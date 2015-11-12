#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
int n,k;
int main(void)
{
    int i,j,k,a,b;
    long double res,out;
    while(cin >> n >> k)
    {
          a = k;
          b = n-k;
          res = 0.0;
          if(k>n-k)
          {
                   for(i = k+1,j=1;i<=n||j<=n-k;i++,j++)
                   {
                         if(i<=n)
                         res += log10(i*1.0);
                         if(j<=n-k)
                         res -= log10(j*1.0);
                   }
          }
          else
          {
              for(i = n-k+1,j=1;i<=n||j<=k;i++,j++)
              {
                         if(i<=n)
                         res += log10(i*1.0);
                         if(j<=k)
                         res -= log10(j*1.0);
              }
          }
          
          out = floor(res) + 1;
          cout << int(out) << endl;
          //printf("%.0lf\n",out);   
    }
    return 0;
}
