
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

#define MAX 1001
#define INF 9999999
int dp[MAX][MAX];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char f[MAX];
    char s[MAX];
    int n,m;
    int i,j;
    while(cin >> n >> f){
        cin >> m >> s;
        //cout << s << endl;
        
        for(i=0;i<=m;i++){
            dp[0][i] = i;
        }
        for(i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j] + 1; //delete
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1); //insert
                
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(f[i-1] != s[j-1])); 
                
            }
        }
        //cout << dp[n][m] << endl;
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
