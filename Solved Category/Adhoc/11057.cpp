#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    int t,in[10000],total;
    int one,to ;
    int min = 1000000;
    char c;
    
    while((scanf("%d",&t))== 1)
    {
        
           int i,m,n;
           
           for(i = 0 ; i  < t;i++)
           {
                cin >> in[i] ;
           }
           cin >> total ;
           
           getchar();
           getchar();
           
           for( m = 0 ; m < t ; m++)
           {
                for(n = m+1 ; n < t; n++ )
                {
                    if( in[m] + in[n] == total )
                    {
                        if(  abs(in[m] - in[n]) < min)
                        {
                            one = in[m];
                            to = in[n];
                            min = abs(in[m] - in[n]) ;
                        }
                    }
                }
            }
           
         if( one > to )
         {
                int tmp = one;
                one = to;
                to = tmp;
         }                    
                             
       cout <<"Peter should buy books whose prices are " << one << " and " << to<< ".";                     
       cout <<  "\n" ;
       cout << "\n" ;
                             
        min = 1000000;                     
    }
    
    
    return 0;   
}
