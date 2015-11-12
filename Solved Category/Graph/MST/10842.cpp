#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int rank[20000];
int p[20000];
int mp[101][101];
struct road
{
	int a;
	int b;
	int capa;
}rd[10005];

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
int n,m;
int comp(road a,road  b)
{
	if(a.capa <= b.capa)
		return 0;
	else
		return 1;
}
int main(void)
{

	int i,i1,j,a,b;
	
	int cost;
	int t,ca = 1;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;

		for(i = 0;i<n;i++)
			makeset(i);
		
		
		memset(mp,-1,sizeof(mp));

		for(i = 0; i < m;i++)
		{
			cin  >> a >> b >> cost;
			rd[i].a = a;
			rd[i].b = b;
			rd[i].capa = cost;
			if(mp[a][b] < cost)
			{
				mp[a][b] = cost;
			}
			
		}

		sort(rd,rd+m,comp);

		int mn = 100000;
		int d1 = 0;

		for(i1 = 0; i1 < m,d1 < n-1;i1++)
		{
		        i = rd[i1].a;
				j = rd[i1].b;
				cost = rd[i1].capa;
				if((findset(i) != findset(j)))
				{
					mergset(i,j);
					if(cost < mn)
						mn = cost;
					d1++;
					
				}
		}
		

		cout << "Case #" << ca++ << ": " << mn << endl;


		

	}

	return 0;

}