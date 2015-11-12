#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{

	int size;

	int mat[10][10];
	int i,j,k,l,m,n,cn = 1,sum;

	while(1)
	{
		cin >> size;
		if( !size)
			break;

		for( i = 0; i < size; i++)
		{
			for( j = 0; j < size; j++)
			{
				cin >> mat[i][j];
			}
		}

		cout << "Case " << cn++ << ": ";

		i = 0;
		j = 0;
		k = size-1;

		sum = 0;

		int q;

		if( size %2 == 0)
              q = size/2;
		else
			q = size/2 + 1;

		for( l = 0; l < q; l++)
		{

			//upper

			for(m = j; m <= j + k ; m++)

				sum += mat[i][m];

			//lower

			if( k != 0)
			{

				for(m = j; m <= j + k ; m++)

					sum += mat[i+k][m];
			}

			//left

			for(m = i+1; m < i + k ; m++)

				sum += mat[m][j];

			//right

			for(m = i+1; m < i + k ; m++)

				sum += mat[m][j+k];

			cout << sum;

			if( l < q-1)
				cout << " ";
			else if( l == q-1)
				cout << endl;


			i++;
			j++;
			sum = 0;
			k -= 2;
		}


	}


	return 0;
}