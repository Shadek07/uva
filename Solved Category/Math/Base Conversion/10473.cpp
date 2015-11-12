#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

int main ()
{
	long n;
	char a [20];
	a [1] = ' ';

	strcpy(a,"1050");
	n = strtol(a,NULL,6);
	cout << n << endl;

	while (gets (a)) {

		if ( a [0] == '0' && a [1] == 'x' ) {
			n = strtol (a, NULL, 16);
			printf ("%ld\n",n);
		}

		else 
		{
			n = atoi (a);
			if ( n < 0 )
				return 0;
			printf("0x%X\n", atoi (a));
		}
		a [1] = ' ';
	}

	return 0;
}
