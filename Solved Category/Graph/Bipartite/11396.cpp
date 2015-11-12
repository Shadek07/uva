#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int flag;
int visited[305];
vector<int> v[305];
void dfs(int i,int c)
{
	int j,k;
	visited[i] = c;
	for(j = 0;j < v[i].size();j++)
	{
		if(!visited[v[i][j]])
			dfs(v[i][j],-c);
		else if(visited[v[i][j]] == c)
		{
			flag = 0;
			return;
		}
	}
}
int main(void)
{
	int V;
	int a,b,i;
	while(1)
	{
		cin >> V;
		if(V == 0)
			break;
		while(1)
		{
			cin >> a >> b;
			if(!a && !b)
				break;
			v[a].push_back(b);
			v[b].push_back(a);

		}

		memset(visited,0,sizeof(visited));
		flag = 1;
		for(i = 1;i <= V;i++)
		{
			if(!visited[i])
				dfs(i,1);
		}

		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
		for(i = 1;i <= V;i++)
			if(!v[i].empty())
				v[i].clear();

	}
	return 0;
}