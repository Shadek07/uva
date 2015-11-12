
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

bool dp[641][641];
int w[33];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca=1;
	int t,n,i,j,k,sum,a,b;
	cin >> t;
	while(t--)
	{
		cin >> n;
		sum=0;
		for(i=1;i<=n;i++)
		{
			cin >> w[i];
			sum += w[i];
		}
		int limit = sum/2;
		memset(dp,false,sizeof(dp));
		dp[0][0] = true;
		for(i = 1;i<=n;i++)
		{
			a = w[i];
			for(j = limit;j>=0;j--)
			{
				for(k = limit;k>=0;k--)
				{
					if(j-a>=0)
					dp[j][k] |= dp[j-a][k];
					if(k-a>=0)
					dp[j][k] |= dp[j][k-a];
				}
			}
		}

		int diff = sum;
		for(j=1;j<=limit;j++)
		{
			for(k=0;k<=limit;k++)
			{
				if(dp[j][k]==true)
				{
					int rest = sum-(j+k);
					a = max(max(j,k),rest);
					b = min(min(j,k),rest);
					diff = min(diff,a-b);
				}
			}
		}

		cout << "Case " << ca++ << ": " << diff << endl;
	}
    return 0;
}