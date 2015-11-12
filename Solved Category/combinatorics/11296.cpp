
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
	int n;
	unsigned long long ans,a,b;
	while( scanf("%d",&n)==1)
	{
		if(n==1)
		{
			cout << 1 << endl;
			continue;
		}
		if(n == 2)
		{
			cout << 3 << endl;
			continue;
		}
		if(n == 3)
		{
			cout << 3 << endl;
			continue;
		}
		if(n%2==0)
		{
			n++;
		}

		a = (n-1)/2;
		a++;
		
		if(a%2==0)
		{
            b = a;
			a/=2;
			a *= (b+1);
		}
		else
		{
			a++;
			b = a-1;
			a /= 2;
			a *= b;
		}

		cout << a << endl;
		
	}
	return 0;
}
