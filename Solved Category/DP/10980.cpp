
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

int itemAmount[21];
double itemCost[21];
double unit;
int m;
char in[1000];
double ans[101];
bool ch[101];

double recur(int k)
{
      if(k <= 0)
           return 0;

      if(ch[k] == true)
           return ans[k];

      double &res = ans[k];
      res = 9999999;
      res = min(res, unit+recur(k-1));
      int i;
      for(i = 0;i<m;i++)
      {
            res = min(res, itemCost[i] + recur(k-itemAmount[i]));
      }

	  ch[k] = true;
      return res;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char *p;
    int i,j;
    int ca=1;
    while(cin >> unit >> m)
    {
           for(i = 0;i<m;i++)
           {
                 cin >> itemAmount[i] >> itemCost[i];
           }
           cout << "Case " << ca++ <<":\n";
           getchar();
           gets(in);
           p = strtok(in, "         ");
           while( p != NULL)
           {
                  memset(ch,false,sizeof(ch));
                  int a = atoi(p);
                  double b = recur(a);
                  cout << "Buy " << a << " for $";
                  printf("%.2f\n",b);
                  p = strtok(NULL,"             ");
           }
    }
    return 0;
}
