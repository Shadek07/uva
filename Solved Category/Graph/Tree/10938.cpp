
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
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n;
vector<int> adj[5001];
int src,dest;
int pa[5001];
int step;
bool found;
bool vis[5001];

void dfs(int cnt,int a)
{
	int sz,i;
	sz = adj[a].size();
	vis[a] = true;
	if(found)
		return;
	if(a==dest)
	{
		step = cnt;
		pa[cnt] = a;
		found = true;
		return;
	}
	pa[cnt] = a;
	for(i=0;i<sz;i++)
	{
		if(!found && vis[adj[a][i]]==false)
		{
			dfs(cnt+1,adj[a][i]);
		}
	}

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int q,a,b;
	while(cin >> n && n)
	{
		for(i=1;i<n;i++)
		{
			cin >> j >> k;
			adj[j].push_back(k);
			adj[k].push_back(j);
		}

		cin >> q;
		while(q--)
		{
			cin >> src >> dest;
			memset(vis,false,sizeof vis);
			found=false;
			dfs(0,src);
			if(step%2==0)
			{
				cout << "The fleas meet at " << pa[step/2] << ".\n";
			}
			else
			{
				a = pa[step/2];
				b = pa[step/2+1];
				if(a>b)
				{
					i = a;
					a = b;
					b = i;
				}
				cout << "The fleas jump forever between " << a << " and " << b <<".\n";
			}
		}
		for(i=1;i<=n;i++)
		{
			adj[i].clear();
		}

	}
     return 0;
}