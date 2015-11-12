
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
#include<list>

using namespace std;

long int val[101];
long int dp[101][101];
bool ch[101][101];
long int sum[101];
#define max(a,b) a>b?a:b

int main(void)
{
	int n;
	int i,j,k;
	long int a,b;
	int x,y;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin >> n)
	{
		if(n == 0)
			break;

		for(i = 0;i<n;i++)
			cin >> val[i];
		memset(ch,false,sizeof(ch));

		for(i = 0;i<n;i++)
			dp[i][i] = val[i];

		sum[0] = val[0];
		for(i = 1;i<n;i++)
			sum[i] = val[i] + sum[i-1];

		for(k = 1;k<n;k++)
		{
			for(i = 0;i<n;i++)
			{
				if(i+k < n)
				{
					j = i+k;
					dp[i][j] = max(val[i]-dp[i+1][j],val[j]-dp[i][j-1]);
					for(x = 1; x<= j - i;x++)
					{
						a = sum[i+x];
						if(i>0)
							a -= sum[i-1];
						b = sum[j];
						if(j-x>0)
							b -= sum[j-x-1];
						a -= dp[i+x+1][j];
						b -= dp[i][j-x-1];

						a = max(a,b);
						dp[i][j] = max(dp[i][j],a);
					}

				}
			}
		}

		cout << dp[0][n-1] << endl;



	}
	return 0;
}
