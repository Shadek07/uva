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
	int L,f;
	double v,vl;
	while(cin >> L >> f && L && f)
	{
		v = sqrt(2.0*L*f);
		vl = (v*3600)/(2.0*L);
		printf("%.8lf %.8lf\n",v,vl);
	}
	return 0;
}