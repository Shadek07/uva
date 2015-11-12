#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(void)
{

	char in[1000009] ;



	int f = 1 ;

	char che[11] = {'a','e','i','o','u','A','E','I','O','U' } ;

	int i,j,k ;

    while( gets(in) )
	{


		i = strlen(in) ;

		for( j = 0 ; j < i ; j++ )
		{

			if( in[j] != ' ' && in[j] != '\t')
			{

				for( k = 0 ; k < 10 ; k++ )
				{
					if( in[j] == che[k] )

						f = 0 ;
				}

				if( f == 0 )
				{

                    while( (islower(in[j]) || isupper(in[j])) && j < i)
					{
						cout << in[j] ;

						j++ ;


					}

					cout << "ay" ;


				}

				else
				{
					char d = in[j] ;

					j++ ;

					while( (islower(in[j]) || isupper(in[j])) && j <i)
					{
						cout << in[j] ;

						j++ ;

					}

					cout << d << "ay" ;


				}

                while( !(islower(in[j]) || isupper(in[j])) && j <i )
				{

					cout << in[j] ;

					j++ ;
				}

				j -- ;

				f = 1 ;

			}


		}

        cout << "\n" ;

		f = 1 ;


	}



	return 0;
}
