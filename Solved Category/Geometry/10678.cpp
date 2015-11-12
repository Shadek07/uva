#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define pi 2*acos(0)

int main(void)
{
	int l,d;
	int t;
	cin >> t;
	double a,b,area;
	while(t--)
	{
		cin >> d >> l;
		a = l*1.0/2;
		double c = d*1.0/2;
		b = sqrt(a*a - c*c);
		printf("%.3lf\n",pi*a*b);

	}
	return 0;
}