
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
#define add 5000
bool dp[10005][51];
int n,m;
int num[102];
int prefix[102];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j;
	int sum,a,s1;
	int mx,mn;
	while(cin >> n >> m)
	{
		sum = 0;
		prefix[0]=0;
		for(i=1;i<=n+m;i++)
		{
			cin >> num[i];
			sum += num[i];
			prefix[i] = prefix[i-1]+num[i];
		}
		memset(dp,false,sizeof(dp));
		//for(i=0;i<5001;i++)
		dp[add][0] = true;
		int n1 = min(n,m);
		int l1,r1;
		l1 = add;
		r1=add;
		for(i=0;i<n+m;i++)
		{
			a = num[i+1];
			if(a>=0)
			{
				int temp = r1;
				for(s1=r1;s1>=l1;s1--)
				{
					for(j=0;j<=min(i,n1);j++)
					{
						dp[s1+a][j+1] |= dp[s1][j];
						//if(dp[s1+a][j+1])
						temp = max(temp,s1+a);
					}
				}
				r1 = temp;
			}
			else
			{
				int temp = l1;
				for(s1=l1;s1<=r1;s1++)
				{
					for(j=0;j<=min(i,n1);j++)
					{
						dp[s1+a][j+1] |= dp[s1][j];
						//if(dp[s1+a][j+1])
						temp = min(temp,s1+a);
					}
				}
				l1 = temp;
			}


		}

		mx = -99999;
		mn = 999999;
		for(i=l1;i<=r1;i++)
		{
			if(dp[i][n1])
			{
				mx = max(mx,(i-add)*(sum-i+add));
				mn = min(mn,(i-add)*(sum-i+add));
			}
		}
		cout << mx << " " << mn << endl;

	}

    return 0;
}
