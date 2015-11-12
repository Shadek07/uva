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




bool dp[1000001];
int take[11];

int main(void)
{
    int n;
    int m;
    int i,j,k;
    while(cin >> n)
    {
         cin >> m;
         for(i = 0;i < m;i++)
         {
               cin >> take[i];
         }
         
         if(n == 0)
         {
              cout << "Ollie wins\n";
              continue;
         }
         
         memset(dp,false,sizeof(false)*(n+1));
         
         for(i = 0; i < m;i++)
         {
               dp[take[i]] = true;
         }
         
         for(i = 1; i <= n;i++)
         {
              for(j = 0; j < m;j++)
              {
                    if(i-take[j] >= 0 && dp[i-take[j]] == false)
                    {
                                 dp[i] = true;
                                 break;
                    }
              } 
         }
         
         if(dp[n] == true)
         cout << "Stan wins\n";
         else
         cout << "Ollie wins\n";     
    }
    return 0;
}
