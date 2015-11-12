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

using namespace std;


int main(void)
{
	int t;
	int num;
	char in[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		int a,b,c,d;
		a = __builtin_popcount(num);
		b = 0;
		c = num;
		while(c>0)
		{
         b += __builtin_popcount(c%10);
         c /= 10;
    }
    cout << a << " " << b << endl;
		
	}
	return 0;
}
