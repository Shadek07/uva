
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
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

map<int,int> mp;

int num_digits(int n)
{
	return log10(n*1.0)+1;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int denominator,numerator;
	int ind;
	bool decimal,indefinite;
	int a,i,j,k;
	string res;
	while(cin >> numerator >> denominator)
	{
		cout << numerator << "/" <<denominator <<" = " << numerator/ denominator<< ".";
		numerator = numerator%denominator;
		i = 0;
		res = "";
		while(numerator != 0 && mp[numerator] == 0)
		{	
			mp[numerator] = ++i;
			numerator *= 10;
			res += char(numerator/denominator + '0');
			numerator = numerator%denominator;
		}

		if(numerator == 0)
		{
			cout << res << "(0)\n";
			i = 1;
		}
		else
		{
			mp[numerator]--;
			int sz = i;
			if(sz>50)
				sz = 50;
			for(j = 0;j<sz;j++)
			{
				if(j == mp[numerator])
					cout << "(";
				cout << res[j];
			}
			if(i>50)
				cout << "...";
			cout << ")\n";
			i -= mp[numerator];
		}

		printf("   %d = number of digits in repeating cycle\n\n", i);
		mp.clear();
	}

    return 0;
}
