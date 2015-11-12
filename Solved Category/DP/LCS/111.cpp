#include<iostream>

using namespace std ;

int main( void)
{
	int in[30] ;
	
	int a;

	int correct[30] ;

	int cal[31][31] ;

	int num ,i,j;

	int x;

	cin >> num ;

	for( i = 1 ; i <= num ; i++ )
	{
         cin >> a;
         
		 correct[a] = i ;
	}

   while( cin >> x )
   {
               
	           in[x] = 1;

				for( i = 2 ; i <= num ; i++ )
				{
                     cin >> a;
                     in[a] = i;
					
				}

				

			

				for( i = 0 ; i <= num ; i++ )
				{
					cal[i][0] = 0 ;

					cal[0][i] = 0 ;
				}

				for( i = 1 ; i <= num ; i++ )
				{
					for( j = 1 ; j <= num ; j++ )
					{

						if( in[i] == correct[j] )
						{
							cal[i][j] = cal[i-1][j-1] + 1;
						}

						else if( cal[i-1][j] >= cal[i][j-1] )
						{
							cal[i][j] = cal[i-1][j] ;
						}

						else
						{
							cal[i][j] = cal[i][j-1]; 
						}
					}
				}

				cout << cal[num ][num ] << "\n"  ;

			
   }




	return 0;
	
}
