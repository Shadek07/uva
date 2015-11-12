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

int  r[102][102]; 
int  N,M; 
int s,v;
//int  v[501]; 
int  m[501],m1[501]; 
int a[501],b[501];
const double eps = 1e-11;
int match[102];
bool vis[101];
int cmp(const double a,const double b) 
 {
	return (fabs(a-b)<=eps?0:((a<b)?-1:1));
}  
vector<int> adj[501];

	double gopher[101][2];
	double hole[101][2];
	bool xyd(double x,double y)// x <= y 
	{   
		return x < y + eps;
	}      
/*int  dfs(int  a) 
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
} */
bool find(int u)  
{  
	int v;
    for(v=0;v<M;v++)  
    {  
            if(r[u][v] && !vis[v])  
            {  
                  vis[v]=true;  
                  if(match[v]==-1 || find(match[v]))  
                  {  
                        match[v]=u;// create a new match  
                        return true;  
                  }  
            }  
              
    }  
    return false;  
}// find the augment path and create a new match in the meantime 
int  bipMatch() 
{ 
       int  i,u; 
       int  ans=0; 
       for(u=0;u<N;u++)  
       {  
           memset(vis,0,sizeof(vis));  
           if(find(u))  
                ans++;                
       } 
       return ans; 
} 

double dist(int i,int j)
{
	double x,y;
	x = gopher[i][0]-hole[j][0];
	y = gopher[i][1] - hole[j][1];
	return sqrt(x*x + y*y);
}
int main(void)
{
    int t;
    
    int ca = 1;
    int i,j,k;
	double a,b,d;

    while(cin >> N )
    {

		  scanf("%d %d %d",&M,&s,&v);
		  for(i = 0;i<N;i++)
		  {
			  scanf("%lf %lf",&gopher[i][0],&gopher[i][1]);
		  }

		  for(i = 0;i<M;i++)
		  {
			  scanf("%lf %lf",&hole[i][0],&hole[i][1]);
		  }


		  for(i = 0;i<M;i++)
			  match[i] = -1;

          for(i = 0; i<N;i++)
          {
              for(j = 0;j<M;j++)
              {
				  d = dist(i,j);
				  
				  if(cmp(d,s*v)<=0)
				  {
						r[i][j] = 1;
				  }
				  else
					  r[i][j] = 0;
              }
          }
              
          int ans = bipMatch();
		  cout << N-ans << endl;
              
              
    }
        
    return 0;
}
