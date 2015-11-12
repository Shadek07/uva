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
	double a,ans;
	while(cin >> a)
	{
		ans = sin(108*div)/sin(63*div);
		ans *= a;
		printf("%.10lf\n",ans);

	}
	return 0;
}