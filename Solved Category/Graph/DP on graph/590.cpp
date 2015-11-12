
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
#define min(a,b) a>b?b:a

int flight[11][11][35];
int wrap[11][11];
int n,w;
bool vis[11][1001];
int dp[11][1001]; //dp[i][k] is min sum of all costs when last node is i and k flights finished

void calculate()
{
	int i,j,k,a,len;

	for(k= 1;k<=w;k++)
	{
		for(a = 1;a<=n;a++)
		{
			for(i = 1;i<=n; i++)
			{
				if(i != a && dp[a][k-1] != -1)
				{
					j = wrap[a][i];
					j = (k)%j-1;
					if(j == -1)
						j = wrap[a][i]-1;
					if(flight[a][i][j] != 0)
					{
						if(vis[i][k] == false)
						{
							dp[i][k] = dp[a][k-1] + flight[a][i][j];
							vis[i][k] = true;							

						}
						else if(dp[i][k] > dp[a][k-1] + flight[a][i][j])
						{
							dp[i][k] = dp[a][k-1] + flight[a][i][j];
												
						}
					}

				}
			}
		}
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,a,b,d;
	int ca=1;
	while(scanf("%d %d",&n,&w)==2  && n && w)
	{
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				if(i != j)
				{
					//cin >> d;
					scanf("%d",&d);
					wrap[i][j] = d;
					for(k = 0;k<d;k++)
					{
						//cin >> a;
						scanf("%d",&a);
						flight[i][j][k] = a;
					}
				}
			}
		}

		for(i = 0;i<=n;i++)
		{
			for(j = 0; j<= w;j++)
			{
				vis[i][j] = false;
				dp[i][j] = -1;
			}
		}

		dp[1][0] = 0;
		vis[1][0] = true;
		calculate();
		cout << "Scenario #" << ca++ << endl;
		if(vis[n][w] == false)
		{
			cout << "No flight possible.\n\n";
		}
		else
		{
			cout << "The best flight costs " << dp[n][w] << ".\n\n";
		}
	}
     return 0;
}
