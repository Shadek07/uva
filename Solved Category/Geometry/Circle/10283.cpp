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
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define pi acos(-1)
#define div pi/180

int main(void)
{
	int R,n;
	double r,I,E;
	//double 
	while(scanf("%d %d",&R,&n)==2)
	{
		if(n ==1)
		{
			printf("%.10f %.10lf %.10lf\n",R*1.0,0,0);
			continue;
		}
		r = R*sin(pi/n);
		r /= (1+sin(pi/n));
		printf("%.10f",r);
		
		//I = n*(r*(R-r)*cos(pi/n) - r*r*(pi-2*pi/n)/2);
		I = n*(r*sqrt((R-r)*(R-r)-r*r) - r*r*(pi-2*pi/n)/2);
		printf(" %.10f",I);
		E = pi*R*R - n*pi*r*r - I;
		printf(" %.10f\n",E);

	}
	return 0;
}