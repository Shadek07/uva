#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
    int N;
    
    int i,j,x,y;
    
    int t1,t2,t = 0;
    int c = 0;
 
    cin >> N;
    
    while( N != 0)
    {
           for( i = 2; i < N ; i++)
           {
                for( j = 1; j <= i-1 ; j++)
                {
                     x = i*i*i;
                     y = j*j*j;
                     if( (x - y == N ))
                     {
                         c = 1;
                         t = 1;
                         t1 = i;
                         t2 = j;
						 i = N;
						 break;
                         
                     }
                    
                     
                         
                     
                }
                
           }
           
       if( c == 1)
       cout << t1 << " " << t2 << endl;
       else
       cout << "No solution" << endl;
       cin >> N;
       t = 0;
       c = 0;       
    }
    
    
    return 0;
}
