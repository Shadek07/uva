
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

#define MAX 1026

int cnt[MAX][MAX];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int n,d;
    int i,j,k;
    int x,y,a;
    int ans;
    while(t--)
    {
        //cin >> d;
        //cin >> n;
        scanf("%d %d",&d,&n);
        ms(cnt,0);
        forl(k,0,n)
        {
            scanf("%d %d %d",&x,&y,&a);
            forl(i,max(0,x-d),min(1025,x+d+1))
            {
                forl(j,max(0,y-d),min(1025,y+d+1))
                {
                    cnt[i][j] += a;
                }
            }
        }
        ans = cnt[0][0];
        x = 0;
        y = 0;
        forl(i,0,1025)
        {
            forl(j,0,1025)
            {
                if(cnt[i][j] > ans)
                {
                    ans = cnt[i][j];
                    x = i;
                    y = j;
                }
         
            }
        }
        //cout << x << " " << y << " " << ans << endl;
        printf("%d %d %d\n",x,y,ans);
    }
    return 0;
}
