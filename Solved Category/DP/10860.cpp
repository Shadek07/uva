
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

char given[10001];
string str;
vector<string> subs[95];
int len;
int dp[10001];
int calc(int ind)
{
	if(ind == len)
		return 0;

	if(dp[ind] != 0)
		return dp[ind];

	int mn=99999;
	int tmp;
	int i,j;
	j = given[ind]-33;
	char in1[101];
	int sz = subs[j].size();
	for(i = 0;i<sz;i++)
	{
		if(subs[j][i].size() <= len-ind)
		{
			if(subs[j][i].compare(str.substr(ind,subs[j][i].size())) == 0)
			{
				tmp = calc(ind+subs[j][i].size());
				if(tmp != -1)
					mn = min(mn,tmp);
			}
		}
	}
	
	if(mn == 99999)
		dp[ind] = -1;
	else
		dp[ind] = 1 + mn;
	return dp[ind];
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int t,ca=1,n;
	char in[101];
	/*for(i = 33;i<=127;i++)
	{
		cout << char(i) << " " << char(i) - 33 << endl;
	}*/
	cin >> t;
	getchar();
	while(t--)
	{
		gets(given);
		str = given;
		cin >> n;
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(in);
			j = in[0] - 33;
			subs[j].push_back(in);
			int b = strlen(in);
			j = in[b-1] - 33;
			reverse(in,in+b);
			subs[j].push_back(in);
		}

		len = strlen(given);

		memset(dp,0,sizeof(int)*(len+1));

		cout << "Set " << ca++ << ": " ;
		k =  calc(0);
		if(k == -1)
			cout << "Not possible.\n";
		else
			cout << k << ".\n";

		for(i = 0;i<95;i++)
			subs[i].clear();
	}
    return 0;
}
