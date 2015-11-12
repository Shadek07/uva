
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
#define max(a,b) ((a>a?a:b))
#define min(a,b) ((a>b?b:a))

int flag;
int n,m;
vector<int> adj[201];
int visited[205];
int fir,sec;
void bipartite_check(int i,int c)
{
	int j,k,len;
	visited[i] = c;
	len = adj[i].size();
	for(j = 0;j<len;j++)
	{
		if(!visited[adj[i][j]])
			bipartite_check(adj[i][j],-c);
		else if(visited[adj[i][j]] == c)
		{
			flag = 0;
			return;
		}
	}
}

void dfs(int i,int c)
{
	int j,k,len;
	visited[i] = c;
	if(c == 1)
		fir++;
	else
		sec++;
	len = adj[i].size();
	for(j = 0;j<len;j++)
	{
		if(!visited[adj[i][j]])
			dfs(adj[i][j],-c);
		
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,k,a,b;
	cin >> t;
	while(t--)
	{
		
		scanf("%d %d",&n,&m);

		for(i = 0;i<m;i++)
		{
			
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		memset(visited,0,sizeof(visited));
		flag = 1;
		for(i = 0;i <n;i++)
		{
			if(!visited[i])
				bipartite_check(i,1);
		}
		if(!flag)
		{
			cout << -1 << endl;
		}
		else
		{
			int ans = 0;
			memset(visited,0,sizeof(visited));
			for(i = 0;i <n;i++)
			{
				if(!visited[i])
				{
					fir = sec = 0;
					dfs(i,1);
					if(fir != 0 && sec != 0)
					ans += min(fir,sec);
					else if(fir == 0)
						ans += sec;
					else if(sec == 0)
						ans += fir;
				}
			}

			cout << ans << endl;

		}


		for(i = 0;i<n;i++)
			adj[i].clear();
	}
     return 0;
}