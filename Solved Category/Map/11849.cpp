
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
map<long int,int> fir;
map<long int,int> sec;
int main(void)
{
	int m,n;
	long int a;
	int cnt,ind,i;
	while(cin >> m >> n)
	{
		if(!m && !n)
			break;

		ind = 1;
		for(i = 0;i<m;i++)
		{
			cin >> a;
			fir[a] = ind++;
		}

		cnt = 0;
		for(i = 0;i<n;i++)
		{
			cin >> a;
			if(fir[a])
				cnt++;
		}

		cout << cnt << endl;
		fir.clear();

	}
	return 0;
}
