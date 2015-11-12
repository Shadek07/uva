#include<iostream>

using namespace std;

int ln();
char x[1000],y[1000];
int c[1001][1001];

int main(void)
{
     
     int h;
     
     int ca = 1;
     int check = 1 ;
     
     while( check)
     {
          gets(x);
          if( x[0] == '#')
          {
              check = 0;
              break;
          }
          gets(y);  
         
          
          
                 
                 
                 h = ln();
                 
                 cout << "Case #" << ca++ << ": you can visit at most " << h << " cities.\n";

                 
          
      }
    
    
    return 0;
}

int ln()
{
    
    int m,n,i,j;
    m = strlen(x);
    n = strlen(y);
    
    for( i = 1; i <= m; i++) c[i][0] = 0;
    for( j = 0; j <= n; j++) c[0][j] = 0;
    
    
    for( i = 1 ; i <= m; i++)
    {
         for( j = 1 ; j <= n ; j++)
         {
              if( x[i-1] == y[j-1] )
              {
                  c[i][j] = c[i-1][j-1] + 1;
              }
              else if( c[i-1][j] >= c[i][j-1])
              {
                   c[i][j] = c[i-1][j];
              }
              else
              c[i][j] = c[i][j-1];
         }
    }
    
    return c[m][n];
}
    
    
    
    
    
    
    
    
    
    
    
    
    
