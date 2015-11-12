
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
#define max(a,b) a>a?a:b
#define min(a,b) a>b?b:a

vector<int> v[101];
long int dp[101];
bool death[101];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,a,b,n;
	int ca=1;

	while(cin >> n)
	{
		memset(death,false,sizeof(death));
		for(i = 0;i<n;i++)
		{
			cin >> a;
			for(j = 0;j<a;j++)
			{
				cin >> b;
				v[b].push_back(i);
			}
			if(a==0)
			death[i] = true;
		}

		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(i = 1;i<n;i++)
		{
			a = v[i].size();
			for(j = 0;j<a;j++)
			{
				//if(!death[v[i][j]])
				int b = v[i][j];
				dp[i] += dp[v[i][j]];
			}
		}
		long int ans=0;
		for(i = 0;i<n;i++)
		{
			if(death[i])
			ans += dp[i];
		}
		//cout << dp[2] << endl;
		if(ca==1)
			ca=2;
		else
			cout << endl;
		cout << ans << endl;
		for(i = 0;i<n;i++)
		{
			v[i].clear();
		}
	

	}
     return 0;
}
