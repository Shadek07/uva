#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
unsigned long long n;
void recur(unsigned long long n)
{
     unsigned long mod;
     unsigned long div;
     if(n == 0)
     return;
     else if(n >= 10000000)
     {
          mod = n%10000000;
          div = n/10000000;
          recur(div);
          cout << " kuti";
          recur(mod);          
     }
     else if(n >= 100000)
     {
          mod = n%100000;
          div = n/100000;
          recur(div);
          cout << " lakh";
          recur(mod);  
     }
     else if(n >= 1000)
     {
          mod = n%1000;
          div = n/1000;
          recur(div);
          cout << " hajar";
          recur(mod); 
     }
     else if(n >= 100)
     {
          mod = n%100;
          div = n/100;
          recur(div);
          cout << " shata";
          recur(mod); 
     }
     else
     {
         cout << " " << n;
     }
}
int main(void)
{
    int ca = 1;
    while(cin >> n)
    {
              printf("%4d.",ca++);
              if(n <100)
              {
                  cout << " " << n << endl;
                  continue;
              }
              recur(n);
              cout << endl;
    }
    return 0;
}
