
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

#define eps 1e-8

double circle[101][3];
vector<int> adj[101];
bool vis[101];
int cnt;
bool check(int a,int b)
{
	double dis;
	double rad;
	dis = sqrt((circle[a][0]-circle[b][0])*(circle[a][0]-circle[b][0]) + (circle[a][1]-circle[b][1])*(circle[a][1]-circle[b][1]));
	rad = circle[a][2] + circle[b][2];
	if(dis<rad-eps && circle[b][2]<circle[a][2]+dis-eps && circle[a][2]<circle[b][2]+dis-eps)
		return true;
	else
		return false;

}

void dfs(int a)
{
	int len,i;
	vis[a] = true;
	cnt++;
	len = adj[a].size();

	for(i = 0;i<len;i++)
	{
		if(vis[adj[a][i]] == false)
		{
			dfs(adj[a][i]);
		}
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int n,i,j,k;

	while(cin >> n)
	{
		if(n==-1)
			break;
		for(i = 0;i<n;i++)
		{
			cin >> circle[i][0] >> circle[i][1] >> circle[i][2];

		}

		for(i = 0;i<n-1;i++)
		{
			for(j = i+1;j<n;j++)
			{
				if(check(i,j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}

			}
		}

		memset(vis,false,sizeof(vis));
		int mx =0;
		for(i = 0;i<n;i++)
		{
			if(vis[i] == false)
			{
				cnt =0;
				dfs(i);
				if(cnt>mx)
					mx = cnt;
			}

		}

		if(mx==1)
			cout << "The largest component contains " << mx <<" ring.\n";
		else
		cout << "The largest component contains " << mx <<" rings.\n";

		for(i = 0;i<n;i++)
			adj[i].clear();
	}

     return 0;
}