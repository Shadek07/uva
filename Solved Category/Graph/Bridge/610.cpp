
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
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))
#define DFS_WHITE 0
#define DFS_GRAY 1
#define DFS_BLACK 2

int dfsRoot; 
int rootChildren = 0;
int V,m;
int dfs_num[1001];
int dfs_low[1001];
int dfs_parent[1001];
vector<int> AdjList[1001];
typedef  pair<int,int>  ii; // we  will frequently   use these  two data  type shortcuts 
typedef  vector<ii>  vii; 
#define  TRvii(c,  it)   for  (vii::iterator  it  = (c).begin();   it != (c).end();  it++) 
// all sample  codes  involving  TRvii  use this  macro

#define REP(i, a, b)   for (int i = int(a); i <= int(b); i++)
int dfsNumberCounter;
bool out[1001][1001];
void articulationPointAndBridge(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	int sz = AdjList[u].size();
	int i,v;
	for(i = 0;i<sz;i++)
	{
		v = AdjList[u][i];
		if (dfs_num[v] == DFS_WHITE) // a tree edge
		{ 
			dfs_parent[v] = u; // parent of this children is me
			if (u == dfsRoot) // special case
			rootChildren++; // count children of root
			articulationPointAndBridge(v) ;
			//if (dfs_low[v] >= dfs_num[u]) // for articulation point
			//articulation_vertex[u] = true; // store this information first
			if (dfs_low[v] > dfs_num[u]) // for bridge
			{
				printf("%d %d\n", u, v);
				printf("%d %d\n", v,u);
				out[u][v] = true;
				out[v][u] = true;
			}
			else
			{
				printf("%d %d\n",u, v);
				out[u][v] = out[v][u] = true;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
		}
		else if (v != dfs_parent[u]) // a back edge and not direct cycle
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
			if(!out[u][v])
			{
				printf("%d %d\n",u, v);
				out[u][v] = out[v][u] = true;
			}
		}
	}
}

int cmp(ii a,ii b)
{
	if(a.first< b.first)
		return 1;
	else if(a.first == b.first && a.second < b.second)
		return 1;
	return 0;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("4.txt", "w", stdout);
		// inside int main()
	int ca=1;
	int a,b,i;
	
	while(cin >> V >> m)
	{
		if(V == 0 && m == 0)
			break;
		dfsNumberCounter = 1;
		memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
		//printf("Bridges:\n");
		cout << ca++ << endl << endl;
		for (i= 0; i<=m-1;i++)
		{
			cin >> a >> b;
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		//cout << AdjList[1].size();
		memset(out,false,sizeof(out));
		for (i= 0; i<=V - 1;i++)
		if(dfs_num[i] == DFS_WHITE) 
		{
			dfsRoot = i; 
			rootChildren = 0;
			articulationPointAndBridge(i) ;
			//articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
		}
		int j;
		for(i = 1;i<=V;i++)
		{
			AdjList[i].clear();
		}
		cout << "#\n";
	}
     
}
