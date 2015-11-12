#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cctype>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;

map<string,int> mp;
map<int,string> epr;

vector<int> adj[101];
vector<int> comp;

set<string> ans;
set<string>::iterator it;


int n,m;
char in[40];
char in1[40];
bool visit[101];
bool vis[101];
int vision;
int total;
bool special;

void dfs(int i)
{
	visit[i] = true;
	comp.push_back(i);
	int len = adj[i].size();
	int j;
	for(j = 0; j < len;j++)
	{
		if(visit[adj[i][j]] == false)
		{
			dfs(adj[i][j]);
		}
	}
     
}

int eye;

void second_dfs(int i)
{
	vis[i] = true;
	
	int len = adj[i].size();
	int j;
	for(j = 0; j < len;j++)
	{
		if(adj[i][j] != eye && vis[adj[i][j]] == false)
		{
			second_dfs(adj[i][j]);
		}
	}

}
int main(void)
{
    int i,j,k,a,b,ind;
    int ch = 0;
    int cnt;
    int city = 1;
	int len;
    while(cin >> n && n)
    {
              getchar();
              ind = 1;
              
              for(i = 0; i < n;i++)
              {
                    gets(in);
                    mp[in] = ind++;
                    epr[ind-1] = in;
              }
              
              cin >> m;              
              getchar();
              
              for(i = 0; i < m;i++)
              {
                    cin >> in >> in1;
                    a = mp[in];
                    b = mp[in1];
                    adj[a].push_back(b);
                    adj[b].push_back(a);
              }
              
              total = -1;
              memset(visit,false,sizeof(visit));
              special = true;
              for(i = 1; i <= n;i++)
              {
                    if(visit[i] == false)
                    {
                                total++;
                                dfs(i);
								
								if(comp.size() > 2)
								{
                                    len = comp.size();
									for(j = 0; j < len;j++)
									{
										if(j == 0)
											k = comp[1];
										else
											k = comp[0];
										eye = comp[j];
										memset(vis,false,sizeof(vis));
										second_dfs(k);
										int i1;
										for(i1 = 0; i1 < len;i1++)
										{
											if(comp[i1] != eye && vis[comp[i1]] == false)
											{
												ans.insert(epr[eye]);
												break;
											}
										}
									}
								}

								comp.clear();
                    }
              }

			  if(ch == 0)
				  ch = 1;
			  else
				  cout << endl;
			  cout << "City map #" << city++ << ": " << ans.size() << " camera(s) found\n";
			  for(it = ans.begin(); it != ans.end(); it++)
			  {
					cout << *it << endl;
			  }

              ans.clear();
			  mp.clear();
			  epr.clear();
			  for(i = 1; i <= n;i++)
				  adj[i].clear();
              
             
                 
    }
    
    return 0;
}
