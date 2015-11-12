#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
int  N,M;
char  bd[50][50]; 
int  x[20],y[20],r[20][20]; 
int  n; 
int  m[1<<17][17]; 

int  abs(int  a) 
{ 
     if(a<0)  return  -a; 
     return  a; 
} 

int  play(int  S ,int  s) 
{ 
     if(S==(1<<s))  
     return  r[s][0]; 
     int &  v=m[S][s]; 
     if(v>=0)  return  v; 
     v=100000000; 
     for(int  i=0;i<n;i++)  
       if(i!=s)  
       if(S&(1<<i)) 
          v=min(v,r[s][i]+play(S-(1<<s),i)); 
     return  v; 
}

int  main() 
{ 
     int  i,j; 
     while(cin>>N>>M)
     { 
          for(i=0;i<N;i++)  cin>>bd[i]; 
          n=1; 
          for(i=0;i<N;i++)  
             for(j=0;j<M;j++) 
             { 
                   if(bd[i][j]=='L')  
                   {
                        x[0]=i; 
                        y[0]=j;
                   } 
                   if(bd[i][j]=='#')  
                   {
                       x[n]=i;  
                       y[n]=j;  
                       n++;
                   } 
              } 
          for(i=0;i<n;i++)  
            for(j=0;j<n;j++) 
                r[i][j]= max(abs(x[i]-x[j]), abs(y[i]-y[j])); 
          memset(m,  -1,  sizeof(m)); 
          cout<< play((1<<n)-1,0)<<endl; 
     } 
     return  0; 
}
