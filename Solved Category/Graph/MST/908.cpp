#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

int rank[1000002];
int p[1000002];


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

class line
{
	int a;
	int b;
	int cost;
public:
	line()
	{

	}
	line(int a1,int b1,int c)
	{
		a = a1;
		b = b1;
		cost = c;
	}
	int ret_a()const
	{
		return a;
	}
	int ret_b()const
	{
		return b;
	}

	int ret_cost() const
	{
		return cost;
	}
};

bool operator<(const line &a, const line &b)
{
  return a.ret_cost() > b.ret_cost();
}
int n;
int m;
int main(void)
{
	int i,j,k,a,b,c,add;
	long int ini;
	priority_queue<line> mypq;
	int ca = 0;

	while(cin >> n)
	{
		ini = 0;
		for(i = 0; i < n-1; i++)
		{
			cin >> a >> b >> c;
			//mypq.push(line(a,b,c));
			ini += c;

		}

		cin >> add;

		for(i = 0; i < add;i++)
		{
			cin >> a >> b >> c;
			mypq.push(line(a,b,c));
		}

		cin >> m;

		for(i = 0; i < m;i++)
		{
			cin >> a >> b >> c;
			mypq.push(line(a,b,c));
		}

		for(i = 1; i <= n;i++)
		{
			makeset(i);
		}

		int total = 0;
		long last = 0;

		while(1)
		{
			line l;
			l = mypq.top();
			if(findset(l.ret_a()) != findset(l.ret_b()))
			{
				mergset(l.ret_a(),l.ret_b());
				last += l.ret_cost();
				total++;

			}

			mypq.pop();
			if(total == n-1)
			{
				while(!mypq.empty())
					mypq.pop();
				break;
			}

		}
		if(ca == 0)
			ca = 1;
		else
			cout << endl;
		getchar();
		getchar();

		cout << ini << endl << last << endl;

		

	}
	
	return 0;
}