
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
vector<int> adj[101];
bool reach[101];
bool visit[101];
int n;
bool ans[101][101];
int node;
void reachable(int a)
{
	int i,j,k,len;
	len = adj[a].size();
	reach[a] = true;
	for(i = 0;i<len;i++)
	{
		if(reach[adj[a][i]] == false)
			reachable(adj[a][i]);
	}

}


void dfs(int a)
{
	visit[a] = true;
	int i,j,k,len;
	len = adj[a].size();
	for(i = 0;i<len;i++)
	{
		if(adj[a][i] != node && visit[adj[a][i]] == false)
			dfs(adj[a][i]);
	}

}

void print()
{
	int i;
	cout << "+";
	for(i = 0;i<2*n-1;i++)
		cout << "-";
	cout << "+";
	cout << endl;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,k,a,b;
	cin >> t;
	int ca=1;
	while(t--)
	{
		cin >> n;

		for(i =0;i<n;i++)
		{
			for(j = 0;j<n;j++)
			{
				cin >> a;
				if(a == 1)
					adj[i].push_back(j);
			}
		}

		cout << "Case " << ca++ << ":\n";

		memset(reach,false,sizeof(reach));
		reachable(0);

		for(i = 0;i<n;i++)
		{
			for(j = 0;j<n;j++)
				ans[i][j] = false;
		}

		ans[0][0] = true;
		for(i = 1;i<n;i++)
		{
			if(reach[i])
			{
				ans[0][i] = true;
				ans[i][i] = true;
			}
		}

		for(i = 1;i<n;i++)
		{
			node = i;
			memset(visit,false,sizeof(visit));
			dfs(0);
			for(j = 1;j<n;j++)
			{
				if(j != node && reach[j] == true && visit[j] == false)
				{
					ans[i][j]  = true;
				}
			}

		}

		for(i = 0;i<n;i++)
		{
			print();
			for(j = 0;j<n;j++)
			{
				if(ans[i][j] == true)
				{
					cout << "|Y";
				}
				else
					cout << "|N";
			}
			cout << "|" << endl;
		}
		print();

		for(i = 0;i<n;i++)
			adj[i].clear();



	}

     return 0;
}
