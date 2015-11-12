#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
map<string,int> mp;

int n,m;

struct road
{
	int a,b;
	int cost;
};


bool operator <(road p,road q)
{
	return p.cost > q.cost;
}

int rank[401];
int p[401];


void makeset(int x)
{
     p[x]=x;
     rank[x]=0;     
}

int findset(int px)
{
     if(px!=p[px])
     return px=findset(p[px]);
     else
     return px;
}

void mergset(int px,int py)
{
     int x=findset(px);
     int y=findset(py);
     
     if(rank[x]>rank[y])
     p[y]=x;
     
     else
     p[x]=y;
     
     if(rank[x]==rank[y])
     rank[y]=rank[y]+1;
}

int main(void)
{
	int i,j,k,a,b,ind,cost;
	char in[20],in1[20];
	priority_queue<road> pq;
	struct road r,r1;
	long  int total;
	while(cin >> n >> m)
	{
		if(!n && !m)
			break;
		ind = 1;
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(in);
			mp[in] = ind++;
		}

		for(i = 0; i < m;i++)
		{
			cin >> in >> in1 >> cost;
			a = mp[in];
			b = mp[in1];
			r.a = a;
			r.b = b;
			r.cost = cost;
			pq.push(r);
		}

		cin >> in1;

		for(i = 1;i<=n;i++)
			makeset(i);
		total = 0;
		int edge = 0;
		i = 0;
		while(!pq.empty() || i < m)
		{
			if(edge == n-1)
				break;
			r1 = pq.top();
			pq.pop();
			a = r1.a;
			b = r1.b;
			i++;
			if(findset(a) != findset(b))
			{
				mergset(a,b);
				total += r1.cost;
				edge++;
			}
		}

		if(edge != n-1)
		{
			cout << "Impossible\n";
		}
		else
			cout << total << endl;
		
		while(!pq.empty())
			pq.pop();
		mp.clear();
	}

}