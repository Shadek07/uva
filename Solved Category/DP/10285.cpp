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

using namespace std;

#define max1(a,b) a>b?a:b

char name[100];
int r,c;

int grid[101][101];
int dp[101][101];

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool check(int a,int b)
{
     if(a >= 0 && a < r && b >= 0 && b < c)
     return true;
     else
     return false;
}
int solve(int i,int j)
{
    int a,b,k,tmp; 
    int mx = 1;
    
    if(dp[i][j] != 1)
    return dp[i][j];
    
    for(k = 0; k < 4;k++)
    {
        a = i+dx[k];
        b = j+dy[k]; 
        if(check(a,b) && grid[a][b] < grid[i][j])
        {
              tmp = solve(a,b);
              mx = max1(mx,1+tmp);       
        } 
    }
    
    return dp[i][j]=mx;
}

int main(void)
{
    int t;
    int i,j,k;
    int mx;
    cin >> t;
    getchar();
    while(t--)
    {
              cin >> name >> r >> c;
              for(i = 0; i < r;i++)
              {
                    for(j = 0; j < c;j++)
                    {
                        cin >> grid[i][j];  
                    }
              }
              
              //memset(dp,1,sizeof(dp));
              for(i= 0; i < r;i++)
              {
                     for(j = 0; j < c;j++)
                     dp[i][j] = 1;
              }
              
              mx = 0;
              for(i = 0; i < r;i++)
              {
                    for(j = 0; j < c;j++)
                    {
                          if(dp[i][j] == 1)
                          {
                                      k = solve(i,j);
                                      mx = max1(mx,k);
                          }
                    }
              }
              
              cout << name << ": " << mx << endl;
              
    }
     
    
    return 0;
}
