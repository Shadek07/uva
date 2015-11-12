
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

int c,s,e,t;
int profit[101][101];
bool end_at[101]; //end_at[i] is true if tour can end at i

unsigned long dp[101][1001]; //dp[i][j] means the profit gained when salesman currently in i node and still has
								//j roads to traverse to go to a destination
vector<int> dest;
#define max(a,b) a>b?a:b

unsigned long solve(int current,int d)
{
	unsigned long mx = 0;
	int i,j;
	if(d == 0)
		return 0;
	if(dp[current][d] != -1)
		return dp[current][d];
	else if(d == 1)
	{
		mx = 0;
		for(i = 0;i<e;i++)
		{
			mx = max(mx,profit[current][dest[i]]);
		}

		return dp[current][d] = mx;

	}
	else if(d > 1)
	{
		mx = 0;
		for(i = 1;i<= c;i++)
		{
			if(i != current)
			{
				dp[i][d-1] = solve(i,d-1);
				mx = max(mx,profit[current][i]+dp[i][d-1]);
				
			}
		}
		return dp[current][d] = mx;
	}
	

}
int main(void)
{
	int a,b,i,j,k;
	while(cin >> c >> s >> e >> t)
	{
		if(!c && !s && !e && !t)
			break;

		for(i = 1;i<= c;i++)
		{
			for(j = 1;j<=c;j++)
				cin >> profit[i][j];
		}

		
		memset(end_at,false,sizeof(end_at));
		for(i = 0;i<e;i++)
		{
			cin >> a;
			dest.push_back(a);
			end_at[a] = true;
		}

		for(i = 1;i<= c;i++)
		{
			for(j = 1;j<= t;j++)
				dp[i][j] = -1;
		}
		cout << solve(s,t) << endl;
		dest.clear();

		
	}
	return 0;
}
