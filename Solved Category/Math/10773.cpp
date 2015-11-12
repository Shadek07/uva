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
	int ca = 1;
	int t;
	double d,u,v;
	double od,t1,t2;
	cin >> t;
	while(t--)
	{
		cin >> d >> v >> u;
		od = u*u - v*v;
		cout << "Case " << ca++ << ": ";
		if(od <= 0 || v == 0)
		{
			cout << "can't determine\n";
			continue;
		}
		od = sqrt(od);
		t1 = d/od;
		t2 = d/(u);
		
		t1 = fabs(t1-t2);
		printf("%.3lf\n",t1);
	}

	return 0;
}