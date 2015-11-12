
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
#include<stack>
#include<list>
using namespace std;

struct fraction
{
	double a;
	double b;
}fr[400001];

bool comp(fraction p,fraction q)
{
	 if(p.a/p.b < q.a/q.b-1e-7)
		 return true;
	 else
		 return false; 
}
int gcd(int a,int b)
{
	int c;

	if(a<b)
	{		
		c = a;
		a = b;
		b = c;
	}
	while(1)
	{
		c = a%b;
		if(c==0)
			return b;
		a = b;
		b = c;
	}
}
int main(void)
{
	int n,k;
	int i,j;
	int cnt;
	while(cin >> n >> k)
	{
		cnt = 0;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=i;j++)
			{
				if(gcd(i,j)==1)
				{
					fr[cnt].a = j;
					fr[cnt].b = i;
					cnt++;
				}
			}
		}

		sort(fr,fr+cnt,comp);
		//for(i = 0;i<cnt;i++)
		//{
			//printf(" %.0lf/%0.lf",fr[i].a,fr[i].b);
		//}
		//cout << endl;
		printf("%.0lf/%0.lf\n",fr[k-1].a,fr[k-1].b);
	}
	return 0;
}
