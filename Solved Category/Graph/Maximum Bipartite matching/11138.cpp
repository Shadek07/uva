#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int  r[501][501]; 
int  N,M; 
int  v[501]; 
int  m[501],m1[501]; 
int a[501],b[501];
vector<int> adj[501];
int  dfs(int  a) 
{ 
          if(a<0)  
          return 1; 
          
          if(v[a])  
          return 0; 
          
          v[a]=1; 
          
          int  i,i1;
          for(i=0;i<M;i++)  
          if(r[a][i])
          { 
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
          for(i=0;i<N;i++)  
			  v[i]=0;          
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
    while(t--)
    {
              cin >> N;
              cin >> M;
              memset(r,0,sizeof(r));
              for(i = 0; i<N;i++)
              {
                  for(j = 0;j<M;j++)
                  {
                        cin >> r[i][j];
                   }
              }
              
              int ans = bipMatch();
              cout << "Case " << ca++ << ": ";
              printf("a maximum of %d nuts and bolts ",ans);
		       printf("can be fitted together\n");
              
    }
        
    return 0;
}
