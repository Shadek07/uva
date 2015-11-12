#include<iostream>
#include<cmath>

using namespace std;

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


		double t1;


		if( g != 0.0)
			cout << "(";
		cout << "x";
		if( g != 0.0)
		{
			if( g > 0.0) cout << " + ";
			else 
			{
			   cout << " - ";
			   
			   
			}

			t1 = fabs(g);

			if( t1 != 0.0)
			printf("%.3f",t1);
		}

		if( g != 0.0)
		{
		    cout << ")";
		}

		cout << "^2 + ";

		if( f != 0.0)
			cout << "(";

		cout << "y";
		if( f != 0.0)
		{
			if( f > 0.0) cout << " + ";
			else 
			{
				cout << " - ";
				
			}
		}

		t1 = fabs(f);
		if( t1 != 0.0)
		printf("%.3f",t1);

		if( f != 0.0)
			cout << ")";
		cout << "^2 = ";

		printf("%.3f^2\n",rad);

//x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0

		cout << "x^2 + y^2";

		if( g != 0.0)
		{
			if( g > 0.0)
				cout << " + ";
			else
				cout << " - ";

			t1 = 2.0*fabs(g);

		    printf("%.3fx ",t1);
		}

		

		if( f != 0.0)
		{
			if( f > 0.0)
				cout << "+ ";
			else
				cout << "- ";

			t1 = 2.0*fabs(f);

			printf("%.3fy ",t1);
		}

		if( c > 0.0)
			cout << "+ ";
		else
			cout << "- ";
		t1 = fabs(c);
		printf("%.3f = 0\n",t1);


		cout << endl;

	}

	return 0;
}