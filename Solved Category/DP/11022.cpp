
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

int dp[82][82];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char in[82];
    int i,j,k;
    int sz;
    string s,s1,s2;
    while(gets(in))
    {
          if(in[0] == '*')
                break;

          sz = strlen(in);
          for(i = 0;i<sz;i++)
          {
                dp[i][i] = 1;
                if(i<sz-1)
                {
                      if(in[i] == in[i+1])
                      {
                            dp[i][i+1] = 1;
                      }
                      else
                      {
                            dp[i][i+1] = 2;
                      }
                }
          }

          s = in;
          for(k = 3;k<=sz;k++)
          {
                for(i = 0;i<=sz-k;i++)
                {
                      j = i+k-1;
                      dp[i][j] = 81;
                      int k1,len;
                      len = j-i+1;
                      for(k1 = i;k1<j;k1++)
                      {
                            dp[i][j] = min(dp[i][j], dp[i][k1] + dp[k1+1][j]);
                      }
                      for(k1 = 1;k1<=len/2;k1++)
                      {
                            int a,b;
                            a = len/k1;
                            if(a*k1 == len)
                            {
                                  s1 = s.substr(i,k1);
                                  s2 = "";
                                  for(b =0;b<a;b++)
                                  {
                                        s2 = s2+s1;
                                  }
                                  if(s2.compare(s.substr(i,j-i+1)) == 0)
                                  {
                                        dp[i][j] = min(dp[i][j], dp[i][i+k1-1]);
                                  }
                            }
                      }
                }
          }

          cout << dp[0][sz-1] << endl;
    }
    return 0;
}
