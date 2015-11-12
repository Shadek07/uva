#include<stdio.h>
#include<math.h>

int main()
{
	int a,b;

	int i;

	double c;
	int total = 0;


	scanf("%d %d", &a,&b);

	while( (a != 0) && (b != 0))
	{
		for( i = a ;i <= b;i++)
		{
			c = sqrt(i);

			if( (c - (int) c) == 0.0)
			{
				total++;
			}
		}

		printf("%d\n",total);

		total = 0;

		scanf("%d %d",&a,&b);
	}


	return 0;
}
