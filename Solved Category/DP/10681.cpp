
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

bool con[101][101];
int dp[101][201];
int n,m;
vector<int> adj[101];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,a,b,j;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		memset(con,false, sizeof(con));
		for(i = 0;i<m;i++)
		{
			cin >> a >> b;
			con[a][b] = true;
			con[b][a] = true;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int s,e,d;
		cin >> s >> e >> d;
		memset(dp,false,sizeof(dp));
		dp[s][0] = true;
		for(i = 1;i<=d;i++)
		{
			for(a = 1;a<=n;a++)
			{
				int sz = adj[a].size();
				for(b = 0;b<sz;b++)
				{
					if(a != adj[a][b] && dp[a][i-1])
						dp[adj[a][b]][i] = true;
				}
			}
		}

		if(dp[e][d] == true)
			cout << "Yes, Teobaldo can travel.\n";
		else
			cout << "No, Teobaldo can not travel.\n";
		for(i = 1;i<=n;i++)
			adj[i].clear();

	}
     return 0;
}
