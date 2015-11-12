
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

char in[101][101];
int n,m,q;

bool test1(int a,int b,int size,char c)
{
	int i,j;
	for(i = a;i<a+size;i++)
	{
		for(j = b;j<b+size;j++)
		{
			if(in[i][j] != c)
				return false;
		}
	}

	return true;

}

bool inside(int a,int b)
{
	if(a>= 0 && a<n && b>= 0 && b< m)
		return true;
	else
		return false;
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	
	int i,j,k;
	int test;
	cin >> test;
	int x,y;
	while(test--)
	{
		cin >> n >> m >> q;
		getchar();
		for(i = 0;i<n;i++)
			gets(in[i]);

		cout << n << " " << m << " " << q << endl;
		for(i = 0;i<q;i++)
		{
			cin >> x >> y;
			if(!inside(x,y))
			{
				cout << 0 << endl;
				continue;
			}
			int step;
			for(step = 1;;step++)
			{
				if(!(inside(x-step,y) && inside(x+step,y) && inside(x,y+step) && inside(x,y-step) && test1(x-step,y-step,2*step+1,in[x][y])))
					break;
			}

			step--;

			cout << 2*step+1 << endl;

		}		

	}
    
	return 0;
}