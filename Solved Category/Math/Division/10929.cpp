#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{

	char in[1003];

	
	int i,len,d;

	while(1)
	{
		gets(in);
		len = strlen(in);
		if( len == 1 && in[0] == '0')
			break;
        
		d = 0;
		for( i = 0; i < len ; i++)
		{
			d = d*10 + (in[i] - '0');

			d %= 11;

		}

		if( d == 0)
		{
			cout << in << " is a multiple of 11.\n";
		}

		else
		{
			cout << in << " is not a multiple of 11.\n";
		}
		


	}




	return 0;
}
