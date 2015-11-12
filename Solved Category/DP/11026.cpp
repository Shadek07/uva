
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

long long int m,n;
long long int in[1001];

long long int dp[1001][1001];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		dp[0][0] = 0;
		for(i = 0;i<n;i++)
			cin >> in[i];
		
		dp[0][0] = in[0]%m;
		
		for(j = 1;j<n;j++)
		{
			for(i = 0;i<=j;i++)
			{
				if(i == 0)
					dp[j][i] = (dp[j-1][i] + in[j])%m;
				else
					dp[j][i] = (dp[j-1][i] + ((dp[j-1][i-1]%m)*in[j]%m)%m)%m;
			}
		}
		long int mx = -1;
		for(i = 0;i<n;i++)
			if(dp[n-1][i] > mx)
				mx = dp[n-1][i];

		cout << mx << endl;


	}
     return 0;
}