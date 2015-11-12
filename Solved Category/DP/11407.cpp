#include<iostream>
#include<cstdio>
#include<cmath>

#define min(a,b) a<b?a:b

using namespace std;
int dp[10002];

void calculate()
{
	int i,j,mn;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;

	for(i = 5;i <= 10000;i++)
	{
		mn = 999999;
		for(j = 1;j*j <= i;j++)
		{
			mn = min(mn,dp[i-j*j]+1);
		}

		dp[i] = mn;

	}
}
int main(void)
{

	int t,i;

	calculate();

	//cout << dp[10000] << endl;

	cin >> t;

	while(t--)
	{
		cin >> i;

		cout << dp[i] << endl;
	}

	return 0;
}