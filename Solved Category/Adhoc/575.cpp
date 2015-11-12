#include<iostream>

using namespace std ;

int power( int k) ;

int main(void)
{
    
    char in[190] ;
    
    int i = 0,j,k,l,num;
    
    int c = 1; 
    
    int get = 0 ;
    
    while( c )
    {
           
           gets(in);
           
           if( in[0] == '0' )
           {
               c = 0;
               
               break;
           }
           else
           {
               
                l = strlen(in) ;
                j = l ;
                
                for( i = 0 ; i < l ; i++ )
                {
                     num = power(j) - 1;
                     
                     get += ((int)in[i]- 48) * num ;
                     
                     j-- ;
                     
                }
                
                cout << get << "\n" ;
                
                get = 0 ;
               
           }
           
           
    }
    
    
    
    
   
   return 0 ;   
}

int power( int k)
{
    int r = 1 ,j;
    
    for( j = 0 ; j < k ; j++ )
    {
         r *= 2 ;
    }
    
    return r;
}






































