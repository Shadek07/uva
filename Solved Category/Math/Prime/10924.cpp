#include<iostream>
#include<cstring>

using namespace std;

int prime(int a);

int main()
{

	char arr[21]; // max letter is 20

	int sum = 0;

	int len; // determining length

	char ch, p ;

	int j = 0 ,i = 0;

	int prim = 0;

	//cout << ((int) p  - 38);

   

	while( (ch = getchar())!= EOF)
	{
		if( ch != '\n')
		{
			arr[i++] = ch;
			
		}

		else
		{
			arr[i] = '\0';

			len =  strlen(arr);

			for(int k = 0;k < len;k++)
			{
				p = arr[k];

				if(p >= 'a' && p <= 'z')
				{
					sum = sum + ((int) p  - 96);
				}

				if( p>='A' && p<='Z')
				{
					sum = sum + ((int) p  - 38);
				}
			}
			
			
			prim = prime( sum);

			if( prim == 0)
			{
				cout << "It is not a prime word."<< endl;
			}

			if( prim == 1)

				cout << "It is a prime word."<< endl;
			i = 0;

		   sum  = 0;



		}
		
	
	}


	return 0;
}
		


int prime(int a)
{
	int i;

	int check = 1;

	for( i = 2; i <= a/2 ; i++)
	{
		if((a % i) == 0)
		{
			check = 0;
		}
	}

	return check;
}