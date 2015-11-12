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


struct vertex
{
	int v;
	int rank;
};

int cnt;
bool visit[50];
vector<vertex> adj[50];
map<int,int> mp;
int corner;
int mx;
int ans[50];



void first_dfs(int a)
{
	visit[a] = true;
	int i;
	int len = adj[a].size();
	for(i = 0; i < len;i++)
	{
		if(visit[adj[a][i].v] == false)
		{
			first_dfs(adj[a][i].v);
		}			 
	}
}

void dfs(int a,int ind)
{
	int i,j,k;
	if(a == corner)
	{
		cout << 1 ;
		for(j = 1; j <=ind;j++)
		{
            cout << " " << ans[j];
		}
		cnt++;
		cout << endl;
	}
	else
	{
		int len = adj[a].size();
		for(i = 0; i < len;i++)
		{
            
			if(visit[adj[a][i].v])
			{
				 bool ch = true;
				 for(k = 0; k <= ind;k++)
				 {
					 if(ans[k] == adj[a][i].v)
					 {
						 ch = false;
						 break;
					 }
				 }
				 if(ch == true)
				 {
					 ans[ind+1] = adj[a][i].v;
					 dfs(adj[a][i].v,ind+1);
				 }
			}
		}
	}

}

bool comp(vertex a,vertex b)
{
	if(a.v < b.v)
		return true;
	else
		return false;
}
int main(void)
{
	int i,j,a,b;
	int ca = 1;
    struct vertex v1;
	int ind;
    while(cin >> corner)
	{
		mx = 0;
		j = 0;
		ind = 1;
       while(1)
	   {
		   cin >> a >> b;
		   if(!a && !b)
			   break;
		   if(a > mx)
			   mx = a;
		   if(b > mx)
			   mx = b;
		   v1.v = b;
		   if(mp[b])
			   v1.rank = mp[b];
		   else
		   {
			   v1.rank = ind;
			   mp[b] = ind;
		   }
		   adj[a].push_back(v1);
		   v1.v = a;
		   if(mp[a])
			   v1.rank = mp[a];
		   else
		   {
			   v1.rank = ind;
			   mp[a] = ind;
		   }
		   adj[b].push_back(v1);
		   ind++;

	   }

	   for(i = 0;i<= mx;i++)
	   {
		   sort(adj[i].begin(),adj[i].end(),comp);
	   }
       
	   memset(visit,false,sizeof(visit));
	   first_dfs(corner);
	   cout << "CASE " << ca++ <<":\n";
	   cnt = 0;
	   ans[0] = 1;
	   dfs(1,0);
	   cout << "There are " << cnt<< " routes from the firestation to streetcorner " << corner << ".\n";
       for(i = 0; i <= mx;i++)
		   adj[i].clear();
	   mp.clear();
	}

	return 0;
}