
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
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

vector<int> two_rect(int lastr,int lastc,int c)
{
	vector<int> ans(4,0);
	if(c == 1)//if upper left corner is white
	{
		ans[0] = lastr/2;
		if(lastr%2)
			ans[0]++;
		ans[1] = lastc/2;
		if(lastc%2)
			ans[1]++;
		ans[2] = lastr/2;
		ans[3] = lastc/2;
	}
	else
	{
		ans[0] = lastr/2;
		if(lastr%2)
			ans[0]++;
		ans[1] = lastc/2;
		ans[2] = lastr/2;
		ans[3] = lastc/2;
		if(lastc%2)
			ans[3]++;

	}

	return ans;

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int m,n,c;
	int lastr,lastc;
	vector<int> ans;
	while(cin >> n >> m >> c)
	{
		if(!n && !m && !c)
			break;
		unsigned long int res=0;
		lastr = n-8+1;
		lastc = m-8+1;
		if(c==1)//bottom right corner is white
		{
			if((m%2==0 && n%2 == 0)	||(m%2==1 && n%2 == 1))
				ans = two_rect(lastr,lastc,1);
			else
				ans = two_rect(lastr,lastc,0);
		}
		else
		{
			if((m%2==0 && n%2 == 1)	||(m%2==1 && n%2 == 0))
				ans = two_rect(lastr,lastc,1);
			else
				ans = two_rect(lastr,lastc,0);
		}

		res = ans[0]*ans[1] + ans[2]*ans[3];
		cout << res << endl;



	}
     return 0;
}