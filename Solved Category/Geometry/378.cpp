#include<iostream>
#include<cmath>

using namespace std;



int main(void)
{
	int t;

	double t1;

	double x1,y1,x2,y2,x3,y3,x4,y4;
	double x,y;
	double a1,b1,c1,a2,b2,c2;
	double m1,m2;
	double d1;

	cin >> t;

	cout << "INTERSECTING LINES OUTPUT\n";

	while(t--)
	{
		cin >> x1 >> y1>>x2>>y2>>x3>>y3>>x4>>y4;

		m1 = -1.0;
		m2 = -1.0;

		if(abs(x1-x2) != 0)
		{
			m1 = (y1-y2)/(x1-x2);

		}

		if(abs(x3-x4) != 0)
		{
			m2 = (y3-y4)/(x3-x4);

		}

		a1 = y1-y2;
		b1 = x2-x1;
		c1 = x1*(y2-y1) + y1*(x1-x2);


		a2 = y3-y4;
		b2 = x4-x3;
		c2 = x3*(y4-y3) + y3*(x3-x4);

		

		

		if( m1 == m2)   //if parrallel or in the same line
		{
			//int t1 = gcd(abs(a1),abs(a2));

			if(abs(a1) > abs(a2))
			{
				t1 = abs(a1) / abs(a2);
			    a1 /= t1;
			    b1 /= t1;
			    c1 /= t1;
			}
			else
			{
				t1 = abs(a2) / abs(a1);

			   a2 /= t1;
		       b2 /= t1;
			   c2 /= t1;
			}

			d1 = abs(c1-c2);
			
			if(d1 == 0.0)
			{
				cout << "LINE\n";
			}
			else
			{
				cout << "NONE\n";
			}

		}
		else
		{
			x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);

			y = (c1*a2 - c2*a1)/(a1*b2 - a2*b1);

			printf("POINT %.2f %.2f\n",x,y);

		}

	}

	cout << "END OF OUTPUT\n";

	return 0;
}
