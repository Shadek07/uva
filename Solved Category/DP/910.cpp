
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

int n,m;
vector<int> special;
long long int cnt[27][31];
int dir[27][2];
bool state[27][31];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[10];
	int i,j,k;
	while(cin >> n)
	{
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(in);
			dir[in[0]-'A'][0] = in[2]-'A';
			dir[in[0]-'A'][1] = in[4]-'A';
			if(in[6] == 'x')
				special.push_back(in[0]-'A');

		}

		cin >> m;
		memset(cnt,0,sizeof(cnt));
		memset(state,false,sizeof(state));
		state[0][0] = true;
		cnt[0][0] = 1;
		for(i = 1;i<=m;i++)
		{
			for(j = 0;j<26;j++)
			{
				for(k = 0;k<26;k++)
				{
					if(dir[k][0] == j)
					{
						cnt[j][i] += cnt[k][i-1];
					}
					if(dir[k][1] == j)
					{
						cnt[j][i] += cnt[k][i-1];
					}
				}
			}
		}

		long long int ans = 0;
		k = special.size();
		for(i = 0;i<k;i++)
		{
			ans += cnt[special[i]][m];
		}
		cout << ans << endl;
		special.clear();

	}
     return 0;
}