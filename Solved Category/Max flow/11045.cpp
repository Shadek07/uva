
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

#define min1(a,b) a<b?a:b
int n,s,d,m;
bool visited[101];
typedef pair<int,int> pa;
map<pa,int> mp;
map<string,int> shirt;

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
	int t;
	char fir[5],sec[5];
	//XXL, XL, L, M , S, and XS
	shirt["XXL"] = 1;
	shirt["XL"] = 2;
	shirt["L"] = 3;
	shirt["M"] = 4;
	shirt["S"] = 5;
	shirt["XS"] = 6;
	cin >> t;
	getchar();
    while(cin >> n >> m)
    {
        
        ind = 1;
		getchar();
        for(i = 1; i <= m;i++)
        {
             cin  >> fir >> sec;            
             capa[i][m+shirt[fir]] = 1;
             capa[m+shirt[fir]][i] = 1;
             st[i].insert(m+shirt[fir]);
             st[m+shirt[fir]].insert(i);   
			 
			 capa[i][m+shirt[sec]] = 1;
             capa[m+shirt[sec]][i] = 1;
             st[i].insert(m+shirt[sec]);
             st[m+shirt[sec]].insert(i);
			 
			 capa[0][i] = 1;
			 capa[i][0] = 1;
			 st[0].insert(i);
             st[i].insert(0);

        }

		for(i = 1;i<=6;i++)
		{
			capa[m+i][m+7] = n/6;
			capa[m+7][m+i] = n/6;
			st[m+i].insert(m+7);
            st[m+7].insert(m+i);
		}

		
        s = 0;
		d = m+7;
        
        memset(visited,false,sizeof(visited));
        long long int ans =  max_flow();
        if(ans == m)
		{
			cout << "YES\n";
		}
		else
			cout << "NO\n";
        mp.clear();
        for(i = 0; i <= m+7;i++)
        {
              if(!st[i].empty())
              st[i].clear();
        }  
    }

    return 0;
}
