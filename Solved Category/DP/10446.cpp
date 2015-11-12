#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

unsigned long long dp[62][62];

int main(void)
{
    int i,j,k;
    int n,back;
    int ca = 1;
    
    unsigned long long a,b;
    
    for(i = 0; i <= 60;i++)
    {
          dp[0][i] = 1;
          dp[1][i] = 1;
          dp[i][0] = 1;          
    }
    
    for(i = 2;i<=60;i++)
    {
          for(j = 1; j <= 60;j++)
          {
               a = 0;
               for(k = 1;k<=j;k++)
               if(i-k >= 0)
               a += dp[i-k][j];
               if(j > i)
               a += (j-i);
               dp[i][j] = a+1; 
          }
    }
    
    
    while(cin >> n >> back)
    {
              if(n > 60)
              break;
              cout << "Case " << ca++ << ": ";
              if(back < 1)
              {
                   cout << 1 << endl;
                   continue;   
              }
              if(n < 2)
              {
                  cout << 1 << endl;
                  continue; 
              }
              
              cout << dp[n][back] << endl;
    }
    
    return 0;
}
