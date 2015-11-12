#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define m1 1.0
#define m2 2.0

int main(void)
{

	int t;

	double a1,b1,a2,b2,c1,c2;
	double p1,p2,q1,q2,r1,r2;
	double d1,d2,e1,e2,f1,f2;
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double u1,v1,w1,u2,v2,w2;
	double area;

	cin >> t;

	while(t--)
	{

		cin >> a1 >> a2 >> b1  >> b2 >> c1 >> c2;

		d1 = (m1*c1)/3.0;
		d1 += (m2*b1)/3.0;

		d2 = (m1*c2)/3.0;
		d2 += (m2*b2)/3.0;

		e1 = (m1*a1)/3.0;
		e1 += (m2*c1)/3.0;

		e2 = (m1*a2)/3.0;
		e2 += (m2*c2)/3.0;

		f1 = (m1*b1)/3.0;
		f1 += (m2*a1)/3.0;

		f2 = (m1*b2)/3.0;
		f2 += (m2*a2)/3.0;

		x1 = a1;
		y1 = a2;
		x2 = d1;
		y2 = d2;
		x3 = b1;
		y3 = b2;
		x4 = e1;
		y4 = e2;
		
		u1 = y1-y2;
		v1 = x2-x1;
		w1 = x1*(y2-y1) + y1*(x1-x2);


		u2 = y3-y4;
		v2 = x4-x3;
		w2 = x3*(y4-y3) + y3*(x3-x4);

		p1 = (v1*w2 - v2*w1) / (u1*v2 - u2*v1);

		p2 = (w1*u2 - w2*u1)/(u1*v2 - u2*v1);

		x1 = b1;
		y1 = b2;
		x2 = e1;
		y2 = e2;
		x3 = c1;
		y3 = c2;
		x4 = f1;
		y4 = f2;
		
		u1 = y1-y2;
		v1 = x2-x1;
		w1 = x1*(y2-y1) + y1*(x1-x2);


		u2 = y3-y4;
		v2 = x4-x3;
		w2 = x3*(y4-y3) + y3*(x3-x4);

		q1 = (v1*w2 - v2*w1) / (u1*v2 - u2*v1);

		q2 = (w1*u2 - w2*u1)/(u1*v2 - u2*v1);

		x1 = a1;
		y1 = a2;
		x2 = d1;
		y2 = d2;
		x3 = c1;
		y3 = c2;
		x4 = f1;
		y4 = f2;
		
		u1 = y1-y2;
		v1 = x2-x1;
		w1 = x1*(y2-y1) + y1*(x1-x2);


		u2 = y3-y4;
		v2 = x4-x3;
		w2 = x3*(y4-y3) + y3*(x3-x4);

		r1 = (v1*w2 - v2*w1) / (u1*v2 - u2*v1);

		r2 = (w1*u2 - w2*u1)/(u1*v2 - u2*v1);

		area = 0.0;

		area += 0.5*(p1*(q2-r2));
		area += 0.5*(q1*(r2-p2));
		area += 0.5*(r1*(p2-q2));
		area = abs(area);

		printf("%.0lf\n",area);



	}

	return 0;
}