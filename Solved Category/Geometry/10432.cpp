#include<stdio.h>
#include<math.h>


#define pi 2.0*acos(0.0)

int main(void)
{

	 double rad,side;

	 double angle,area;
	

	while(scanf("%lf %lf",&rad,&side) == 2)
	{

		rad *= 1.0;
		side *= 1.0;
		angle = 360.0/side;
		angle *= pi;
		angle /= 180.0;

		/*angle = sin(2*pi/side);

		area = 0.5;*/
		area = sin(angle);
		area *= 0.5;
		area *= rad;
		area *= rad;

		printf("%.3lf\n",area*side);




	}


	return 0;
}