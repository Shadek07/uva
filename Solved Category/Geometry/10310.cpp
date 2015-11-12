#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double hole[1005][2];
int n;
double dx,dy,gx,gy;
double tx,ty;

double square(double x)
{
       return x*x;
}
int main(void)
{
    int i,j,k;
    int ch;
    double pg,pd;
    while(cin >> n)
    {
          cin >> gx >> gy >> dx >> dy;
          for(i = 0; i <n;i++)
          cin >> hole[i][0]>> hole[i][1];   
          ch = 0;
          
          for(i = 0; i < n;i++)
          {
               pg = sqrt(square(hole[i][0]-gx) + square(hole[i][1]-gy)); 
               pd = sqrt(square(hole[i][0]-dx) + square(hole[i][1]-dy));
               if((pd/2.0)>= pg)
               {
                     ch = 1;
                     tx = hole[i][0];
                     ty = hole[i][1];
                     break;
               }
          }
          
          if(ch == 1)
          {
                cout << "The gopher can escape through the hole at (";
                printf("%.3lf,%.3lf).\n",tx,ty);
          } 
          else
          {
              cout << "The gopher cannot escape.\n";
          }
    }
}
