#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
long int dp[15];
long fact[15];
void f()
{
	int i;
	fact[1] = 1;
	for(i = 2;i <=12;i++)
	{
		fact[i] = i*fact[i-1];
	}
}
void cal()
{
	int i;
	dp[1] = 0;
	dp[2] = 1;
	for(i = 3;i <=12;i++)
	{
		dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
	}
}
int main(void)
{
	int t,n;

	cal();
	f();
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << dp[n] << "/" << fact[n] << endl;
	}
	return 0;
}