#include<iostream>

using namespace std ;

int main(void)
{
    
    int t,f,a,b,c,i ;
    
    float ti ;
    
    float cal = 0;
    
    
    cin >> t ;
    
    while(t--)
    {
              
              cin >> f ;
              
              for( i = 0 ; i < f ; i++ )
              {
                   
                   cin >> a >> b >> c ;
                   
                   ti = (a*1.0)/ b ;
                   
                   ti *= (b*c) ;
                   
                   cal += ti ;
                   
                   
                   
              }
              
              cout << cal << "\n"  ;
              
              cal = 0 ;
              
              
              
              
    }
    
    
 
 
    
    return 0 ;   
    
}
