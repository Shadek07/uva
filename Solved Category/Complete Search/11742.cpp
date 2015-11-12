
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
	int n,m,i,j,k,a,b;
	long int cnt;
	int limit[21][3];
	int perm[9];
	int pos[9];
	while(cin >> n >> m)
	{
		if(!n && !m)
			break;
		for(i = 0;i<m;i++)
		{
			cin >> limit[i][0] >> limit[i][1] >> limit[i][2];
		}

		for(i = 0;i<n;i++)
		{
			perm[i] = i;
		}

		cnt = 0;
		do
		{
			for(i = 0;i< n;i++)
			{
				pos[perm[i]] = i;
			}

			bool ch = true;
			for(i = 0;i<m;i++)
			{
				k = limit[i][2];
				a = limit[i][0];
				b = limit[i][1];
				if(k>0 && abs(pos[a]-pos[b]) > k)
				{
					ch = false;
					break;
				}
				if(k<0 && abs(pos[a]-pos[b]) < abs(k))
				{
					ch = false;
					break;
				}

			}
			if(ch)
				cnt++;
		}while(next_permutation(perm,perm+n));

		cout << cnt << endl;
	}
	return 0;
}
