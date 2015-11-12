#include<iostream>

using namespace std;

int num[10][10];

int main(void)
{
	int n,i,j,k,x;

	cin >> n;
	while(n--)
	{
		for(i = 0; i < 5; i++)
		{
			k = 2*i;
			for( j = 0; j <= i ; j++)
			{
				cin >> num[k][2*j];

			}
		}

		for( i = 1; i <= 7; i += 2)
		{
			x = (num[6][i-1] - (num[8][i-1] + num[8][i+1]))/2;
			num[8][i] = x;

		}

	

		for( i = 7; i >= 0; i--)
		{
			for( j = 0; j <= i; j++)
			{
				num[i][j] = num[i+1][j] + num[i+1][j+1];

			}
		}

		for( i = 0; i <= 8; i++)
		{
			cout << num[i][0];
			for( j = 1; j <= i; j++)
			{
				cout <<  " " << num[i][j];
			}
			cout << endl;
		}



	}
	return 0;
}