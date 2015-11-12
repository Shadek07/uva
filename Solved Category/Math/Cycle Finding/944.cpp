
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

int happy[100000];

int cycle(int n)
{
	int vis[406];
	int a = n,b;
	memset(vis,false,sizeof(vis));
	int cnt = 1;
	while(true)
	{
		b = 0;
		while(n)
		{
			b += (n%10)*(n%10);
			n/=10;
		}
		cnt++;
		if(b == 1)
			return cnt;
		if(b==a || vis[b] == true)
			return 0;
		vis[b] = true;
		n = b;

	}
}

void calc()
{
	int i,j;
	
	happy[1] = 1;
	for(i = 2;i<100000;i++)
	{
		happy[i] = cycle(i);
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	calc();
	int ca=1;
	int l,h,i;
	while(cin >> l >> h)
	{
		if(ca == 1)
			ca = 2;
		else
			cout << endl;
		for(i = l;i<=h;i++)
		{
			if(happy[i])
				cout << i << " " << happy[i] << endl;
		}

	}
     return 0;
}