#include<iostream>
#include<cmath>

using namespace std;

#define pi 2*acos(0)

int main(void)
{

	int t,i;

	double a;
	cin >> t;

	char c;
	int r1,r2 = -1;
	while(t--)
	{
		cin >> r1;

		c = getchar();

		if( c == ' ')
		{
			cin >> r2;
		}

		if( r2 == -1)
		{
			a = r1*r1*pi;
			a /= 8;
			printf("%.4f\n",a);
			goto next;
		}
		else
		{
            i = r1 + r2;

			a = pi*(i*i - r1*r1 - r2*r2);

			printf("%.4f\n",a);


		}

next:

		r2 = -1;

	}

	return 0;
}
