
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

int n,m,c;

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca = 1,a;
	bool st[21];
	int cons[21];
	int i;
	while(cin >> n >> m >> c)
	{
		if(n == 0 && m == 0 && c == 0)
			break;
		int mx = 0;
		int cur = 0;
		memset(st,false,sizeof(st));
		for(i = 1;i<=n;i++)
		{
			cin >> cons[i];
		}
		for(i = 0;i<m;i++)
		{
			cin >> a;
			if(st[a] == false)
			{
				st[a] = true;
				cur += cons[a];
				if(cur > mx)
					mx = cur;

			}
			else
			{
				st[a] = false;
				cur -= cons[a];
				
			}
		}

		cout << "Sequence " << ca++ << endl;
		if(mx > c)
			cout << "Fuse was blown.\n";
		else
			cout << "Fuse was not blown.\nMaximal power consumption was " << mx <<" amperes.\n";
		cout << endl;

	}
     return 0;
}