#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int ca,cb,n;
int visited[1005][1005];
#define INF 9999999
char output[][10] = {"a","pour A B","pour B A","empty B","fill B","empty A","fill A"};

struct state
{
	int first;
	int second;
};

queue<state> q;
vector<int> v;
int parent[1005][1005][2];
int opt[1005][1005];
int dist[1005][1005];

int operate(int x1,int y1,int x2,int y2)
{
	if(x1 > x2 && y1 < y2)
		return 1;  //pour A B
	else if(y1 > y2 && x2 > x1)
		return 2;  //pour B A
	else if(x1 == x2 && y1 > y2)
		return 3;  //empty B
	else if(x1 == x2 && y1 < y2)
		return 4;  //fill B
	else if(y1 == y2 && x1 > x2)
		return 5;  //empty A
	else if(y1 == y2 && x1 < x2)
		return 6;  //fill A
	return 0;
}


int g1,g2;

void iterative()
{
	int i,a,b;
	a = g1;
	b = g2;
	while(!(parent[a][b][0] == 0 && parent[a][b][1] == 0))
	{
					//cout << a << " " << b << endl;
		//i = operate(parent[a][b][0],parent[a][b][1],a,b);
		i = opt[a][b];
		v.push_back(i);
					//find_operation(parent[a][b][0],parent[a][b][1]);
		int x1,x2;
		x1 = a;
		x2 = b;
		a = parent[x1][x2][0];
		b = parent[x1][x2][1];
	}

	if(a == 0 && b == cb)
		cout << "fill B\n";
	else if(a == ca && b == 0)
		cout << "fill A\n";
	
	for(i = v.size()-1;i >=0; i--)
	{
			cout << output[v[i]] << endl;
	}

	cout << "success\n";
	v.clear();

}

void solve()
{
		
		struct state st,next;
		//int x1,y1,x2,y2; //x is for A, y is for B, 2 is formed by modification on state 1
		int a,b,x;
		int diff;

		
		memset(dist,INF,sizeof(dist));
		//cout << dist[3][5] << endl;

		st.first = ca;
		st.second = 0;
		parent[ca][0][0] = 0;
		parent[ca][0][1] = 0;
		dist[ca][0] = 0;
		opt[ca][0] = 6;
		q.push(st);

		st.first = 0;
		st.second = cb;
		parent[0][cb][0] = 0;
		parent[0][cb][1] = 0;
		dist[0][cb] = 0;
		opt[0][cb] = 4;
		q.push(st);

		while(!q.empty())
		{
			st = q.front();
			a = st.first;
			b = st.second;
			x = dist[a][b];
			q.pop();

			if(b == n || a == n)
			{
				g1 = a;
				g2 = b;
				//find_operation(a,b);
				//iterative();
				while(!q.empty())
					q.pop();
				break;

			}

			//empty A
			if(a > 0 && b != 0)
			{
				next.first = 0;
				next.second = b;
				
				
				if(dist[0][b] > x+1)
				{
					q.push(next);
					dist[0][b] = x+1;
					parent[0][b][0] = a;
					parent[0][b][1] = b;
					opt[0][b] = 5;
				}

			}

			//fill A
			if(a < ca)
			{
				next.first = ca;
				next.second = b;
				if(dist[ca][b] > x+1)
				{
					q.push(next);
					dist[ca][b] = x+1;
					parent[ca][b][0] = a;
					parent[ca][b][1] = b;
					opt[ca][b] = 6;				
				}

			}

			//empty B
			if(b > 0 && a!= 0)
			{
				next.first = a;
				next.second = 0;
				if(dist[a][0] > x+1)
				{
				q.push(next);
				dist[a][0] = x+1;
				parent[a][0][0] = a;
				parent[a][0][1] = b;
				opt[a][0] = 3;
				}

			}

			//fill B
			if(b < cb)
			{
				next.first = a;
				next.second = cb;
				if(dist[a][cb] > x+1)
				{
				q.push(next);
				dist[a][cb] = x+1;
				parent[a][cb][0] = a;
				parent[a][cb][1] = b;
				opt[a][cb] = 4;
				}

			}

			//pour A to B
			if(a > 0 && b < cb)
			{
				diff = cb - b;
				if(diff > a)
				{
					next.first = 0;
					next.second = b + a;
					if(dist[0][b+a] > x+1)
					{
					q.push(next);
					dist[0][b+a] = x+1;
					parent[0][b+a][0] = a;
					parent[0][b+a][1] = b;
					opt[0][b+a] = 1;
					}
				}
				else
				{
					next.first = a - diff;
					next.second = cb;
					if(dist[a-diff][cb]>x+1)
					{
					q.push(next);
					dist[a-diff][cb]=x+1;
					parent[a-diff][cb][0] = a;
					parent[a-diff][cb][1] = b;
					opt[a-diff][cb] = 1;
					}
				}

			}

			//pour B to A
			if(b > 0 && a < ca)
			{
				diff = ca - a;
				if(diff > b)
				{
					next.first = a+b;
					next.second = 0;
					if(dist[a+b][0] > x+1)
					{
					q.push(next);
					dist[a+b][0] = x+1;
					parent[a+b][0][0] = a;
					parent[a+b][0][1] = b;
					opt[a+b][0] = 2;
					}
				}
				else
				{
					next.first = ca;
					next.second = b-diff;
					if(dist[ca][b-diff] > x+1)
					{
					q.push(next);
					parent[ca][b-diff][0] = a;
					parent[ca][b-diff][1] = b;
					dist[ca][b-diff] = x+1;
					opt[ca][b-diff] = 2;
					}
				}

			}

		}
}

int main(void)
{
	
	while(cin >> ca >> cb >> n)
	{
			solve();
			//find_operation(g1,g2);
			iterative();
	}

	return 0;
}