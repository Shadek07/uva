#include<iostream>

using namespace std ;

int main(void)
{
    
    
    string a[11] ;
    
    int t = 1 ;
    
    int i = 0, ch = 1 ,m,n, count = 0;
    
    char in[11] ;
    
    while( gets(in) )
    {
           
           if( in[0] != '9' )
           {
               a[i++] = in ;
               
           } 
           
           else
           {
               
               
               for( m = 0 ; m <= i-1 ; m++ )
               {
                    
                    for( n = 0 ; n <= i- 1 ; n++ )
                    {
                         
                         if( m != n )
                         {
                             
                             count = a[m].find(a[n]);
                             
                             if( count == 0)
                             {
                                 ch = 0 ;
                                 
                                 break ;
                                 
                                 
                             }
                             
                             
                         }
                         
                         
                    }
                    
               }
               
               if( ch == 0 )
               {
                   cout << "Set " << t++ << " is not immediately decodable\n";
               }
               
               else
               {
                   
                   cout << "Set " << t++ << " is immediately decodable\n" ;
                   
               }
               
               ch = 1 ;
               
               i = 0 ;
               
               
           }
           
           
           
           
    }
    
    
   
   
   return 0 ;   
    
}
