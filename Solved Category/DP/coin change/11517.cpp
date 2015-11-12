
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

#define INF 999999
#define min(a,b) a<b?a:b

int main(void)
{
	int t;
	int i,j,c;
	cin >> t;
	int price,n,v;
	int coin[101];
	int dp[30010]; //dp[i] is number of coins to make i
	int mx;
	while(t--)
	{
		cin >> price;
		cin >> n;
		mx = -1;
		for(i = 0;i<n;i++)
		{
			cin >> coin[i];
			if(coin[i] > mx)
				mx = coin[i];
		}
		dp[0] = 0;
		for(i = 1; i<= price+mx;i++)
		{
			dp[i] = INF;
		}

		for(i = 0;i<n;i++)
		{
			c = coin[i];
			for(v = price + mx;v>=0;v--)
			{
				if(dp[v] < INF)
				{
					dp[v+c] = min(dp[v+c],dp[v]+1);
				}
			}
		}

		for(i = price;;i++)
		{
			if(dp[i] < INF)
			{
				cout  << i << " " << dp[i] << endl;
				break;
			}
		}


	}
	return 0;
}