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
bool a[25][25];
bool b[25][25];
int main(void)
{
	int n,i,j,k;
	int fir[25];
	int sec[25];
	while( scanf("%d",&n) == 1)
	{
		k = 0;
		for(i = 0;i<n;i++)
			scanf("%d",&fir[i]);
		for(i = 0;i<n;i++)
			scanf("%d",&sec[i]);

		memset(a,false,sizeof(a));
		memset(b,false,sizeof(b));

		for(i = 0;i<n-1;i++)
		{
			for(j = i+1;j<n;j++)
			{
				a[fir[i]][fir[j]] = true;
			}
		}

		for(i = 0;i<n-1;i++)
		{
			for(j = i+1;j<n;j++)
			{
				b[sec[i]][sec[j]] = true;
			}
		}

		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				if(a[i][j] == true && b[i][j] == false)
					k++;
			}
		}

		cout << k << endl;

	}
	return 0;
}