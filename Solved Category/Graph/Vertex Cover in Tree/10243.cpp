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

vector<int> adj[1001];
int t;
bool visit[1001];
int parent[1001];
int order[1001]; //preorder of DFS tree
bool cover[1001];
int n;
void dfs(int i)
{
	order[t++] = i;
	visit[i] = true;
	int len,k;
	len = adj[i].size();
	for(k = 0; k<len;k++)
	{
		if(!visit[adj[i][k]])
		{
			dfs(adj[i][k]);
			parent[adj[i][k]] = i;

		}
	}

}

int cnt;

void minimum_vertex_cover()
{
	memset(visit,false,sizeof(visit));
	memset(parent,-1,sizeof(parent));
	t = 0;
	int i,j,k;
	for(i = 1; i<= n;i++)
	{
		if(visit[i] == false)
		dfs(i);
	}

	memset(cover,false,sizeof(cover));
	cnt = 0;

	for(k = n-1;k>= 0;k--)
	{
		i = order[k];
		j = parent[i];
		if(!cover[i] && j != -1 && !cover[j])
		{
			cover[j] = true;
			cnt++;
		}

	}

}

int main(void)
{
	int i,j,k,m,a,b;
	//int edge;
	while(cin >> n && n)
	{
		//edge = 0;
		for(i = 0; i< n;i++)
		{
			cin >> a;
			//edge += a;
			for(j = 0; j< a;j++)
			{
				cin >> b;
				//if(b != i+1)
				adj[i+1].push_back(b);
			}
		}
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		minimum_vertex_cover();
		cout << cnt << endl;
nt:
		for(i = 1;i<=n;i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
		}
	}
	
	return 0;
}
