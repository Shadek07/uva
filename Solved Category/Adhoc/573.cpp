
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

int main(void)
{
	double h,u,d,f,up;
	int cnt;
	double a,b,c;
	bool succ;
	double pr;
	while(cin >> h >> u >> d >> f)
	{
		if(h == 0)
			break;
		cnt = 0;
		pr=  0;
		a  = (u*f)/100;
		up = u;
		if(u>h)
		{
			cout << "success on day 1\n";
			continue;
		}
		if(d> u)
		{
			cout << "failure on day 1\n";
			continue;
		}
		pr = u-d;
		cnt = 1;
		up -= a;
		while(1)
		{
			cnt++;
			
			if(up>0)
				pr += up;
			if(pr >= h)
			{
				succ = true;
				break;
			}
			pr -= d;
			if(pr < 0)
			{
				succ = false;
				break;
			}
			up -= a;			
		}
		if(succ)
		{
			cout << "success on day " << cnt<< "\n";
		}
		else
		{
			cout << "failure on day " << cnt << "\n";
		}
	}
	return 0;
}