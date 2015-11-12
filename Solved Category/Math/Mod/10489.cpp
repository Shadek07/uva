#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    int t;
    long int fnd,box;
    long int i,j,k,a,b;
    long int t1,t2;
    cin >> t;
    
    while(t--)
    {
          cin >> fnd >> box;
          a = 0;
          for(i = 0; i < box; i++)
          {
                cin >>  j;
                
                t1 = 1;
                
                for( k = 1; k <= j; k++)
                {
                     cin >> b;
                     t1 *= b;
                     t1 = t1%fnd;
                }
                
                a += t1;
          }
          
          cout << a%fnd << endl;
              
    }
    return 0;
}
