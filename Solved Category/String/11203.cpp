
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[52];
	int n;
	int i,j,k;
	cin >> n;
	getchar();
	int a,b,c;

	while(n-->0)
	{
		gets(in);
		int len = strlen(in);
		i = 0;
		while(i<len && in[i] == '?')
			i++;
		a = i;
		if(i<1)
		{
			cout << "no-theorem\n";
			continue;
		}

		if(i>=len || in[i] != 'M')
		{
			cout << "no-theorem\n";
			continue;
		}

		i++;
		j = i;
		while(i<len && in[i] == '?')
			i++;
		b = i-j;
		if(i-j <= 0)
		{
			cout << "no-theorem\n";
			continue;
		}

		if(i >= len || in[i] != 'E')
		{
			cout << "no-theorem\n";
			continue;
		}

		i++;
		j = i;

		while(i<len && in[i] == '?')
			i++;
		c = i-j;
		if(i< len || i-j <= 0)
		{
			cout << "no-theorem\n";
			continue;
		}
		if(a+b != c || b != c-a)
		{
			cout << "no-theorem\n";
			continue;
		}

		cout << "theorem\n";

	}

    return 0;
}