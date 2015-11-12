#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int rank[200000];
int p[200000];


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

struct line
{
	int a;
	int b;
	int cost;

}ln[300000];

int comp(const line &a, const line &b)
{
	if( a.cost < b.cost)
		return 1;
	else
		return 0;
}

int n,m;

int main(void)
{

	int i,a,b,total;
	int air,cost;
	int component;
	int t,ca=1;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> air;
		

		for(i = 1;i<=n;i++)
			makeset(i);
		
		total = 0;

		for(i = 0; i < m;i++)
		{
			cin  >> a >> b >> cost;
		    ln[i].a = a;
			ln[i].b = b;
			ln[i].cost = cost;
		}

		sort(ln,ln+m,comp);
		component = n;

		int cst = 0;
		int nd=0;

		for(i = 0; i < m && total < n-1 && ln[i].cost < air;i++)
		{
			if(findset(ln[i].a) != findset(ln[i].b))
			{
				mergset(ln[i].a,ln[i].b);
				cst += ln[i].cost;
				total++;
				component--;

			}

			
			if(total == n-1)
			{
				break;
			}
			
		}

		printf("Case #%d: %d %d\n",ca++,component*air + cst,component);

		//cout << cst << endl;

	}

}