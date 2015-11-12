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
	double D,V,a,b,d;
	//cout << pi << endl;
	while(cin >> D >> V)
	{
		if(D == 0.0 && V == 0.0)
			break;
		a = pow(D,3.0);
		a -= (6/pi)*V;
		d = pow(a,1.0/3.0);
		printf("%.3lf\n",d);
	}

	return 0;
}
