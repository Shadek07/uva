
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

int F[201];
string st[101];

//return longest length of prefix that is also a suffix
int build_failure_function(string pattern)
{
      int i,j;
      int m = pattern.size();
      F[0] = F[1] = 0;
      for(i = 2; i<=m;i++)
      {
            // j is the index of the largest next partial match
            // (the largest suffix/prefix) of the string under
            // index i - 1
            j = F[i-1];
            for(;;)
            {
                  // check to see if the last character of string or
                  // pattern[i - 1] "expands" the current "candidate"
                  // best partial match - the prefix under index j
                  if(pattern[j] == pattern[i - 1])
                  {
                        F[i] = j + 1;
                        break;
                  }

                  if(j == 0)
                  {
                        F[i] = 0;
                        break;
                  }
                  // else go to the next best "candidate" partial match
                  j = F[j];
            }
      }

      return F[m];

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    char in[102];
    getchar();
    int i,j,len,n;
    int ans;
    while(t--)
    {
          cin >> len >> n;
          getchar();
          for(i = 0;i<n;i++)
          {
                gets(in);
                st[i] = in;
          }

          ans = len;
          for(i = 1;i<n;i++)
          {
                if(st[i].compare(st[i-1]) == 0)
                continue;
                /*
                if s1 and s2 are two consecutive strings then the number of
                overlapping characters between s1 and s2 is
                longest suffix/prefix match of (s2+s1)
                s1 = "ABCD"
                s2 = "CDEF";
                s1 + s2 = "ABCD + CDEF", CD is common
                s2 + s1 = CDEFABCD, here CD is longest prefix that is also a suffix
                */
                ans += (len - build_failure_function(st[i] + st[i-1]));
          }

          cout << ans << endl;
    }

    return 0;
}
