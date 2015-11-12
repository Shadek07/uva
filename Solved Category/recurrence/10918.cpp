
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
long int f[31], g[31];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	f[0] = 1;
	f[1] = 0;

	g[0] = 0;
	g[1] = 1;
	int i;
	for(i = 2;i<=30;i++)
	{		
		f[i] = f[i-2] + 2*g[i-1];
		g[i] = f[i-1] + g[i-2];
		
	}

	while(cin >> i && i != -1)
	{
		cout << f[i] << endl;
	}


    return 0;
}