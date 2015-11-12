
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

bool hori[10][10][10];
bool vert[10][10][10];
int n,m;

bool hori_check(int row,int a,int b)
{
	int i;
	for(i = a;i<b;i++)
	{
		if(hori[row][i][i+1] == false)
			return false;
	}

	return true;

}

bool vert_check(int col,int a,int b)
{
	int i;
	for(i = a;i<b;i++)
	{
		if(vert[col][i][i+1] == false)
			return false;
	}

	return true;

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char c;
	int i,j,k,a,b;
	int cnt[10];
	int prob=1;
	while(cin >> n)
	{
		cin >> m;
		getchar();
		memset(hori,false,sizeof(hori));
		memset(vert,false,sizeof(vert));

		for(i = 0;i<m;i++)
		{
			cin >> c >> a >> b;
			getchar();
			if(c == 'H')
			{
				hori[a][b][b+1] = true;
			}
			else
			{
				vert[a][b][b+1] = true;
			}
		}

		memset(cnt,0,sizeof(cnt));

		for(i = 1;i<=9;i++)
		{
			for(j = 1;j<=9;j++)
			{
				for(k = 1;i+k<=n && j+k<=n;k++)
				{
					if(hori_check(i,j,j+k) && hori_check(i+k,j,j+k) && vert_check(j,i,i+k) && vert_check(j+k,i,i+k))
					{
						cnt[k]++;
					}

				}
			}
		}
		if(prob > 1)
			cout << endl << "**********************************" << endl << endl;
		cout << "Problem #" << prob++ << endl << endl;
		bool fnd = false;
		for(i = 1;i<=n;i++)
		{
			if(cnt[i] > 0)
			{
				fnd = true;
				cout << cnt[i] << " square (s) of size " << i << endl;
			}
		}
		if(fnd == false)
			cout << "No completed squares can be found.\n";


	}
     return 0;
}