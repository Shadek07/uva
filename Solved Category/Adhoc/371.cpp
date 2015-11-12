#include<stdio.h>



int main()
{
	 long int num1,num2;

	 long int t,i;

	 long int tmp,t1,t2;

	 long int g;

     long int count = 0;

     long int max = 0;

	while(1)
	{
          
         scanf("%lld %lld",&num1,&num2); 
         if( num1 == 0 && num2 == 0 )
        
         break ;
         
          
           t1 = num1;

	       t2 = num2;

		if( num1 > num2 )
		{
			tmp = num1;

			num1 = num2;

			num2 = tmp;
		}


     g = num1;
	
	for( i = num1 ;i<=num2;i++)
	{
		t = i;

		

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

			g = i;
		}

		count = 0;


				
	}

	

	printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",num1,num2,g,max);

	

	

	max = 0;

	}

	

	return 0;
}
