
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

int n;
vector<int> adj[1005];
set<int> check;
set<int>::iterator it1;
int color[1005];
typedef pair<int,int> pa;
map<int,pa> mp;
set<pa> st;
set<pa>::iterator it;
pa p2;
int cnt;
bool conn[1001][1001];
int parent[1001];


void dfs(int i,int prev)
{
     int j,k,a,b,c;
     bool ch;
     color[i] = 1;
     a = adj[i].size();
     for(j = 0;j < a;j++)
     {
           k = adj[i][j];
           if(color[k] == 1 && k != prev)
		   {
				c = i;
				while(c != k)
				{
					b = parent[c];
					conn[b][c] = conn[c][b] = false;
					cnt--;
					c = b;
				}
				cnt--;
				conn[i][k] = conn[k][i] = false;

		   }
		   else if(color[k] == 0)
		   {
			    parent[k] = i;
				dfs(k,i);
		   }
     }

	 color[i] = 2;
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k,a,b;

    int ind;
    pa p1;
    char in[100],in1[100];
    char c1,c2,c3,c4;

    while(cin >> n)
    {
              ind = 1;
              if(n == 0)
              {
                  cout << 0 << " critical links\n\n";
                  continue;
              }

			  memset(conn,false,sizeof(conn));
              for(i = 0; i < n;i++)
              {
					scanf("%d (%d)",&a,&cnt);
                    
                    for(j = 0; j < cnt;j++)
                    {
                          cin >> k;
                          //adj[a].push_back(k);
                          conn[a][k] = conn[k][a] = true;
                    }
              }
              
              if(n == 1)
              {
                  cout << 0 << " critical links\n\n";
                  continue;
              }
              
              cnt = 0;
			  for(i = 0;i<n;i++)
			  {
				  for(j = 0;j<n;j++)
				  {
					  if(j != i && conn[i][j] == true)
					  {
						  adj[i].push_back(j);
					  }
				  }
			  }
			  for(i = 0;i<n;i++)
			  {
				  cnt  += adj[i].size();
			  }
			  
			  cnt /= 2; //no. of edges

			  memset(color,0,sizeof(color));
			  for(i = 0;i<n;i++)
			  {
				  if(color[i] == 0)
				  {
					  dfs(i,i);
				  }
			  }

			  
			  cnt = 0;
			  for(i = 0;i<n;i++)
			  {
				  a = adj[i].size();
				  for(j = 0;j<a;j++)
				  {
					  if(conn[i][adj[i][j]] == true)
					  {
						  //cout << i << " - " << adj[i][j]<<endl;
						  p2.first = i;
						  p2.second = adj[i][j];
						  mp[++cnt] = p2;
						  conn[i][adj[i][j]] = conn[adj[i][j]][i] = false;
					  }
				  }

				  adj[i].clear();

			  }
			  cout << cnt << " critical links\n";
			  for(i = 1;i<=cnt;i++)
			  {
				  cout << mp[i].first << " - " << mp[i].second << endl;
			  }

			  cout << endl;
			  mp.clear();

			  

	}


     return 0;
}