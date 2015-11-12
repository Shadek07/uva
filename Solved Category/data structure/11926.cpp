
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
bool bt[1000001];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n,m;
    int a,b,i,j,k;
    int interval,period;
    bool ok = true;
    while(cin >> n >> m)
    {
          if(n == 0 && m == 0)
          break;
            memset(bt,false,sizeof(bt));
            ok = true;
            for(i = 0;i<n;i++)
            {
                  cin >> a >> b;
                  for(j = a+1;j<=b&& ok;j++)
                  {
                        if(bt[j])
                        {
                              ok = false;
                              break;
                        }
                        bt[j] = true;
                  }
            }
            for(i = 0;i<m;i++)
            {
                  cin >> a >> b >> period;
                  interval = b-a;
                  for(j = a;j<=1000000 && ok;j+=period)
                  {
                        for(k = j+1;k<=j+interval && k<= 1000000;k++)
                        {
                              if(bt[k])
                              {
                                    ok = false;
                                    break;
                              }
                              bt[k] = true;
                        }
                        
                  }
            }
            if(ok)
                  cout << "NO CONFLICT\n";
            else
                  cout << "CONFLICT\n";
    }
    return 0;
}
