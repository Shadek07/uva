#include<iostream>
#include<cmath>

using namespace std;

#define pi 3.141592653589793

int main(void)
{
	double x1,y1,x2,y2,x3,y3,p,q,r,g,f,k,c,rad;

	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		p = x1*x1 + y1*y1;
		q = x2*x2 + y2*y2;
		r = x3*x3 + y3*y3;

		k = 4.0*(x1-x2)*(y2-y3) - 4.0*(y1-y2)*(x2-x3);

		g = (2.0*(q-r)*(y1-y2)-2.0*(p-q)*(y2-y3))/k;

		f = (2.0*(p-q)*(x2-x3)-2.0*(q-r)*(x1-x2))/k;

		c = -(p+2.0*g*x1+2.0*f*y1);

		rad = sqrt(g*g + f*f - c);

	//	(x - 3.000)^2 + (y + 2.000)^2 = 5.000^2

		printf("%.2f\n",2*pi*rad);

	

	}

	return 0;
}