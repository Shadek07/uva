
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
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
int n;
#define eps 1e-7
double cor[1001][2],d;
vector<int> adj[1001];
bool vis[1001];

bool dist(int i,int j)
{
	double d1 = (cor[i][0] - cor[j][0])*(cor[i][0] - cor[j][0]) + (cor[i][1] - cor[j][1])*(cor[i][1] - cor[j][1]);
	if(d1 < d*d-eps)
		return true;
	else
		return false;
}

void dfs(int a)
{
	int i,len;

	vis[a] = true;
	len = adj[a].size();
	for(i = 0;i<len;i++)
	{
		if(vis[adj[a][i]] == false)
			dfs(adj[a][i]);
	}
}
int main(void)
{
	int i,j,k;
	int t;
	cin >> t;
	int ca=1;
	while(t--)
	{
		cin >> n>> d;
		for(i = 0;i<n;i++)
		{
			cin >> cor[i][0] >> cor[i][1];
		}

		for(i = 0;i<n;i++)
		{
			for(j = i+1;j<n;j++)
			{
				if(dist(i,j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		memset(vis,false,sizeof(vis));
		int cnt = 0;
		for(i = 0;i<n;i++)
		{
			if(vis[i] == false)
			{
				cnt++;
				dfs(i);
			}
		}

		cout << "Case " << ca++ << ": " << cnt << endl;
		for(i = 0;i<n;i++)
			adj[i].clear();


	}
	return 0;
}