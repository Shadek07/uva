
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

using namespace std;
const int MAXL = 1000+5;
char str[MAXL];
int dp[MAXL][MAXL], p[MAXL][MAXL];
int DP(int x, int y)
{
	int a,b;
    if (x >= y)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (str[x] == str[y])
	{
        dp[x][y] = DP(x+1, y-1), p[x][y] = 0;
		return dp[x][y];
	}
	else
	{
		a = DP(x+1, y);
		b = DP(x,y-1);
		if(a<=b)
		{
			dp[x][y] = a+1;
			p[x][y] = 1;
			return dp[x][y];
		}
		else
		{
			dp[x][y]  =b+1;
			p[x][y] = -1;
			return dp[x][y];
		}

	}
    
    
}
void Print(int x, int y)
{
    if (x > y)
        return;
    if (x == y)
        printf("%c", str[x]);
    else if (p[x][y] == 0)
        printf("%c", str[x]), Print(x+1, y-1), printf("%c", str[x]);
    else if (p[x][y] == 1)
        printf("%c", str[x]), Print(x+1, y), printf("%c", str[x]);
    else if (p[x][y] == -1)
        printf("%c", str[y]), Print(x, y-1), printf("%c", str[y]);
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        memset(dp, -1, sizeof(dp));
        printf("%d ", DP(0, len-1));
        Print(0, len-1);
        printf("\n");
    }
    return 0;
}