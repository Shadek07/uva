#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAX 40
#define INF 2147483647
using namespace std;
int cap[MAX][MAX],flow[MAX][MAX],pr[MAX],cnt;
void init()
{
     int i,j;
     for(i=0;i<=38;i++){
      for(j=0;j<=38;j++)
         cap[i][j]=flow[i][j]=0;
     }
}
int bfs(int source,int des)
{
    int u,v;
    bool visit[MAX];
    memset(visit,0,sizeof(visit));
    memset(pr,-1,sizeof(pr));
    queue<int>q;
    pr[source]=-1;
    visit[source]=1;
    q.push(source);
    while(!q.empty()){
       u=q.front();
       q.pop();
       if(u==des)
       return 1;
       for(v=0;v<=37;v++){
         if(!visit[v]&&(cap[u][v]-flow[u][v])>0){
            q.push(v);
            pr[v]=u;
            visit[v]=1;
         }
       }
    }
    return 0;
}                                                   
int  max_flow(int source ,int des)
{
     int u,v,inc,maxi=0;
     while(bfs(source,des)){
       inc=INF;
       for(v=des;pr[v]>-1;v=pr[v])
       {
         u=pr[v];
         inc=min(inc,cap[u][v]-flow[u][v]);
       }
       for(v=des;pr[v]>-1;v=pr[v]){
         u=pr[v];
         flow[u][v]+=inc;
         flow[v][u]-=inc;
       }
       maxi+=inc;
     }
     return maxi;
}                                                                                  
int main(){
    char f[10],s[40],buff[60];
    int i,l,j,total=0;
    bool flag;
    while(gets(buff))
	{
                                        
      sscanf(buff,"%s%s",f,s);
      i=f[1]-'0';
      total+=i;
      j=f[0]-'A'+1;
      cap[0][j]+=i;
      for(i=0;s[i]&&s[i]!=';';i++)
	  {
           cap[j][s[i]-'0'+27]=1;
      }
	  while(gets(buff))
	  {
		  if(strlen(buff)==0)
			  break;
		  sscanf(buff,"%s%s",f,s);
		  i=f[1]-'0';
		  total+=i;
		  j=f[0]-'A'+1;
		  cap[0][j]+=i;
		  for(i=0;s[i]&&s[i]!=';';i++)
		  {
			   cap[j][s[i]-'0'+27]=1;
		  }
	  }

	  for(i=27;i<=36;i++) cap[i][37]=1;
         l=max_flow(0,37);
         if(l!=total) printf("!\n");
         else{  
            for(i=27;i<37;i++)
            {
               flag=0;               
               for(j=1;j<27;j++)
               {
                 if(flow[i][j]==-1)
                 {
                     printf("%c",'A'+j-1);
                     flag=1;
                     break;
                 }
               }
               if(!flag) printf("_");
            }
            printf("\n");
         }
         init();
         total=0;
         //continue;
    }
    return 0;
}                            
