
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


#define white 0
#define gray 1
#define black 2

vector<int> adj[10000],rev[10000];
int n,m;

int vis[10000];
int  order[10001],top_place; 
bool forward;
bool one_comp;
bool v[10001];
void dfs(int a)
{
	if(vis[a] == black)
		return;
	vis[a] = gray;
	int i,len = adj[a].size(),b;
	for(i = 0;i<len;i++)
	{
		b = adj[a][i];
		if(vis[b] == white) //tree edge
		{
			dfs(b);
		}
		else if(vis[b] == black) //gray to black, it is forward or cross edge
		{
			forward = true;
		}

	}

	vis[a] = black;
	top_place--; 
	order[top_place] = a;
}

void top()
{
	memset(vis,white,sizeof(vis));
	int i;
	top_place = n;
	for(i =0;i<n;i++)
	{
		if(vis[i] == white)
		{
			dfs(i);
		}
	}

}

void dfs_rev(int a)
{
	if(v[a])
		return;
	int i,len;
	v[a] = true;
	len = rev[a].size();
	for(i = 0;i<len;i++)
	{
		if(v[rev[a][i]]==false)
			dfs_rev(rev[a][i]);
	}
}
void scc()
{
	top();
	if(forward)
		return;
	memset(v,false,sizeof(v));
	int i,j;
	int cnt=0;
	for(i = 0;i<n;i++)
	{
		j = order[i]; //j is a vertex, i is finishing time for vertex j
		if(!v[j])
		{
			cnt++;
			if(cnt>1)
				break;
			dfs_rev(j);

		}
	}
	if(cnt>1)
		one_comp = false;


}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t;
	cin >> t;
	int i,j,a,b;
	while(t--)
	{
		cin >> n >> m;
		for(i = 0;i<m;i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			rev[b].push_back(a);
		}
		forward = false;
		one_comp = true;
		scc();
		if(one_comp && !forward)
			cout << "YES\n";
		else
			cout << "NO\n";
		for(i = 0;i<n;i++)
		{
			adj[i].clear();
			rev[i].clear();
		}



	}
     return 0;
}