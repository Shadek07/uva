
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
int s,m,n;
int fir;
int sec;
int dp[257][257][101];
long int cost;
int msk[101];
int cst[101];

long int doit(int fir, int sec, int i)
{
      if(fir == (1<<s)-1 && sec == (1<<s)-1)
          return 0;
      if(i >= n)
         return 5000000;
      
      if(dp[fir][sec][i] != -1)
          return dp[fir][sec][i];
      return dp[fir][sec][i] = min( doit(fir,sec,i+1), cst[i] + doit( fir|msk[i], sec|(fir&msk[i]), i+1) );
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k,mask;
    int a;
    char c;
    string line;
    while(cin >> s && s)
    {
          cin >> m >> n;
          getline(cin,line);
          cost = 0;
          fir = sec = 0;
          //memset(dp,-1, sizeof(dp));
          for ( i = 0; i < 1 << s; i++)
                for ( j = 0; j < 1 << s; j++)
                    for ( k = 0; k < n; k++)
                        dp[i][j][k] = -1;
          for(i = 0;i<m;i++)
          {
                getline(cin,line);
                istringstream is(line);
                is >> a;
                
                cost += a;
                mask = 0;
                while(is >> a)
                {                      
                      mask |= (1<<(a-1));
                }
                fir |= mask;
                sec |= (fir & mask);          
          }
          
          for(i = 0;i<n;i++)
          {
                getline(cin,line);
                istringstream is(line);
                is >> a;
                
                cst[i] = a;
                mask = 0;
                while(is >> a)
                {
                      mask |= (1<<(a-1));
                }
                msk[i] = mask;
          }
          
          cost += doit(fir,sec,0);
          cout << cost << endl;
          
    }
    return 0;
}
