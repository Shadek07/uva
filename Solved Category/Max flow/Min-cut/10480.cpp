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
#include<queue>

using namespace std;

#define min1(a,b) a<b?a:b

int n,s,d;
bool visited[101];

typedef pair<int,int> pa;
map<pa,int> mp;
map<pa,int> ans2;
map<int,pa> ans1;

map<int,int> check;

queue<int> pq;
set<int> st[101];
set<int>::iterator it;

int capa[101][101];

int from[101];
int cnt;
int ver;
bool edge[51][51];
vector<int> source,sink;  // all vertices that can be reached from respectively source and sink
                         //using positive capacity will be stored in source and sink vector

void dfs(int i)
{
     visited[i] = true;
     source.push_back(i);
     int next;
     set<int>::iterator it1;
     for(it1 = st[i].begin(); it1 != st[i].end(); it1++)
     {
           next = *it1;
           if(visited[next] == false && capa[i][next] > 0)
           {
               dfs(next);             
           } 
     }
}

void dfs_second(int i)
{
     visited[i] = true;
     sink.push_back(i);
     int next;
     set<int>::iterator it2;
     for(it2 = st[i].begin(); it2 != st[i].end(); it2++)
     {
           next = *it2;
           if(visited[next] == false && capa[i][next] > 0)
           {
               dfs_second(next);             
           } 
     }
}
int bfs()
{
     
     int where,next,path_cap,prev;
     pq.push(s);
     visited[s] = true;
     memset(from,-1,sizeof(from));
     
     pa p3,p4;
     
     while(!pq.empty())
     {
          where = pq.front();
          pq.pop();
          for(it = st[where].begin(); it != st[where].end(); it++)
          {
                 next = *it;
                 if(visited[next] == false && capa[where][next] > 0)
                 {
                       pq.push(next);
                       visited[next] = true;
                       from[next] = where;
                       if(next == d)
                       {
                               while(!pq.empty())
                               pq.pop();
                               goto nt;
                       }          
                 }
                 
          }
                     
     }
     
     nt:
               where = d;
               path_cap = 99999999;
               while(from[where] > -1)
               {
                   prev = from[where];
                   path_cap = min1(path_cap, capa[prev][where]);
                   where = prev;             
               }
               
               if(path_cap != 99999999)
               {
                   where = d;
                   while(from[where] > -1)
                   {
                         prev = from[where];
                         capa[prev][where] -= path_cap;
                         
                         capa[where][prev] += path_cap;
                         
                         where = prev;
                   }
                   return path_cap;
               }
               else
               return 0;
                     
}

long long int max_flow()
{
    long long int result = 0;
    int path_capacity;
    
    while(true)
    {
               memset(visited,false,sizeof(visited));
               path_capacity = bfs();
               if(path_capacity == 0)
               break;
               else
               result += path_capacity;
               
    }
    
    
    return result;
}
int main(void)
{
    int i,j,k,c,band,a,b;
    int ind;
    pa p1,p2;
    int net = 1;
    while(cin >> n >> c && n && c)
    {
        s = 1;
        d = 2;
        ind = 1;
        ver = 1;
        memset(edge,false,sizeof(edge));
        for(i = 0; i < c;i++)
        {
             cin  >> a >> b >> band;
             edge[a][b] = true;
             edge[b][a] = true;
             p1 = pa(a,b);
             if(mp[p1])
             {
                       capa[a][b] += band;
                       capa[b][a] += band;
             }
             else
             {
                 capa[a][b] = band;
                 capa[b][a] = band;
                 mp[p1] = ind++;
                 p1 = pa(b,a);
                 mp[p1] = ind++;
                 st[a].insert(b);
                 st[b].insert(a);
             }
             
        }
        
        
        memset(visited,false,sizeof(visited));
        cnt = 1;
        long long int ans =  max_flow(); 
        mp.clear();
        memset(visited,false,sizeof(visited));
        dfs(1);
        dfs_second(2);

        i = source.size();
        j = sink.size();
        //cout << i << " " << j << endl;
        cnt = 1;
        for(a = 0; a < i;a++)
        {
              for(b = 0; b < j;b++)
              {
                   if(edge[source[a]][sink[b]] && capa[source[a]][sink[b]] == 0)
                   {
                                 p1 = pa(source[a],sink[b]);
                                 p2 = pa(sink[b], source[a]);
                                 if(!ans2[p1] && !ans2[p2])
                                 {         
                                           //cout << source[a] << " " << sink[b] << endl;
                                           ans2[p1] = cnt;
                                           ans1[cnt] = p1;
                                           cnt++;
                                 }
                   }
              }
        }
        
        for(i = 1; i < cnt;i++)
        {
              cout << ans1[i].first << " " << ans1[i].second << endl;
        }
        
        cout << endl;
        source.clear();
        sink.clear();
        ans1.clear();
        ans2.clear();
        for(i = 1; i <= n;i++)
        {
              if(!st[i].empty())
              st[i].clear();
        }  
        
        
    }
    return 0;
}
