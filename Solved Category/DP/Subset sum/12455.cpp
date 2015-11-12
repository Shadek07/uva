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

bool dp[22][1002];
//1 10 2 1 10
int main(void)
{
	int t;
	cin >> t;
	int i,j,k,a,b;
	int l[21];
	int B;
	int n;
    long int sum;
	while(t--)
	{
		cin >> B;
		cin >> n;
		sum = 0;
		for(i = 1;i<=n;i++)
		{
			cin >> l[i];
			sum += l[i];
		}
		if(B>sum)
		{
			cout << "NO\n";
			continue;
		}
		if(B==0 && n != 0)
		{
			cout << "YES\n";
			continue;
		}
		
		dp[1][0] = true;
		for(i = 1;i<=B;i++)
		{
			if(i == l[1])
				dp[1][i] = true;
			else
				dp[1][i]= false;
		}

		for(i = 2;i<=n;i++)
		{
			for(j = 0;j<=B;j++)
			{
				dp[i][j] = dp[i-1][j];
				if(j-l[i] >=0)
					dp[i][j] |= dp[i-1][j-l[i]];
			}
		}

		if(dp[n][B])
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}