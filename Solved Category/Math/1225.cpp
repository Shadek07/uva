
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
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); } 
int dp[10000][10];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	dp[2][1] = 1;
	dp[2][2] = 1;
	int i,j;
	int a,b;
	for(i=3;i<10000;i++)
	{
		a = i;
		for(j=0;j<10;j++)
			dp[i][j] = dp[i-1][j];
		while(a)
		{
			b = a%10;
			dp[i][b]++;
			a /= 10;
		}
	}
	int ca;
	cin >> ca;
	while(ca--)
	{
		cin >> a;
		cout << dp[a][0];
		for(i=1;i<10;i++)
			cout << " " << dp[a][i];
		cout << endl;
	}
    return 0;
}