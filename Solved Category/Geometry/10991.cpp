#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
#define pi 3.141592653589793
//acos(-1)

int main(void)
{
	int t;
	double r1,r2,r3;
	double a,b,c;
	double area;
	double a1,b1,c1; //angle
	double s;
	double par1,par2,par3;
	//cout << pi << endl;
	cin >> t;
	while(t--)
	{
		cin >> r1 >> r2 >> r3;
		a = r1+r2;
		b = r1+r3;
		c = r2+r3;
		s = (a+b+c)/2.0;
		area = sqrt(s*(s-a));
		area *= sqrt((s-b)*(s-c));

		//angle calculation
		a1 = acos((b*b+c*c-a*a)/(2.0*b*c));
		b1 = acos((a*a+c*c-b*b)/(2.0*a*c));
		c1 = acos((b*b+a*a-c*c)/(2.0*b*a));
	

		//convert to degree
		a1 = (a1*180)/pi;
		b1 = (b1*180)/pi;
		c1 = (c1*180)/pi;

		par1 = (pi*r1*r1*c1)/360;
		par2 = (pi*r2*r2*b1)/360;
		par3 = (pi*r3*r3*a1)/360;

		printf("%.6lf\n",area-par1-par2-par3);
	}

	return 0;
}