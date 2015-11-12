
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
typedef vector<char> vc;
typedef vector<vc> vcc;

set<vcc> st;
int n;


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int move,i,j,k,i1;
	int a,b;
	char c;
	bool win;
	while(cin >> n && n)
	{
		//vc col(n);
		vcc v(n, vc(n,' '));
		vcc tmp(n, vc(n));
		win = false;
		st.insert(v);
		for(i1 = 0;i1<2*n;i1++)
		{
			scanf("%d %d %c", &a,&b,&c);
			if(win)
				continue;
			if(c == '+')
			v[a-1][b-1] = '.';
			else
				v[a-1][b-1] = ' ';

			if(st.count(v) != 0)
			{
				if(i1%2==0)
					cout << "Player 2 wins on move " << i1+1 << endl;
				else
					cout << "Player 1 wins on move " << i1+1 << endl;
				win = true;
				continue;
			}
			
			for(i = 0;i<n;i++)
			{
				for(j=0;j<n;j++)
					tmp[j][n-1-i] = v[i][j];
			}

			if(st.count(tmp) != 0)
			{
				if(i1%2==0)
					cout << "Player 2 wins on move " << i1+1 << endl;
				else
					cout << "Player 1 wins on move " << i1+1 << endl;
				win = true;
				continue;
			}

			for(i = 0;i<n;i++)
			{
				for(j=0;j<n;j++)
					tmp[n-1-j][i] = v[i][j];
			}

			if(st.count(tmp) != 0)
			{
				if(i1%2==0)
					cout << "Player 2 wins on move " << i1+1 << endl;
				else
					cout << "Player 1 wins on move " << i1+1 << endl;
				win = true;
				continue;
			}

			for(i = 0;i<n;i++)
			{
				for(j=0;j<n;j++)
					tmp[n-1-i][n-1-j] = v[i][j];
			}

			if(st.count(tmp) != 0)
			{
				if(i1%2==0)
					cout << "Player 2 wins on move " << i1+1 << endl;
				else
					cout << "Player 1 wins on move " << i1+1 << endl;
				win = true;
				continue;
			}

			st.insert(v);
		}

		while(i1<2*n)
		{
			scanf("%d %d %c", &a,&b,&c);
			i1++;
		}
		st.clear();
		if(win == false)
			cout << "Draw\n";

	}
    return 0;
}
