#include<iostream>

using namespace std ;

int total(char t[] ) ;
int total1(int num) ;

int main(void)
{
    char in[1001],c;
    
    int i,j,k = 1, d = 0 ;
    
    while( k )
    {
        gets(in) ;
        
        if( in[0] == '0' )
        {
            k = 0;
            break;
        }
        
        else
        {
            int e =  total(in) ;
            
            d = 1 ;
            
            while( e > 9 )
            {
                d++ ;
                
                e =  total1( e );
                
            }
            
            if( e == 9)
            {
                cout << in << " is a multiple of 9 and has 9-degree " << d << ".\n" ;
                
            }
            else
            {
                cout << in << " is not a multiple of 9.\n" ;
            }
                
            
        }
        
        d = 0 ;
    }
    
    
    
    return 0 ;   
}

int total(char t[] )
{
    int sum = 0;
    
    for( int a  = 0 ; a < strlen(t) ;a++ )
    {
        sum += (int)(t[a] - 48) ;
    }
    
    return sum ;
}
int total1(int num)
{
    int y = 0 ;
    
    while(num > 9 )
    {
        y += num%10;
        
        num /= 10;
    }
    
    y += num ;
    
    return y;
    
    
      
    
    
    
}


