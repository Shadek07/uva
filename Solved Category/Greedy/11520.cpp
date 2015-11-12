#include<iostream>

using namespace std ;

int main(void)
{
    int t,d,m,n,term = 1 ;
    
    char in[10][11] , c = 'A' ;
    
    char res[10][11] ;

	bool neighbour[4];

	int i;
    
    cin >> t ;
    
    while(t--)
    {
        cin >>  d ;
        
        c = getchar();

		memset(neighbour,false,sizeof(neighbour));
        
        for( m = 0 ; m < d; m++)
        {
             gets(in[m]);
        }
             
         for( m = 0 ; m < d;m++)
         {
              
              for( n = 0; n < d ; n++)
              {
                   if( in[m][n] != '.')
                   {
                       res[m][n] = in[m][n];
                   }
                   else
                   {
					   if( m-1 >= 0 )
					   {
                           if(in[m-1][n] >= 'A' && in[m-1][n] <= 'D')

							   neighbour[in[m-1][n]-'A'] = true;
					   }
					   if( m+1 < d )
					   {
						   if(in[m+1][n] >= 'A' && in[m+1][n] <= 'D')

							   neighbour[in[m+1][n]-'A'] = true;

					   }
					   if( n-1 >= 0 )
					   {
						    if(in[m][n-1] >= 'A' && in[m][n-1] <= 'D')

							   neighbour[in[m][n-1]-'A'] = true;

					   }
					   if( n+1 < d )
					   {
						   if(in[m][n+1] >= 'A' && in[m][n+1] <= 'D')

							   neighbour[in[m][n+1]-'A'] = true;

					   }

					   for( i = 0; i < 4; i++)
					   {
						   if( neighbour[i] == false)
						   {
                               res[m][n] = char('A' + i);
							   in[m][n] = char('A' + i);
							   break;
						   }
					   }
					   if( i == 4)
					   {
						   res[m][n] = 'E';
						   in[m][n] = 'E';
					   }

					   memset(neighbour,false,sizeof(neighbour));
				   }
                       
                    
                   
              }
               
         }    
             
         
         cout << "Case " << term++ << ":\n" ;
         
         for( m = 0 ; m < d ; m++ )
         {
              for( n = 0 ; n < d ; n++ )
              {
                   cout << res[m][n] ;
              }
              cout << "\n"; 
         }   
             
    }
    
   return 0;   
}
