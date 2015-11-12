#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(void)
{

	int n;
	int cnt = 0;

	double a1,b1,c1;

	double res;

	cin >> n;

	while(cnt < n)
	{
		cin >> a1 >> b1 >> c1;

		res = (1.0/a1 + 1.0/b1 + 1.0/c1)*(1.0/a1 + 1.0/b1 - 1.0/c1)*(1.0/a1 - 1.0/b1 + 1.0/c1)*(-1.0/a1 + 1.0/b1 + 1.0/c1);

		if(res>0.0)
		{
			res = sqrt(res);
			res = (1.0/res);
			printf("%.3f\n",res);
		}
		else
		{
			cout << "These are invalid inputs!\n";
			cnt++;
		}

	}

	return 0;
}