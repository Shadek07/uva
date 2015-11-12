
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

int len,mx;
int n,mw;
//int que[101];
int wi[400];
int dp[400][10005];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,a;
	cin >> t;
	int ca=1;
	int i,j;
	while(t--)
	{
		cin >> len;
		len *= 100;
		len = 2*len;
		int sum=0;
		i=1;
		j=0;
		bool got=false;
		while(cin >> a && a)
		{
			if(got == false && a <= len/2 && sum+a<=len)
			{				
				sum += a;
			}
			else if(!got)
			{
				j = i-1;
				got = true;
			}
			wi[i] = a;
			i++;
		}

		if(got == false && j==0 && i!= 1)
			j = i-1;
		n=j;
		mw = len/2;
		for(i=0;i<=n;i++)
			dp[i][0] = 0;
		for(i=0;i<=mw;i++)
			dp[0][i] = 0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=mw;j++)
			{
				if(wi[i] > j)
				{
					dp[i][j] = dp[i-1][j];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
					if(dp[i-1][j-wi[i]]+wi[i]> dp[i][j]) //take i'th car in port side
					{
						dp[i][j] = dp[i-1][j-wi[i]]+wi[i];
					}
				}
			}
		}

		i = n;
		j = mw;
		vector<bool> ind(205);
		while(i>0 && j > 0)
		{
			if(dp[i][j] != dp[i-1][j]) //i'th car was placed in port side
			{
				j -= wi[i];
				ind[i] = true;
			}
			else
				ind[i] = false;
			i--;
		}

		sum = 0;
		vector<string> ans;
		int s1=0,s2=0;
		bool not_taken=false;
		for(i=1;i<=n && sum+wi[i]<= 2*mw;i++)
		{
			if(ind[i] == true&& s1+wi[i] <= mw)
			{
				ans.push_back("port\n");
				s1 += wi[i];
				sum += wi[i];
			}
			else if(s2+wi[i]<=mw)
			{
				ans.push_back("starboard\n");
				s2 += wi[i];
				sum += wi[i];
			}
			else
			{
				not_taken=true;
				break;
			}
			
		}

		if(ca==1)
			ca=2;
		else
			cout << endl;
		cout << ans.size() << endl;
		j = ans.size();
		i=0;
		//cout << mw << endl;
		//cout << s1 << " " << s2 << endl;
		while(i<j)
		{
			cout << ans[i];
			i++;
		}
		ans.clear();


	}
     return 0;
}