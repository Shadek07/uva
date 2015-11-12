
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;

#define pi acos(-1)

int main(void)
{
	double a,b,c;
	double triangle,outer,inner,R,cosA,sinA,s;
	//cout << pow(cos(0),2) + pow(sin(0),2.0) << endl;
	while(cin >> a >> b >> c)
	{
		cosA = (b*b+c*c-a*a)/(2.0*b*c);
		sinA = sqrt(1-cosA*cosA);
		R = (a*1.0)/(2*sinA);
		s = (a+b+c)/2.0;
		triangle = sqrt(s*(s-a)*(s-b)*(s-c));
		outer = pi*R*R;
		double r = triangle/s;
		inner = pi*r*r;
		printf("%.4lf %.4lf %.4lf\n",outer-triangle,triangle-inner,inner);

	}
	return 0;
}

