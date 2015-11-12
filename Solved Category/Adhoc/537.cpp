#include<iostream>

using namespace std ;

int main(void)
{
    
    
    int t ;
    
    
    char c,c2,c3,c1 ;
    
    float one,to,three ;
    
    double ret ;
    
    int prob = 1 ;
    
    int i,j,k ;
    
    int k1 = 0;
    
    int k2 = 0 ;
    
    int k3 = 0 ;
    
    int i1 = 0,i2 = 0,i3 = 0 ;
    
    cin >> t ;
    
    c3 = getchar() ;
    
    while(t--)
    {
              
              
              while( ( c = getchar() ) != '\n' )
              {
                     
                     
                     if( c == 'I' || c == 'U' || c == 'P' )
                     {
                         
                         c1 = getchar() ;
                         
                         if( c1 == '=' )
                         {
                             
                             if( c == 'I' )
                             {
                                 
                                 cin >> one ;
                                 
                                 i1 = 1 ;
                                 
                                 k1 = 1 ;
                             }
                                 
                             if( c == 'U' )
                             {
                                 
                                 cin >> to ;
                                 
                                 i2 = 1 ;
                                 
                                 k2 = 1 ;
                             }
                                 
                             if( c == 'P' )
                             {
                                  
                                  cin >> three ;  
                                  
                                  i3 = 1 ;
                                  
                                  k3 = 1 ;
                             }                            
                             
                             
                         }
                         
                         c2 = getchar() ;
                         
                         if( c2 == 'm' || c2 == 'M' || c2 == 'k' )
                         {
                             
                             if( i1 == 1 )
                             {
                                 
                                 
                                 if( c2 == 'm' )
                                 {
                                     
                                     one /= 1000 ;
                                     
                                     
                                     
                                 }
                                 
                                 if( c2 == 'M' )
                                 {
                                     
                                     
                                     one *= 1000000 ;
                                 }
                                 
                                 if( c2 == 'k' )
                                 {
                                     
                                     one *= 1000 ;
                                 }
                                 
                                 i1 = 0 ;
                             }
                             
                             if( i2 == 1 )
                             {
                                 
                                 if( c2 == 'm' )
                                 {
                                     
                                     to /= 1000 ;
                                     
                                     
                                     
                                 }
                                 
                                 if( c2 == 'M' )
                                 {
                                     
                                     
                                     to *= 1000000 ;
                                 }
                                 
                                 if( c2 == 'k' )
                                 {
                                     
                                     to *= 1000 ;
                                 }
                                 
                                 i2 = 0 ;
                             }
                             
                              if( i3 == 1 )
                             {
                                 
                                 if( c2 == 'm' )
                                 {
                                     
                                     three /= 1000 ;
                                     
                                     
                                     
                                 }
                                 
                                 if( c2 == 'M' )
                                 {
                                     
                                     
                                     three *= 1000000 ;
                                 }
                                 
                                 if( c2 == 'k' )
                                 {
                                     
                                     three *= 1000 ;
                                 }
                                 
                                 i3 = 0 ;
                             }
                             
                             
                             
                             
                             
                         }
                         
                         
                         i1 = i2 = i3 = 0 ;
                         
                         
                     }
                     
                     
                     
              }
              
              cout << "Problem #" << prob++ << "\n" ;
              
              if( k1 && k2 )
              {
                  ret = one*to ;
                  
                 // cout <<  << "W\n" ;
                 
                 cout << "P=" ;
                 
                 printf("%.2f", ret) ;
                 
                 cout << "W\n" ;
              }
              
              if( k1 && k3 )
              {
                  ret = three / one ;
                  //cout << three / one << "V\n" ;
                  
                  cout << "U=" ;
                  
                  printf("%.2f",ret) ;
                  
                  cout << "V\n" ;
                  
              }
              
              if( k2 && k3 )
              {
                  ret = three/to ;
                  
                 // cout << three/to << "A\n" ;
                 
                 cout << "I=" ;
                 
                 printf("%.2f",ret) ;
                 
                 cout << "A\n" ;
                  
                  
              }
              
              cout << "\n" ;
              
              k1 = k2 = k3 = 0 ;
              
              
              
              
    }
              
              
              
              
    
   
    
    return 0 ;   
}
