#include<iostream>

using namespace std ;

int main(void)
{

	int paste = 0 ;

	int num ,k = 1 ,  check = 1, j = 1;

	cin >> num ;

	while( num > 0)
	{

        while( check )
		{

			if( num == 1 )
			{
				cout << "Case " << j++ << ":" << " " << paste << "\n" ;

				break ;

			}

			if( num == 2 )
			{

                   cout << "Case " << j++ << ":" << " " << "1" << "\n" ;

				   break ;

			}

			k *= 2 ;

			if( k < num )
			{
				paste++ ;
			}

			else
			{
				paste++ ;

				check = 0;

				cout << "Case " << j++ << ":" << " " << paste << "\n" ;

			}


		}


		cin >> num ;

		check = 1 ;

		k = 1;

		paste = 0 ;
	}


	return 0; 

}