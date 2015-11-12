#include<iostream>

using namespace std;

int main( void)
{
	int s,t,n;

	int i,j,k,g ;

	int count ;

	cin >> s >> t >> n;

	while( !(s == 0 && t == 0 && n == 0 ))
	{
		count = (n*s) + (n+1)*3 ;

		for( i = 1; i <= n  ; i++ )
		{

			for( j = 1; j <= t ; j++ )
			{
				for( k = 1 ; k <= count ; k++ )
				{
					cout << "*";
				}

				cout << "\n";
			}

			for( g = 1; g <= s ; g++ )
			{


			


						for( j = 1 ; j <= ( 2*n + 1 ) ; j++)
						{
					

								if( j %2 == 1 )
								{
									for( k = 0 ; k < 3 ; k++)
									{
										cout << "*";
									}
								}

								else
								{

									for( k = 1 ; k <= s ; k++ )
									{
										cout << ".";
								

									}
								}
						}

						cout << "\n";


			}

		}


		for( j = 1; j <= t ; j++ )
		{
			for( k = 1 ; k <= count ; k++ )
			{
				cout << "*";
			}

			cout << "\n";
		}

      
		cin >> s >> t >> n;
	}


	return 0;
}