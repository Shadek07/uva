#include<iostream>

using namespace std;

int main( void )
{
	char t[100][101] ,c1;

	int p = 1;

    int r,c,i,j,k = 0 ;

	cin >> r >> c ;

	c1 = getchar() ;

	while( r != 0 && c != 0 )
	{

		for( i = 0 ; i < r ; i++ )
		{

			gets(t[i]) ;
		}
		for( i = 0 ; i < r ; i++ )
		{
			for( j = 0 ; j < c ; j ++ )
			{

				if( t[i][j] == '*')
				{

							if( (i - 1) != -1 && ( j - 1) != -1 )
							{
								if( t[i-1][j-1] == '*')

									p = 0;
							}

							if( (i - 1) != -1  )
							{
								if(t[i-1][j] == '*' )

									p = 0;

							}

							if( (i - 1) != -1 && ( j + 1) != c )
							{

								if(t[i-1][j + 1] == '*' )

									p = 0 ;

							}

							if( ( j + 1) != c )
							{

								if(t[i][j + 1] == '*' )

									p = 0;


							}

							if( (i + 1) != r && ( j + 1) != c )
							{


								if( t[i+1][j+1] == '*' )

									p = 0; 

							}

							if( (i + 1) != r  )
							{

								if( t[i+1][j] == '*' )

									p = 0;
							}

							if( (i + 1) != r && ( j - 1) != -1 )
							{

								if( t[i+1][j-1 ] == '*' )

									p = 0;
							}

							if( ( j - 1) !=  -1 )
							{
								if( t[i][j -1] == '*' )

									p = 0;
							}

							if( p == 1)

					           k++ ;

				            else

					           p = 1;
				}

				

			}

		}

		cout << k << "\n";


        k = 0;

		cin >> r >> c;

		c1 = getchar() ;
	}



	return 0;
}