#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{

	int n;
	int q,size;
	int i,j,k;
	int D;
	double d;

	while(1)
	{

		cin >> n;

		if(n == 0)
			break;

		size = 1;

		n--;

		while(1)
		{

			q = size;

			D  = 1;

			while( D <= (q-1)*n )
			{
				d = (q*D*1.0)/(q-1);
				D = ceil(d);
			}

			if( (q*n + 1 - D) == 1)
			{
				cout << q << endl;
				break;
			}

			size++;

		}
	}
}