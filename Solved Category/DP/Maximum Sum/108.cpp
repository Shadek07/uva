#include<iostream>

using namespace std;
int N;
int input[100][101];
int sum[100][101];

int arr[101];

int find_max()
{
	int max, suffix,i;

	max = suffix =  0;

	for( i = 0; i < N; i++)
	{
		if(suffix + arr[i] > max)
		{
			max = suffix + arr[i];
			suffix = max;
		}
		else if(suffix + arr[i] > 0)
		{
			suffix += arr[i];
		}
		else
		{
			suffix = 0;
		}
	}

	return max;

}

int main(void)
{
	int i,j,k;
	
	cin >> N;

	for( i = 0; i < N; i++)
	{
		for( j = 0; j < N; j++)
		{
			cin >> input[i][j];
		}
	}

	for( j = 0; j < N; j++)
	{
		sum[0][j] = input[0][j];

		for( i = 1; i < N; i++)
		{
			sum[i][j] = sum[i-1][j] + input[i][j];

		}
	}

	int max;

	max = -100000;

	for( i = 0; i < N ; i++)
	{
		for( k = 0; k < N; k++)
		{
			arr[k]  =  sum[i][k];
		}

		k = find_max();
		if( k > max)
			max = k;
	}

	for( i = 1; i < N-1; i++)
	{
		for( j = 0; j < N; j++)
		{
			arr[j] = input[i][j];
		}

		k = find_max();
		if(k > max)
			max = k;

		for( j = i+1; j < N; j++)
		{
			for( k = 0; k < N; k++)
			{
				arr[k] = sum[j][k] - sum[i-1][k];
			}

				k = find_max();
			if(k > max)
				max = k;
		}
	}
	
	cout << max << endl;

	return 0;
}