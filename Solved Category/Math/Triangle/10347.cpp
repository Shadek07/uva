#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{

	double a,b,c,i,j,k;

	while(cin >> a >> b >> c)
	{
		i = 2*(a*a*b*b + b*b*c*c + c*c*a*a);
		j = pow(a,4.0) + pow(b,4.0) + pow(c,4.0);
		if( i <= j)
		{
			cout << "-1.000" << endl;
			continue;
		}

		k = sqrt(i-j);
		k /= 3;
		printf("%.3lf\n",k);
	}


	return 0;
}