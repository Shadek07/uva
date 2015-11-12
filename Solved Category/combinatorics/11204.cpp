
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int t;
	int n,m;
	int cnt[33];
	cin >> t;
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		cin >> n >> m;
		for(i = 0;i<m;i++)
		{
			for(j = 1;j<=n;j++)
			{
				cin >> k;
				if(k == 1)
					cnt[j]++;

			}
		}

		unsigned long int ans = 1;
		for(i = 1;i<=n;i++)
			if(cnt[i]>1)
				ans*=cnt[i];
		cout << ans << endl;

	}
     return 0;
}