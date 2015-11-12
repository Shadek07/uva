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

int m,n1;
bool visit[21][21];
char in[21][21];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int cnt;
char t;
void dfs_first(int a,int b)
{
	int i,j;

	visit[a][b] = true;
	if(in[a][(b+1)%n1] == t && visit[a][(b+1)%n1] == false)
		dfs_first(a,(b+1)%n1);
	if(a-1>= 0 && in[a-1][b] == t&& visit[a-1][b] == false)
		dfs_first(a-1,b);
	if(a+1<m && in[a+1][b] == t&& visit[a+1][b] == false)
		dfs_first(a+1,b);
	if(b == 0 && in[a][n1-1] == t&& visit[a][n1-1] == false)
			dfs_first(a,n1-1);
	else if(b>0 && in[a][b-1] == t && visit[a][b-1] == false)
		dfs_first(a,b-1);

}

void dfs(int a,int b)
{
	int i,j;

	visit[a][b] = true;

	if(in[a][(b+1)%n1] == t && visit[a][(b+1)%n1] == false)
	{
		cnt++;
		dfs(a,(b+1)%n1);
	}
	if(a-1>= 0 && in[a-1][b] == t&& visit[a-1][b] == false)
	{
		cnt++;
		dfs(a-1,b);
	}
	if(a+1<m && in[a+1][b] == t&& visit[a+1][b] == false)
	{
		cnt++;
		dfs(a+1,b);
	}
	if(b == 0 && in[a][n1-1] == t&& visit[a][n1-1] == false)
	{
		 cnt++;
		 dfs(a,n1-1);
	}
	else if(b>0 && in[a][b-1] == t && visit[a][b-1] == false)
	{
		cnt++;
		dfs(a,b-1);
	}

}
int main(void)
{
	int i,j,k;
	int a,b;
	int x,y;
    //freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin >> m >> n1)
	{
		getchar();
		x = m;
		y = n1;
		for(i = 0;i<m;i++)
		{
			gets(in[i]);
			//cout << in[i]<<endl;
		}


		cin >> a >> b;
		t = in[a][b];
		memset(visit,false,sizeof(visit));
		dfs_first(a,b);
		m = x;
		n1 = y;
		int mx = 0;
		for(i = 0;i<m;i++)
		{
			for(j = 0;j<n1;j++)
			{
				if(in[i][j] == t && visit[i][j] == false)
				{
					cnt = 1;
					m = x;
					n1 = y;
					dfs(i,j);
					if(cnt>mx)
						mx = cnt;
				}
			}
		}
		cout << mx << endl;
	}
	return 0;
}
