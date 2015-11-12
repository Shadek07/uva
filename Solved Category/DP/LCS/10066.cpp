#include<iostream>

using namespace std ;

 int main( void)
{
	long int in[100] ;
	
	long int a;

	long int m,n;

	long int correct[100] ;

	long int cal[102][102] ;

	long int num = 1 ,i,j;

   while(1)
   {

	   cin >> m >> n;

	   if( !m && !n)
		   break;

	   

	    for( i = 0 ; i < m ; i++ )
		{
			 cin >> correct[i];
        			  
		}


		for( i = 0 ; i < n ; i++ )
		{
                  cin >> in[i];
                  			
		}

				

			memset(cal,0,sizeof(cal));

		

				for( i = 1 ; i <= m ; i++ )
				{
					cal[i][0] = 0 ;

				
				}
				for( i = 0 ; i <= n ; i++ )
				{
					

					cal[0][i] = 0 ;
				}

				for( i = 1 ; i <= m ; i++ )
				{
					for( j = 1 ; j <= n ; j++ )
					{

						if( correct[i-1] == in[j-1] )
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

				cout << "Twin Towers #" << num++ << endl;

				cout << "Number of Tiles : " << cal[m][n] << "\n\n"  ;

			
   }




	return 0;
	
}
