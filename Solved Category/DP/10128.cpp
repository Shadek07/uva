
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
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

long long int dp[14][14][14];

long long int calc(int n,int l,int r)
{
	if(n==1)
		return (l==1&&r==1)?1:0;
	if(l<0 || r< 0)
		return 0;
	long long int &res = dp[n][l][r];
	res = calc(n-1,l-1,r);  //placing smallest man in leftmost position
	res += calc(n-1,l,r-1); //placing smallest man in rightmost position

	//for other (n-2) positions, smallest man can't be seen from either side
	res += (n-2)*calc(n-1,l,r);
	return res;

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t;
	int n,a,b;
	cin >> t;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%d %d %d",&n,&a,&b);
		if(a>n || b > n)
		{
               cout << 0 << endl;
               continue;
        }
        if(dp[n][a][b] != -1)
        {
              cout << dp[n][a][b] << endl;
              continue;
        }
		
		cout << calc(n,a,b) << endl;
	}
    
	return 0;
}
