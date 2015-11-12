#include<stdio.h>

int main()
{
	long int num1,num2;

	long int t,i;

	long int tmp,t1,t2;

	int count = 1;
	int max = 0;

	
    while( (scanf("%ld %ld",&num1,&num2)) == 2 )
	{


        t1 = num1;

        t2 = num2;
	

	
	

		if( num1 > num2 )
		{
			tmp = num1;

			num1 = num2;

			num2 = tmp;
		}



	
	for( i = num1 ;i<=num2;i++)
	{
		t = i;

		while(t !=1)
		{
			if( t%2 == 0)
			{
				t /=2;

				count++;
			}

			else
			{
				t = 3*t + 1;
				count++;

			}

		}

				
		if(max < count)
		{
			max = count;
		}

		count = 1;
		
	

		
	}

	printf("%d %d %d\n",t1,t2,max);

	//scanf("%ld %ld", &num1,&num2 );

	//t1 = num1;

	//t2 = num2;

	 max = 0;

	}

	

	return 0;
}
