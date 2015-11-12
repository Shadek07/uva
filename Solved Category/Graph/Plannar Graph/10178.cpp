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

using namespace std;

char in[100];
map<char,int> mp;
vector<int> adj[55];
typedef pair<int,int> pa;
map<pa,bool> check;
int vertices;
int edges;
bool visit[55];

void dfs(int i)
{
     int j,len;
     visit[i] = true;
     vertices++;
     len = adj[i].size();
     edges += len;
     for(j = 0; j < len;j++)
     {
           if(visit[adj[i][j]] == false)
           {
                               //edges++;
                               dfs(adj[i][j]);
           }
     }
}

int main(void)
{
    int n,m,i;
    int f,f1;
    char *p;
    char c1,c2;
    int ind;
    pa p1,p2;
    int a,b;
    
    while(cin >> n >> m)
    {
         getchar();
         ind = 1;
         f = 0;
         for(i = 0; i < m;i++)
         {
               gets(in);
               p = strtok(in,"          ");
               c1 = p[0];               
               p = strtok(NULL,"          ");
               c2 = p[0];
               if(c1 != c2)
               {
                     if(!mp[c1])
                   mp[c1] = ind++;
                   if(!mp[c2])
                   mp[c2] = ind++;
                   a = mp[c1];
                   b = mp[c2];
                   p1 = pa(a,b);
                   p2 = pa(b,a);
                   if(check.find(p1) != check.end() || check.find(p2) != check.end())
                   {                           
                           f++;         
                   }
                   else
                   {
                       check[p1] = true; 
                       adj[a].push_back(b);
                       adj[b].push_back(a);
                   } 
               }
               else
               f++;
         }
         
         memset(visit,false,sizeof(visit));
         
         for(i = 1; i < ind;i++)
         {
               if(visit[i] == false)
               {
                    vertices = edges = 0;
                    dfs(i);
                    edges /= 2;
                    f1 = 2 - vertices + edges;
                    f += (f1-1);
               }
         }
          
         f += 1;
                
         cout << f << endl; 
         mp.clear();
         check.clear();
         for(i = 1; i < ind;i++)
         if(!adj[i].empty())
         adj[i].clear();    
    }
}
