#include<iostream>

using namespace std;

int ln();
char x[1010],y[1010];
int c[1010][1010];

int main(void)
{
     
     int h;

	 int t;
     
     int ca = 1;
     int check = 1 ;

	 cin >> t;
	 getchar();
     
     while(t--)
     {
          gets(x);
          
		  ca = strlen(x);

		  for( int i = ca-1; i >= 0; i--)
		  {
			  y[ca-i-1] = x[i];
		  }

		  y[ca] = '\0';

          //gets(y);  
         
          
          
                 
                 //if( ca != 0)
                 h = ln();
				 //else
					 //continue;
                 
                 cout <<  h << "\n";

                 
          
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
    
    
    
    
    
    
    
    
    
    
    
    
    
