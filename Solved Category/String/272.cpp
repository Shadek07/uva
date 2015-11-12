#include<iostream>
using namespace std;
int main (void )

{
	char in[1000000];

	char c ;

	int i = 0,j = 0;

	int check = 1,temp = 0;

	
	while( ( c = getchar()) != EOF )
	{	
			in[i++] = c;			
	}

    in[i] = '\0' ;

			for( j = 0 ; j < i ; j++ )
			{

				if ( in[j] == '"' )
				{
					if( check == 1)
					{
						cout << "``" ;

						temp = 0;
					}

					if( check == 0)
					{
						cout << "''" ;

						temp = 1;
					}

					check = temp ;
				}

				else

					cout << in[j] ;

				

				
			}
			
		//	cout << "\n" ; 




	return 0;
}
