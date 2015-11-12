
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
#define max(a,b) a>a?a:b
set<string> words;
char lan1[1501][11];
char lan2[1501][11];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,m,n;
	cin >> t;
	getchar();
	string s,s1;
	int ca=1;
	while(t--)
	{
		cin >> m >> n;
		getchar();
		for(i = 0;i<m;i++)
		{
			gets(lan1[i]);
		}

		for(i = 0;i<n;i++)
		{
			gets(lan2[i]);
		}

		for(i = 0;i<m;i++)
		{
			for(j = 0;j<n;j++)
			{
				s = lan1[i];
				s += lan2[j];
				words.insert(s);
			}
		}

		cout << "Case " << ca++ << ": " << words.size() << endl;
		words.clear(); 
	}
     return 0;
}