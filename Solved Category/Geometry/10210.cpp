
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
#include<stack>

using namespace std;
#define PI acos(-1)
#define div PI/180 
int main(void)
{
	double x1, y1, x2, y2  ,CMD, ENF;
	double b,a;
	while(cin >> x1 >> y1 >> x2 >> y2 >> CMD >> ENF)
	{
		b = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		a = b/tan(CMD*div);
		a += b/tan(ENF*div);
		printf("%.3lf\n",a);
	}
	return 0;
}