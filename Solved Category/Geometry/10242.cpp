#include<iostream>

using namespace std;

int main(void)
{

	double x1,y1,x2,y2,x3,y3,x4,y4;

	double a1,b1,a2,b2,a3,b3;

	while(cin >> x1>> y1>> x2 >> y2>> x3>> y3>> x4 >> y4)
	{
		if( x1 == x3 && y1 == y3)
		{
			a1 = x2;
			b1 = y2;
			a2 = x1;
			b2 = y1;
			a3 = x4;
			b3 = y4;

		}
		if( x1 == x4 && y1 == y4)
		{
			a1 = x2;
			b1 = y2;
			a2 = x1;
			b2 = y1;
			a3 = x3;
			b3 = y3;

		}

		if( x2 == x3 && y2 == y3)
		{
			a1 = x1;
			b1 = y1;
			a2 = x2;
			b2 = y2;
			a3 = x4;
			b3 = y4;

		}

		if( x2 == x4 && y2 == y4)
		{
			a1 = x1;
			b1 = y1;
			a2 = x2;
			b2 = y2;
			a3 = x3;
			b3 = y3;

		}

		printf("%.3lf %.3lf\n",a1 + a3 - a2 , b1 + b3 - b2 );


	}


	return 0;
}