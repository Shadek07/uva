#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int rank[20000];
int p[20000];


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
	double cost;

}ln[300000];

int comp(const line &a, const line &b)
{
	if( a.cost <= b.cost)
		return 1;
	else
		return 0;
}

int n,m;
double cor[10000][2];
int main(void)
{

	int i,j,k,a,b,total;
	double d;
	while(cin >> n)
	{
		for(i = 0; i < n;i++)
			cin >> cor[i][0] >> cor[i][1];

		for(i = 1;i<=n;i++)
			makeset(i);
		cin >> m;
		total = 0;

		for(i = 0; i < m;i++)
		{
			cin  >> a >> b;
			if(findset(a) != findset(b))
			{
				mergset(a,b);
				total++;
			}
		}

		int ind=0;

		for(i = 1;i <= n;i++)
		{
			for(j = i+1;j <= n;j++)
			{
				
				d = sqrt((cor[i-1][0]-cor[j-1][0])*(cor[i-1][0]-cor[j-1][0]) + (cor[i-1][1]-cor[j-1][1])*(cor[i-1][1]-cor[j-1][1]));
				ln[ind].a=i;
				ln[ind].b=j;
				ln[ind].cost=d;
				ind++;
				
			}
		}

		sort(ln,ln+ind,comp);

		double cst = 0.0;
		int nd=0;

		while(1)
		{
			if(findset(ln[nd].a) != findset(ln[nd].b))
			{
				mergset(ln[nd].a,ln[nd].b);
				cst += ln[nd].cost;
				total++;

			}

			
			if(total == n-1)
			{
				break;
			}
			nd++;
		}

		printf("%.2lf\n",cst);

		//cout << cst << endl;

	}

}