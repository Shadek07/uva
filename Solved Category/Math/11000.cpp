#include<iostream>

using namespace std;

int main(void)
{
	int N;
	unsigned long int F,M;
	int i;
	int p,q;

	while(1)
	{
		cin >> N;

		if( N == -1)
			break;
		F = 0;
		M = 0;
		for( i = 1; i <= N; i++)
		{
			if( i == 1)
			{
				M = 1;
				p = F;
				q = M;
				continue;
			}

			

			F = q;

		    M++;

			if( p >= 0)
			{
				M += p;
			}

			p = F;
			q = M;


		
		}

		cout << M << " " << M + F + 1<< endl;
	}

	return 0;
}