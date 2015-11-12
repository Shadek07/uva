
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
	int n;
	int ca=1;
	double A,spectator,official,R,r;
	while(cin >> n >> A)
	{
		if(n < 3)
			break;
		R = sqrt((2.0*A)/(n*sin((2.0*pi)/(n*1.0))));
		//cout << R << endl;
		r = R*cos(pi/n);
		//cout << r << endl;
		spectator = pi*R*R-A;
		official = A - pi*r*r;
		cout << "Case " << ca++ << ": ";
		printf("%.5lf %.5lf\n",spectator,official);

	}
	return 0;
}
