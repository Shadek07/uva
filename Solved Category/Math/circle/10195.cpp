#include<string.h>
#include<math.h>
#include<stdio.h>



int main(void)
{
	double a,b,c,s,r;

	while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
	{


		 if ( b + c <= a || c + a <= b || a + b <= c ) {
            printf ("The radius of the round table is: 0.000\n");
            continue;
        }
		s = (a+b+c)/2.0;

		r = (s-a);
		r = sqrt(r);
		r *= sqrt(s-b);
		r *= sqrt(s-c);
		r /= sqrt(s);
		printf("The radius of the round table is: %.3lf\n",r);
	}

	return 0;
}
