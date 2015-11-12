#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int  r[110][110]; 
int  N,M; 
int  v[110]; 
int  m[110],m1[110]; 
int a[110],b[110];
vector<int> adj[110];
int  dfs(int  a) 
{ 
          if(a<0)  
          return 1; 
          
          if(v[a])  
          return 0; 
          
          v[a]=1; 
          
          int  i,i1;
          //int sz = adj[a].size();
          for(i=0;i<M;i++)  
          if(r[a][i])
          { 
                       //i = adj[a][i1];
                    if(dfs(m1[i])) 
                    { 
                               m[a]=i;
                               m1[i]=a; 
                               return 1; 
                    } 
          } 
          return 0; 
} 

int  dfsExp(int  a)    
{ 
          int  i; 
          for(i=0;i<N;i++)  v[i]=0;
           
          return  dfs(a); 
} 

int  bipMatch() 
{ 
          int  i; 
          int  ans=0; 
          for(i=0;i<N;i++)  m[i]=-1; 
          for(i=0;i<M;i++)  m1[i]=-1; 
          for(i=0;i<N;i++)  
          if(m[i]<0)  
          ans += dfsExp(i); 
          return ans; 
} 

int main(void)
{
    int t;
    cin >> t;
    int ca = 1;
    int i,j,k;
    //ofstream f3("11159.out");
    while(t--)
    {
              cin >> N;
              for(i = 0; i <N;i++)
              cin >> a[i];
              cin >> M;
              for(i = 0; i <M;i++)
              cin >> b[i];
              memset(r,0,sizeof(r));
              for(i = 0; i<N;i++)
              {
                    for(j = 0;j<M;j++)
                    {
                          if(b[j] == 0)
                          r[i][j] = 1;
                          //adj[i].push_back(j);
                          if(a[i] == 0)
                          continue;
                          if(b[j]%a[i] == 0)
                          r[i][j] = 1;
                          //adj[i].push_back(j);
                    }
              }
              
              int ans = bipMatch();
              //cout << "Case " << ca++ << ": ";
              //cout << ans << endl;
              cout << "Case " << ca++ << ": ";
              cout << ans << endl;
              //for(i = 0; i <=M;i++)
              //adj[i].clear();
              
    }
        
    return 0;
}
