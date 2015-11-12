#include<iostream>

using namespace std;


int main(void)
{
	int n;
	int i,j;

	while(cin >> n && n != 0)
	{
		if( n == 1 || n == 2)
		{
			cout << n << endl;
			continue;
		}

		for( i = 2; ; i*= 2)
		{
			if( n > i && n <= i*2)
			{
				j = n - i;
				cout << j*2 << endl;
				break;
			}
		}
	}

	return 0;
}