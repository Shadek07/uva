#include<iostream>

using namespace std;

int main(void)
{

	char c;

	int i, count = 0,s = 0 ;

	while( ( c = getchar()) != EOF )
	{


        if( c == '\n' )
		{
	     	cout << count << "\n" ;

	     	count = 0 ;

			s = 0;
		}

		if( !((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ) // if not a letter
		{
             s = 0 ;


		}

				

		else if( s == 0 )
		{
			s = 1;

			count++ ;
		}
	}




	return 0 ;
}