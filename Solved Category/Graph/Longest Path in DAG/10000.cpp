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

using namespace std;

#define max(a,b) a>b?a:b

vector<int> adj[101];
int dp[101];
int n,m;
int start,end;

void dfs(int prev,int a)
{
	int i,j;
	int len = adj[a].size();
	for(i = 0; i<len;i++)
	{
		if(adj[a][i] != prev && dp[a] + 1 > dp[adj[a][i]])
		{
			dp[adj[a][i]] = dp[a]+1;
			dfs(a,adj[a][i]);
		}
	}
	
}


int main(void)
{
	int i;
    int a,b;
	int ca = 1;
	while(cin >> n && n)
	{
		i = 0;
		cin >> start;
		while(1)
		{
			cin >> a >> b;
			if(!a && !b)
				break;
			adj[a].push_back(b);
			//adj[b].push_back(a);
			i++;
		}
	
	    
		for(i = 1;i<=n;i++)
			dp[i] = -1;

		dp[start] = 0;

		dfs(start,start);

		
		int mx = -1;
		
		for(i = 1; i <=n;i++)
		{
			if(dp[i]>mx)
			{
				mx = dp[i];
				end = i;
			}
		}
        for(i = 1;i<=n;i++)
        adj[i].clear();
		cout << "Case " << ca++ << ": The longest path from " << start << " has length " << mx << ", finishing at " << end << ".\n\n";

	}

	return 0;

}
