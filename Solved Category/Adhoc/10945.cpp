#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	char a[] = "You won't be eaten!\n";

	char b[] = "Uh oh..\n";

	char in[300];

	char c = 'A'; 

	int i,j,k;

	int check = 1;

	//cout << char(c + 32);

	gets(in);

   // tohin bai kamon asen?

    i = 0 ;

	while( strcmp(in,"DONE") != 0 )
	{

		j = strlen(in) ;

		k = j;

		j --;

		for( ;( i < k && j >= 0 ); i++ , j-- )
		{
			if( in[i] == ',' || in[i] == '.' || in[i] == '?' || in[i] == '!' || in[i] == ' ')
			{

			//	i++ ;

				j++;

				continue;
			}

			if( in[j] == ',' || in[j] == '.' || in[j] == '?' || in[j] == '!' || in[j] == ' ' )
			{

				i--;

				continue;
			}

			if( !((in[i] == in[j]) || ( char(in[i] + 32) == in[j] ) || ( char(in[j] + 32) == in[i] )) )

				check = 0;

			if( check == 0)

				break;

		}

		if( check )

			cout << a;

		else

			cout << b;


		gets(in) ;

		check = 1;

		i = 0;


	}




	return 0 ;
}