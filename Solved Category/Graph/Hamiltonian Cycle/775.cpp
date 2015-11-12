#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>

using namespace std;

char in[50];
int n;

bool adj[260][260];
bool used[260];
int x[260];
int dp[260];

bool path_ok(int k)
{
     if(used[x[k]])
     return false;
     if(k<n)
     {
            return adj[x[k-1]][x[k]];
     }
     else
     {
         return adj[x[n-1]][x[n]] && adj[x[1]][x[n]];
     }
}
int i1;
bool rhamilton(int k)
{
     int i,j;
     bool ch;
     for(i = 2; i <= n;i++)
     {
           x[k] = i;
           if(path_ok(k))
           {
                  used[x[k]] = true;
                  if(k == n||rhamilton(k+1))
                  return true;
                  used[x[k]] = false;
           }
     }
     
     return false;
}
int main(void)
{
    int i,j;
    char *p;
    int a,b;
    bool ch;
    while(cin >> n)
    {
         getchar();
         
         memset(adj,false,sizeof(adj));
         memset(dp,-1,sizeof(dp));
         while(1)
         {
                 gets(in);
                 if(in[0] == '%')
                 break;
                 p = strtok(in,"        ");
                 a = atoi(p);
                 
                 p = strtok(NULL,"         ");
                 b = atoi(p);
                 adj[a][b] = true;
                 adj[b][a] = true;                                
         }
         
         x[1] = 1;
         used[1] = true;
         for(i = 2;i <= n;i++)
         used[i] = false;
         i1 = 2;
         ch = rhamilton(2);
         if(ch == false)
         {
               cout << "N\n";
         }
         else
         {
             cout << x[1] ;
             for(i = 2; i <= n;i++)
             {
                   cout << " " << x[i];
             }
             cout << " " << x[1] << endl; 
         }
         
    }
    
    return 0;
}
