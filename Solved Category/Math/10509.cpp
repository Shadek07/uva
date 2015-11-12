#include<iostream>
#include<cmath>

using namespace std;


int main(void)
{

	double a,b,c,d,dx;
//k = exp(log(p)/n);
	while(1)
	{
		cin >> a;

		if( a == 0.0)
			break;

        b = floor(pow(a, 1.0/3.0)+0.0000000001);
		//b = floor(exp(log(a)/3);

		dx = (a-b*b*b)/3.0;

		dx /= b;

		dx /= b;

		b += dx;


		printf("%.4f\n",b);
	

	}


	return 0;
}