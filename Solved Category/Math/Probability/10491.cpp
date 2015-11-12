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

int main(void)
{
	double cow,car,show,t;
	double ans;
	while(cin >> cow >> car >> show)
	{
		t = cow+car;
		ans = (cow/t)*(car/(t-1-show));
		ans += (car/t)*((car-1)/(t-1-show));
		printf("%.5lf\n",ans);
	}
	return 0;
}