
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

int digits(unsigned int n)
{
	return log10(n) + 1;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int n;
	int len;
	int i;
	double left,right;
	int l,r;
	while(cin >> n)
	{
		len = digits(n);
		i=1;
		while(true)
		{
			left = log10(n)/log10(2) + (len+i)*1.0/log10(2);
			right = log10(n+1)/log10(2) + (len+i)*1.0/log10(2);
			l = floor(left);
			r = floor(right);
			if(r != right && l<r)
			{
				cout << r << endl;
				break;
			}
			i++;
		}
	}
    return 0;
}
