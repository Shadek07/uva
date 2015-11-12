#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

#define E 2.7182818284
 double  p, q, r, s, t,u;
double cal(double x)
{
    return p*pow(E,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;   
}
int main(void)
{
   
    double low,m,x,high,value;
    while(cin >> p >>  q >> r>> s>> t>>u)
    {
              low = 0.0;
              high = 1.0;
              if(cal(0)*cal(1) > 0)
              {
                  printf("No solution\n");
                  continue;
              }
               if(cal(1)<cal(0))
	            {
	                high = 0.0;
	                low = 1.0;
	            }
              while(1)
              {
                      x = (low+high)/2.0;
                      value = p*pow(E,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
                      if(value > (0 - 0.00000005) && value < (0 + 0.00000005))
                      {
                               break;
                      }
                      else if( value > 0)
                      {
                           high = x;
                      }
                      else
                      low = x;
                      
              }
              
              printf("%.4lf\n",x);
    }
}
