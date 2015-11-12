#include<iostream>

using namespace std ;

int prime( int num ) ;

int main (void)
{
	char t[2001],c ;

	int fre[62] = {0} ;

	int term, go = 1,i,j ,k,emp = 0;

	cin >> term ;

	c = getchar() ;

	while( term )
	{

		gets(t);

		for( i = 0 ; i < strlen(t) ; i++ )
		{

			if( t[i] >= '0' && t[i] <= '9' )
			{
				fre[ t[i] - '0' ]++ ;


			}

			if( t[i] >= 'A' && t[i] <= 'Z' )
			{
				fre[ t[i] - 'A' + 10 ]++ ;


			}

			if( t[i] >= 'a' && t[i] <= 'z' )
			{
				fre[ t[i] - 'a' + 36 ]++ ;


			}

		}


		cout << "Case " << go << ": " ;


		for( j = 0 ; j < 62 ; j++ )
		{

			if( fre[j] >= 2 )
			{

				

				k = prime( fre[j] ) ;

				if( k )
				{
					if( j >= 0 && j <= 9 )
					{

						cout << char( '0' + j ) ;
					}

					if( j >= 10 && j <= 35 )
					{

						cout << char( 'A' + j - 10) ;
					}

					if( j >= 36 && j <= 61 )
					{

						cout << char( 'a' + j - 36) ;
					}

					emp = 1 ;

				}
			}


		}

		if( emp == 0 )

			cout << "empty";

		cout << "\n";

		for( i = 0 ; i< 62 ; i++ )
		{

			fre[i] = 0;
		}

        go++ ;

		emp = 0;

		term--;
	}




	return 0;
}

int prime( int num )
{
	int p = 1 ;

	int i ;

	for( i = 2 ; i <= num/2 ; i++ )
	{
		if( num % i == 0 )

			p = 0;
	}

	return p ;

}