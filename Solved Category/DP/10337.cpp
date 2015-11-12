
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

int w[10][1002];
int dp[10][1002];
int m;
int dy[] = {1,0,-1};

#define min(a,b) a<b?a:b

long int solve(int h,int x)
{
	if(h == 0 && x == m)
	{
		return dp[h][x]=0;
	}
	long int mn = 10010009;
	if(dp[h][x] != 10010009)
		return dp[h][x];
	if(h>0)
		mn = min(mn,20-w[h][x]+solve(h-1,x+1));
	if(h<9)
		mn = min(mn,60-w[h][x]+solve(h+1,x+1));
	if(x+1 <= m)
		mn = min(mn,30-w[h][x]+solve(h,x+1));
	return dp[h][x] = mn;

}

int main(void)
{
	int t;
	int i,j,k;
	cin >> t;
	long int x;
	while(t--)
	{
		cin >> x;
		x /= 100;
		m = x;
		x--;
		
		for(i = 9;i>=0;i--)
		{
			for(j =0;j<=x;j++)
			{
				cin >> w[i][j];
			}
		}

		for(i = 0;i<=9;i++)
		{
			for(j = 0;j<=x+1;j++)
			{
				dp[i][j] = 10010009;
			}
		}

		long int mn;
		mn = 10010009;
		mn = solve(0,0); //solve(currentHeight,currentX) //currentX is not travelled
		cout << mn << endl<<endl;
	}
	return 0;
}