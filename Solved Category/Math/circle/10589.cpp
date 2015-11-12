
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

double pnts[100001][2];
double cent[4][2];
int n,a;
#define eps 1e-12

bool inside(int p,int c)
{
	double dis = (pnts[p][0]-cent[c][0])*(pnts[p][0]-cent[c][0])+(pnts[p][1]-cent[c][1])*(pnts[p][1]-cent[c][1]);
	if((a*a-dis)>eps)
		return true;
	else
		return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i;
	while(cin >> n >> a && n && a)
	{
		for(i = 0;i<n;i++)
		{
			cin >> pnts[i][0] >> pnts[i][1];
		}
		cent[0][0] = 0;
		cent[0][1] = 0;
		cent[1][0] = 0;
		cent[1][1] = a;

		cent[2][0] = a;
		cent[2][1] = 0;
		cent[3][0] = a;
		cent[3][1] = a;
		int cnt=0;
		for(i = 0;i<n;i++)
		{
			if(inside(i,0)&&inside(i,1)&&inside(i,2)&&inside(i,3))
				cnt++;
		}

		/*double r = 1.0;
		r *= cnt;
		r /= n;
		r *= a*a;*/

		printf("%.5f\n",cnt*a*a*1.0/n);



	}
    
	return 0;
}