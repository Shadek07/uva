
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
#include <bitset>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define eps 1e-9
#define PI acos(0)
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	
	//idea from competitive programming

	double l,w,r,arc,half_l,half_w,theta;
	double lo,hi;
	int a,b;
	int ca=1;
	double expected_arc;
	char c;
	while(cin >> a >> c >> b)
	{
		lo = 0.0;
		hi = 400.0;
		while(fabs(hi-lo)>eps)
		{
			l = (lo+hi)/2;
			w = b*l/a;
			expected_arc = (400.0-2*l)/2;
			half_l = 0.5*l;
			half_w = 0.5*w;
			r = sqrt(half_l*half_l + half_w*half_w);
			theta = 2*atan(half_w/half_l)*180/PI;
			arc = theta/360.0*2*PI*r;
			if(arc>expected_arc)
				hi = l;
			else
				lo = l;
		}

		cout << "Case " << ca++;
		printf(": %.12f %.12f\n",l,w);

	}
     return 0;
}