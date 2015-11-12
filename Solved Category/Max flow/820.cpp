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

queue<int> pq;
set<int> st[101];
set<int>::iterator it;

int capa[101][101];

int from[101];

int bfs()
{
     
     int where,next,path_cap,prev;
     pq.push(s);
     visited[s] = true;
     memset(from,-1,sizeof(from));
     
     
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
    while(cin >> n && n != 0)
    {
        cin >>  s >> d >> c;
        ind = 1;
        for(i = 0; i < c;i++)
        {
             cin  >> a >> b >> band;
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
        
        cout << "Network " << net++ << endl;
        memset(visited,false,sizeof(visited));
        long long int ans =  max_flow();
        cout << "The bandwidth is " << ans << ".\n\n"; 
        mp.clear();
        for(i = 1; i <= n;i++)
        {
              if(!st[i].empty())
              st[i].clear();
        }  
    }
    return 0;
}
