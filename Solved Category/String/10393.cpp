
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

int mp[30];
set<string> st[51];
bool missing[11];
set<string>::iterator it;
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    mp[0] = 1;
    mp[1] = 4;
    mp[2] = 3;
    mp[3] = 3;
    mp[4] = 3;
    mp[5] = 4;
    mp[6] = 4;
    mp[7] = 7;
    mp[8] = 8;
    mp[9] = 7;
    mp[10] = 8;
    mp[11] = 9;
    mp[12] = 7;
    mp[13] = 7;
    mp[14] = 9;
    mp[15] = 10;
    mp[16] = 1;
    mp[17] = 4;
    mp[18] = 2;
    mp[19] = 4;
    mp[20] = 7;
    mp[21] = 4;
    mp[22] = 2;
    mp[23] = 2;
    mp[24] = 7;
    mp[25] = 1;
    int finger,m;
    int i,j;
    char word[52];
     int mx,mx_len;
    while(cin >> finger >> m)
    {
          memset(missing, false,sizeof(missing));

          for(i = 0;i<finger;i++)
          {
                cin >> j;
                missing[j] =true;
          }

          getchar();

          mx_len = 0;

          for(i = 0;i<m;i++)
          {
                cin >> word;
                int a = strlen(word);
                if(a> mx_len)
                mx_len = a;
                st[a].insert(word);
          }
          string s;
          set<string> ans;
          bool take = false;
          for(;mx_len>0;mx_len--)
          {
                  mx = 0;
                  for(it = st[mx_len].begin(); it != st[mx_len].end(); it++)
                  {
                        s = *it;
                        bool fnd = false;
                        for(i = 0;i<mx_len;i++)
                        {
                                    if(missing[mp[s[i]-'a']])
                                    break;
                        }

                        if(i == mx_len)
                        {
                                    fnd = true;
                                    take = true;
                                    ans.insert(s);
                        }
                  }

                  if(take)
                  {
                        cout << ans.size() << endl;
                        for(it = ans.begin(); it != ans.end(); it++)
                        {
                              cout << *it << endl;
                        }
                        break;
                  }
          }
          if(!take)
          cout << 0 << endl;

          ans.clear();
          for(i = 1;i<51;i++)
          st[i].clear();
    }



    return 0;
}
