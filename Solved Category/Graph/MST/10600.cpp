#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
int rank[3005];
int p[3005];
bool visit[3005];

vector<int> adj[3005];
typedef pair<int,int> pa;
vector<int> mst; //edges of MST by index
void dfs(int i)
{
	int len,j;
	len = adj[i].size();
	visit[i] = true;
	for(j = 0;j<len;j++)
	{
		if(visit[adj[i][j]]==false)
		{
			dfs(adj[i][j]);
		}

	}

}
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
	int ind;
	unsigned long int cost;

}ln[3005];

int comp(const line &a, const line &b)
{
	if( a.cost <= b.cost)
		return 1;
	else
		return 0;
}

int main(void)
{
	int t;
	int ca=  1;
	int i,j,k;
	cin >> t;
	int n,m;
	int a,b,c,len;
	int cnt;
	pa p1;
	while(t--)
	{
		cin >> n >> m;
		for(i = 0;i<m;i++)
		{
			cin >> a >> b >> c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			ln[i].a = a;
			ln[i].b = b;
			ln[i].ind = i;
			ln[i].cost = c;
		}
		
		
		
		
			sort(ln,ln+m,comp);
			for(i = 1;i<=n;i++)
				makeset(i);
			int nd=0;
			int total = 0;
			unsigned long sum = 0,sum1;
			while(1)
			{
				if(findset(ln[nd].a) != findset(ln[nd].b))
				{
					mergset(ln[nd].a,ln[nd].b);	
					sum += ln[nd].cost;
					mst.push_back(ln[nd].ind);
					total++;
				}				
				if(total == n-1)
				{
					break;
				}
				nd++;
			}

			unsigned long int mn = 9999999,temp; 
			len = mst.size();
			for(i = 0;i<len;i++)
			{
				temp = 0;
				a = mst[i];				
				nd=0;
				total = 0;
				for(j = 1;j<=n;j++)
				makeset(j);
				while(1)
				{
					if((ln[nd].ind != a) && findset(ln[nd].a) != findset(ln[nd].b))
					{
						mergset(ln[nd].a,ln[nd].b);	
						temp += ln[nd].cost;
						total++;
					}				
					if(total == n-1)
					{
						break;
					}
					nd++;
					if(nd == m)
						break;
				}
				if(total == n-1)
				{
					if(temp < mn)
						mn = temp;
				}

			}
			
			cout << sum << " " << mn << endl;
			
		

		mst.clear();
		for(i = 1;i<=n;i++)
		{
			if(!adj[i].empty())
			adj[i].clear();
		}

	}
	return 0;
}