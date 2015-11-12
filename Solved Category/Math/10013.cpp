#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int fir[1000001];
int sec[1000001];
int res[1000001];
int main(void)
{
    int t,i,j;
    int ch = 0;
    int n;
    int cn;
    int a,b;
    cin >> t;
    
    while(t--)
    {
              cin >> n;
              for(i = 0; i < n;i++)
              {
                    cin >> fir[i] >> sec[i];
              }
              
              cn = 0;
              for(i = n-1;i>= 0; i--)
              {
                    a = fir[i] + sec[i] + cn;
                    res[i] = a%10;
                    if(a >= 10)
                    cn = 1;
                    else
                    cn = 0;                 
              }
              
              if(ch == 0)
              ch = 1;
              else
              cout << endl;
              if(cn==1)
              cout << 1;
              for(i = 0; i < n;i++)
              cout << res[i];
              cout << endl;
              
    }
    return 0;
}
