#include<iostream>

using namespace std ;
int sum(int num) ;

int main(void)
{
    char in1[26],in2[26] ;
    int one = 0 ,i,j,m;
    int to = 0;
    float three ;
    
    while( gets(in1))
    {
        gets(in2) ;
        
        for( i = 0 ; i < strlen(in1) ; i++ )
        {
            if( in1[i] >= 'a' && in1[i] <= 'z' )
            {
                one += (int)in1[i] - 96 ;
            }
            
            if( in1[i] >= 'A' && in1[i] <= 'Z' )
            {
                one += (int)in1[i] - 64 ;
            }
            
        }
        
        while(one >= 10 )
        {
            one = sum(one) ;
            
        }
        
        for( i = 0 ; i < strlen(in2) ; i++ )
        {
            if( in2[i] >= 'a' && in2[i] <= 'z' )
            {
                to += (int)in2[i] - 96 ;
            }
            
            if( in2[i] >= 'A' && in2[i] <= 'Z' )
            {
                to += (int)in2[i] - 64 ;
            }
            
        }
        
        while(to >= 10 )
        {
            to = sum(to) ;
            
        }
        if( to <= one)
        
        three = (to*1.0)/one ;
        else
        three = (one*1.0)/to ;
        
        three *= 100 ;
        
        printf("%.2f",three) ;
        
        cout << " %\n";
        one = 0;
        to = 0;
        
        
        
    }
    
    
    
    return 0;
}

int sum(int num)
{
    int t= 0;
    
    while( num > 0 )
    {
        t += num%10;
        num /= 10;
    }
    return t;
    
    
}














