
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

int t,r,h;

int tr[20][21];
int rs[20][21];
int ht[20][21];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	while(cin >> t >> r >> h)
	{
		for(i = 0;i<t;i++)
		{
			for(j = 0;j<r+1;j++)
				cin >> tr[i][j];
		}
		for(i = 0;i<r;i++)
		{
			for(j = 0;j<h+1;j++)
				cin >> rs[i][j];
		}
		for(i = 0;i<h;i++)
		{
			for(j = 0;j<t+1;j++)
				cin >> ht[i][j];
		}

		bool fnd = false;
		int chp;
		int a,b,c;
		for(i = 0;i< t;i++)
		{
			for(j = 0;j<r;j++)
			{
				for(k = 0;k<h;k++)
				{
					if(!tr[i][j+1] && !rs[j][k+1] && !ht[k][i+1])
					{
						if(fnd == false)
						{
							fnd = true;
							chp = tr[i][0] + rs[j][0] + ht[k][0];
							a = i;
							b = j;
							c = k;
						}
						else if(tr[i][0] + rs[j][0] + ht[k][0] < chp)
						{
							chp = min(chp,tr[i][0] + rs[j][0] + ht[k][0]);
							a = i;
							b = j;
							c = k;
						}
					}
				}
			}
		}

		if(fnd==true)
			cout << a << " " << b << " " << c << ":" << chp << endl;
		else
			cout << "Don't get married!\n";

	}
     return 0;
}