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

bool ch[62][62];
unsigned long long int dp[62][62];
char in[62];

unsigned long long int solve(int i,int j)
{
	if(ch[i][j])//already calculated
		return dp[i][j];
	if(i == j)
	{
		ch[i][j] = true;
		dp[i][j] = 1;
		return 1;
	}

	unsigned long long int a,b,c;
	a = b = c = 0;
	if(in[i] == in[j])
	{
		if(i+1<=j)
			a = solve(i+1,j);
		if(j-1>= i)
			b = solve(i,j-1);
		ch[i][j] = true;
		dp[i][j] = a+b+1;
		return dp[i][j];
	}
	else
	{
		if(i+1<=j)
			a = solve(i+1,j);
		if(j-1>= i)
			b = solve(i,j-1);
		if(i+1<=j-1)
			c = solve(i+1,j-1);
		ch[i][j] = true;
		dp[i][j] = a+b-c;
		return dp[i][j];

	}

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,len,i,j;
	cin >> t;
	getchar();
	unsigned long long int ans;
	while(t--)
	{
		gets(in);
		len = strlen(in);
		memset(ch,false,sizeof(ch));
		ans = solve(0,len-1);
		cout << ans << endl;
	}

     return 0;
}
