#include<stdio.h>

int main(void)
{
	unsigned N1,N2;int carry = 0,hand=0,c;

	scanf("%u %u",&N1,&N2);

	
	while( !(N1==0 && N2==0))
	{


		while((N1>0) || (N2>0))
		{
			
			c = (N1%10) + (N2%10) + hand;

			if(c>9)
			{
				hand=1;

				carry++;
			}

			else

				hand = 0;

			N1 /= 10;
			N2 /= 10;
			
		
			
		}

	
		if(carry > 1)
		{


		    printf("%d carry operations.\n",carry);
		}

	    if ( carry == 1)
		{


			printf("1 carry operation.\n");
		}
		
		if(carry == 0)

		   printf("No carry operation.\n");



		 carry = 0;

		 hand = 0;

		scanf("%u %u", &N1,&N2);
	}

	return 0;
}