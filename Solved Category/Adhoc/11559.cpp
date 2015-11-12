
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

int main(void)
{
	int n,b,h,w;
	int i,j,k;
	int cost;
	long int ans = 2000001;
	int mn;
	while(scanf("%d %d %d %d",&n,&b,&h,&w)==4)
	{
		ans = 2000001;
		for(i = 0;i<h;i++)
		{
			scanf("%d",&cost);
			mn = 10001;
			for(j = 0;j<w;j++)
			{
				scanf("%d",&k);
				if(k>= n && mn > k)
				{
					mn = k;
				}
			}
			if(mn != 10001)
			{
				mn = n*cost;
				if(mn< ans)
					ans = mn;
			}

		}
		if(ans != 2000001 && ans <= b)
		{
			printf("%d\n",ans);
		}
		else
			printf("stay home\n");
	}
	return 0;
}
