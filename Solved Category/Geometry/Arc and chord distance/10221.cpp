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
#define pi acos(-1)
int main(void)
{
	char in[5];
	double s,a,b;
	double arc,chord;
	while(cin >> s >> a >> in)
	{
		if(strcmp(in,"min")==0)
			a /= 60;
		if(a==180)
		{
			chord = 2.0*(s+6440);
			arc = pi*(s+6440);
		}
		else
		{
			if(a>180)
				a = 360-a;
			arc = (s+6440)*((a*pi)/180.0);
			b = 180-a;
			b /=2;
			chord = ((6440+s)*sin(a*(pi/180)))/sin(b*(pi/180));
		}
		printf("%.6lf %.6lf\n",arc,chord);
	}

	return 0;
}

