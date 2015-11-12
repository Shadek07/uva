
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
long long int ans=-1;
void update(long long int a)
{
      if(ans == -1)
         ans = a;
      else if(ans>a)
          ans = a;
}
bool check(long long int n)
{
      while(n%2 == 0)
         n/=2;
      while(n%3 == 0)
         n/=3;
      if(n==1)
         return true;
         
      return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    long long int m1;
    long long int l,r,mid;
    vector<long long int> v;
    int i,j;
    for(i = 0;i<=31;i++)
    {
          for(j = 0;j<=20;j++)
          {
                if(pow(2.0,i) <= pow(2.0,31)*pow(3.0,j))
                {
                      v.push_back((long long int)(pow(2.0,i)*pow(3.0,j)));
                }
          }
    }
    
    sort(v.begin(), v.end());
    vector<long long int>:: iterator low,up;
    while(cin >> m1 && m1)
    {
          low=lower_bound(v.begin(), v.end(), m1);
          cout << v[(low- v.begin())]  << endl;
    }
    return 0;
}
