
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
#include<list>
#include<sstream>
using namespace std;



bool v[100001];
vector<int> adj[100001];
int cnt,n;

void dfs(int a)
{
	v[a] = true;
	int i,len;
	len = adj[a].size();
	for(i = 0;i<len;i++)
	{
		if(v[adj[a][i]] == false)
		{
			cnt++;
			dfs(adj[a][i]);
		}
	}

}
int main(void)
{
	
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	
	int i,m,a,b,l;
	bool ch = true;
	int ind;
	int t;
	cin >> t;

	while(t--)
	{
		cin >> n >> m >> l;
				
		for(i = 0;i<m;i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
		}

		memset(v,false,sizeof(v));
		cnt = 0;

		for(i = 0;i<l;i++)
		{
			cin >> a;
			if(v[a] == false)
			{
				cnt++;
			}

			dfs(a);
			
		}

		cout << cnt << endl;
		for(i = 1;i<=n;i++)
		{
			adj[i].clear();
		}
	}	
	return 0;
}