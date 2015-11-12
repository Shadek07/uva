
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
#define M 1000000007
int n,m;
long int dp[1<<11][101][11]; //dp[bitmask][counter][lastdigit]

long int solve(int digit,int cnt,int bitmask)
{
	int i;
	int next;
	long int a,b;
	if(cnt == m)
	{
		if(bitmask == (1<<n)-1)
			return 1;
		else
			return 0;
	}

	if(dp[bitmask][cnt][digit] != -1)
		return dp[bitmask][cnt][digit];
	if(cnt < m)
	{
		next = digit-1;
		(bitmask == (1<<n)-1)?a = 1:a=0;
		if(next>=0)
		{
			a = a + solve(next,cnt+1,bitmask|(1<<next))%M;
		}
		b=0;
		next = digit+1;
		if(next<m)
		{
			b = solve(next,cnt+1,bitmask|(1<<next))%M;
		}

		return dp[bitmask][cnt][digit] = (a+b)%M;
	}

	//return 0;

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,k;
	long int ans;
	cin >> t;
	while(t--)
	{
		scanf("%d %d",&n,&m);
		ans = 0;
		if(m<n)
		{
			cout << ans << endl;
			continue;
		}
		else if(m == n)
		{
			cout << 1  << endl;
			continue;

		}
		for(i = 0;i<=(1<<n)-1;i++)
		{
			for(j = 0;j<=m;j++)
				for(k = 0;k<m;k++)
				dp[i][j][k] = -1;
		}
		for(i = n-1;i>=1;i--)
		{
			ans = (ans + solve(i,1,1<<i)%M)%M;
		}
		for(i = 0;i<=(1<<n)-1;i++)
		{
			for(j = 0;j<=m;j++)
				for(k = 0;k<m;k++)
				dp[i][j][k] = -1;
		}

		cout << ans%M << endl;
	}
    
	return 0;
}

