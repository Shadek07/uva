
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
	int t;
	cin >> t;
	int n,m;
	int cnt;
	while(t--)
	{
		cnt = 0;
		cin >> n >> m;
		while(n>=m)
		{
			cnt++;
			n = (n-m)+1;
		}

		if(n != 1)
			cout << "cannot do this\n";
		else
			cout << cnt << endl;
	}
     return 0;
}