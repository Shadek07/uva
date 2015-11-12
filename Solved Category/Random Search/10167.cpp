
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
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); } 
#define pi acos(-1.0)
int chery[101][2];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	//cout << acos(-40.0/(sqrt(65.0)*5))*180/pi << endl;
	int n,i,j,k;
	int a,b;
	while(cin >> n && n)
	{
		for(i=0;i<2*n;i++)
		{
			cin >> chery[i][0] >> chery[i][1];
		}

		while(true)
		{
			a = -500 + rand()%1001;
			b = -500 + rand()%1001;
			//a=0;
			//b=1;
			int cnt1,cnt2;
			cnt1 = cnt2 = 0;
			for(i = 0;i<2*n;i++)
			{
				if(chery[i][0]*a + chery[i][1]*b>0)
					cnt1++;
				else if(chery[i][0]*a + chery[i][1]*b<0)
					cnt2++;
			}
			if(cnt1 == cnt2 && cnt1==n)
				break;
		}

		cout << a << " " << b << endl;
	}
    return 0;
}