
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


int flag;
int visited[305];
vector<int> v[201];
int n,m;
int rank[205];
int p[205];

struct knil
{
	int x;
	int y;
	int c1;

}lk[11001];

bool comp(knil fir,knil sec)
{
	if(fir.c1 < sec.c1)
		return 1;
	else
		return 0;
}

void dfs(int i,int c)
{
	int j;
	visited[i] = c;
	int len = v[i].size();
	for(j = 0;j < len;j++)
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


void makeset(int x)
{
     p[x]=x;
     rank[x]=0;    
}

int findset(int px)
{
     /*if(px!=p[px])
     return px=findset(p[px]);
     else
     return px;*/
	int arr[100005];
	int i,j;

	i = 0;

	while(px != p[px])
	{
		arr[i++] = px; 
		px = p[px];
	}

	for(j = 0;j<i;j++)
	{
		p[arr[j]] = px;
	}
	return px;
}

void mergset(int px,int py)
{
     int x=findset(px);
     int y=findset(py);
     
     if(rank[x]>rank[y])
     p[y]=x;
     
     else
     p[x]=y;
     
     if(rank[x]==rank[y])
     rank[y]=rank[y]+1;
}

int main(void)
{
	int a,b,i,c;
	while(cin >> n && n)
	{
		cin >> m;
		i = 0;
		while(i<m)
		{
			cin >> a >> b >> c;
			v[a].push_back(b);
			v[b].push_back(a);
			lk[i].x = a;
			lk[i].y = b;
			lk[i].c1 = c;
			i++;
		}

		memset(visited,0,sizeof(visited));
		flag = 1;
		for(i = 1;i <= n;i++)
		{
			if(!visited[i])
				dfs(i,1);
		}

		if(flag==0)
		{
			cout << "Invalid data, Idiot!\n";
		}
		else
		{
			sort(lk,lk+m,comp);
			for(i = 1;i<=n;i++)
				makeset(i);
			int nd=0;
			int total = 0;
			long int cost = 0;
			while(nd <m)
			{
				int x,y;
				x = findset(lk[nd].x);
				y = findset(lk[nd].y);
				if(x != y)
				{
					mergset(lk[nd].x,lk[nd].y);
					total++;
					cost += lk[nd].c1;
				}
				else if(lk[nd].c1 < 0)
				{
					cost += lk[nd].c1;
				}
				nd++;
			}

			if(total < n-1)
			{
				cout << "Invalid data, Idiot!\n";
			}
			else
			{
				cout << cost << endl;
			}
		}

		for(i = 1;i <= n;i++)
			if(!v[i].empty())
				v[i].clear();

	}
	return 0;
}