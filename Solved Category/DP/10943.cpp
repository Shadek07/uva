
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

#define M 1000000 
long int dp[101][101];//dp[i][j] is number of ways to make i by using j numbers

int main(void)
{
	int i,j,n,k;

	for(i = 0;i<=100;i++)
	{
		for(j = 0;j<=100;j++)
		{
			dp[i][j] = 0;
		}
	}

	for(i = 0;i<=100;i++)
	{
		dp[0][i] = 1;
	}
	
	for(i = 1;i<=100;i++)
	{
		for(k = 1; k<= 100;k++)
		{
			for(j = 0;j<=i;j++)
			{
				dp[i][k] = (dp[i][k] + dp[i-j][k-1]%M)%M;
			}
		}
	}

	while(cin >> n >> k)
	{
		if(!n && !k)
			break;
		cout << dp[n][k] << endl;
	}

	return 0;
}
