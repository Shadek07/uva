#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[2501];
int cnt[5000];
bool visited[2501];
int e;
int t,n;
int src;
struct point
{
       int node;
       int day;
};

queue<point> pq;

int main(void)
{
    cin >> e;
    int i,j,k,a,b,c;
    
    struct point p,q;
    
    for(i = 0; i<e;i++)
    {
          cin >> n;
          for(j = 0;j<n;j++)
          {
                cin >> a;
                v[i].push_back(a);
          }
    }
    cin >> t;
    for(i = 0; i < t;i++)
    {
          cin >> src;
          memset(cnt,0,sizeof(cnt));
          memset(visited,false,sizeof(visited));
          visited[src] = true;
          p.day = 0;
          p.node = src;
          pq.push(p);
          while(!pq.empty())
          {
               q = pq.front();
               pq.pop();
               b = q.node;
               a = v[b].size();
               for(j = 0; j < a;j++)
               {
                   c = v[b][j];
                   if(!visited[c])
                   {
                        visited[c] = true;
                        p.node = c;
                        p.day = q.day + 1;
                        cnt[p.day]++;
                        pq.push(p);   
                   } 
               }          
          }
          
          int mn = 0;
          int ind = 0;
          for(j = 0; j <= e;j++)
          {
                if(cnt[j] > mn)
                {
                     mn = cnt[j];
                     ind = j;
                }
          }
          
          if(mn == 0)
          {
                cout << 0 << endl;
          }
          else
          cout << mn << " " << ind << endl;
    }
    
    return 0;
}
