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
	int a,b,c,d,e;
	long ans;

	while(1)
	{
		cin >> a >> b >> c >> d >> e;
		if(!a && !b && !c && !d && !e)
			break;
		ans = 1;
		ans *= (a*b*c*d*d*e*e);
		cout << ans << endl;
	}
	return 0;
}