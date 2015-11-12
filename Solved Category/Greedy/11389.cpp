
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

vector<int> morning;
vector<int> night;

int main(void)
{
	int i;
	int n,d,r;
	unsigned long ans,a;
	while(cin >> n >> d >> r)
	{
		if(!n && !d && !r)
			break;
		for(i = 0;i<n;i++)
		{
			cin >> a;
			morning.push_back(a);
		}
		for(i = 0;i<n;i++)
		{
			cin >> a;
			night.push_back(a);
		}
		sort(morning.begin(),morning.end());
		sort(night.begin(),night.end());
		ans = 0;
		for(i = 0;i<n;i++)
		{
			if(morning[i] + night[n-1-i] > d)
			{
				ans += r*(morning[i] + night[n-1-i] - d);
			}
		}
		cout << ans << endl;
		morning.clear();
		night.clear();
	}
	return 0;
}