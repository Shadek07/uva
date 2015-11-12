
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
	int t;
    unsigned long long int n,m,i,j,cnt,a,b;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		if(m < n)
		{
			cout << m << endl;
			continue;
		}

		cnt = n-1;
		a = 1;
		b = 0;
		while(cnt > 0 && b+a < m-(n-1))
		{
			if(a==1)
			cnt-=2;
			else
				cnt--;
			b += a;
			a++;
		}
		if(m-(n-1) == 1)
			cnt -= 2;
		else if(m-(n-1) > b)
			cnt--;
		if(cnt<0)
			cnt = 0;
		cout << cnt << endl;
	}
     return 0;
}
