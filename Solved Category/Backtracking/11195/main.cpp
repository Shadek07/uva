
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
#include <fstream>
#include<ctime>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 17
int ans=0;
int ok;  //( (1<<n) - 1)
int n;
char in[MAX][MAX];

int getPower(int n)
{
    int x = 1;
    int cnt = 0;
    int t = log10(n*1.0)/log10(2.0);
    return t;
    while(x < n)
    {
        x = x<<1;
        cnt++;
    }
    return cnt;
}
void backtrack(int rw, int ld, int rd, int col)
{
    if(rw == ok)
    {
        ans++;
        return;
    }
    int pos = ok & (~(rw|ld|rd));
    while(pos)
    {
        int p = pos & -pos;
        pos -= p;
        int r = getPower(p);
        if(in[r][col] != '*')
            backtrack(rw|p, (ld|p)<<1, (rd|p)>>1, col+1);
    }
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k;
    int ca = 1;
    while(cin >> n)
    {
        if(n == 0)
            break;
        ok = (1<<n)-1;
        ans = 0;
        getchar();
        forl(i,0,n)
        {
            gets(in[i]);
        }
        backtrack(0,0,0,0);
        cout << "Case " << ca++ << ": " << ans << endl;
    }
    return 0;
}
