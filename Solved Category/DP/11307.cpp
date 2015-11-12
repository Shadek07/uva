
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
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

vector<int> child[10000];
int n;
unsigned long dp[10000][7];
int deg[10000];

unsigned long calc(int node, int color)
{
	unsigned long int sum = 0;
	unsigned long int tmp;
	sum += color;
	int i,j,sz;
	sz = child[node].size();
	if(sz == 0)
		return color;
	if(dp[node][color] != -1)
		return dp[node][color];
	for(i = 0;i<sz;i++)
	{
		tmp = 99999999;
		for(j = 1;j<7;j++)
		{
			if(j != color)
				tmp = min(tmp,calc(child[node][i],j));

		}
		sum += tmp;
	}
	return dp[node][color] = sum;

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int a,b;
	while(scanf("%d",&n) && n)
	{
		getchar();
		char s1[50000];
		memset(deg,0,sizeof(deg));
		for(i = 0;i<n;i++)
		{
			gets(s1);
			int len = strlen(s1);
			a = 0;
			j = 0;
			while(s1[j] != ':')
			{
				a = a*10 + (s1[j] - '0');
				j++;
			}
			j++;
			bool prev = false;
			b = 0;
			while(1)
			{
				if(j >= len)
				{
					break;
				}
				while(j<len && s1[j] >= '0' && s1[j] <= '9')
				{
					prev = true;
					b = b*10 + (s1[j]-'0');
					j++;
				}
				if(prev == true)
				{
					child[a].push_back(b);
					deg[b]++;
					b = 0;
					prev = false;
				}
				j++;
			}


		}
		int root;
		for(i = 0;i<n;i++)
			if(deg[i] == 0)
			{
				root = i;
				break;
			}
		for(i = 0;i<n;i++)
		{
			for(j =1 ;j<7;j++)
				dp[i][j] = -1;
		}
		unsigned long int ans = 99999999;
		for(i = 1;i<7;i++)
		{
			ans = min(ans,calc(root,i));
		}
		cout << ans << endl;
		for(i = 0;i<n;i++)
			child[i].clear();
	}
    
	return 0;
}
