#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	 int n;
	 long int num[20];
	 int ca = 1;
	 int taken = 0;
	 long int max,i,j;
	while( (scanf("%d",&n)) == 1 )
	{
		for(i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		getchar();
		getchar();
		taken = 0;

		long int res = 0;
		for(i = 0; i < n; i++)
		{
			max = 1;

			for( j = i; j < n; j++)
			{
				max *= num[j];
				if(max > res)
					res = max;
			}

		}


		cout << "Case #" <<ca++<<": The maximum product is ";
		cout << res;
		cout << ".\n\n";
		
	}

	return 0;
}