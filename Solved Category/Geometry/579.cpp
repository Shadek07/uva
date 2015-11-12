#include<stdio.h>

int main( void)

{
	double H = 0,M = 0;

	double g,k,l;

	

	char d = ' ' ;

	

    scanf("%lf %c %lf",&H,&d,&M);

	while( !((H == 0.0) && (M == 0.0)) )
	{
		k =  H ;

		l = M ;

	


		g = (k*5.000) + (l/12.000) - l;

		g = g*(6.000);

		if( g < 0.0)

			g = -g;
		
		if( g > 180.000 )

			g = 360.000 - g;

		printf("%.3lf",g);

		printf("\n");

		scanf("%lf%c%lf",&H,&d,&M);


		



	}

	

	




	return 0;
}
