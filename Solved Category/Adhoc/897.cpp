#include<iostream>

using namespace std;

int res[]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,
199,311,337,373,733,919,991};
int digit_count(int n);

int main(void)
{
	int n,i,j,max;
	int check;

	while(1)
	{
		cin >> n;
		if(!n)
			break;
		if( n > 991)
		{
			cout << 0 << endl;
			continue;
		}
		i = digit_count(n);

		check = 0;

		if( i == 1)
		{
            for( j = 0;j <= 3; j++)
			{
				if( res[j] > n)
				{
					cout << res[j] << endl;
					check = 1;
					break;
				}
			}
			if( check == 0)
				cout << 0 << endl;
			max = 10;
		}
		if( i == 2)
		{
			for( j = 4;j <= 12; j++)
			{
				if( res[j] > n)
				{
					cout << res[j] << endl;
					check = 1;
					break;
				}
			}
			if( check == 0)
				cout << 0 << endl;
			max = 100;
		}
		if( i == 3)
		{
			for( j = 12;j <= 21; j++)
			{
				if( res[j] > n)
				{
					cout << res[j] << endl;
					check = 1;
					break;
				}
			}
			if( check == 0)
				cout << 0 << endl;
			max = 1000;
		}
	}

	return 0;
}

int digit_count(int n)
{
	int i = 0;
	while(n)
	{
		i++;
		n /= 10;
	}
	return i;
}