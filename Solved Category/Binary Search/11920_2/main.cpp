
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
#include<climits>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define MID(a, b) (a + ((b - a) >> 1))
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 1001
#define INF 9999999
char in[MAX+1];
int n;
bool check(int sz){
    int dp[MAX][2];
    int i;
    dp[0][0] = n;
    dp[0][1] = n;
    //dp[i][0] is the minimum length of consecutive streak of '0' 
    //  which ends at i'th index when max group size is : sz
    //dp[i][1] is the minimum length of consecutive streak of '1' which ends at i'th index
    for(i=1;i<=n;i++){
        dp[i][0] =dp[i][1] = 0;
        if(in[i-1] == '1'){
            //a streak ends at (i-1)'th index having '0' as the last element
            //so greedily start new streak of '1' as length 1
            if(dp[i-1][0] > 0){
                dp[i][1] = 1;
            }else if(dp[i-1][1] > 0 && dp[i-1][1] + 1 <= sz){
                dp[i][1] = dp[i-1][1] + 1;
            }
        }else if(in[i-1] =='0'){
            if(dp[i-1][1] > 0){
                dp[i][0] = 1;
            }else if(dp[i-1][0] > 0 && dp[i-1][0] + 1 <= sz){
                dp[i][0] = dp[i-1][0] + 1;
            }
        }else{
            if(dp[i-1][0] > 0){
                dp[i][1] = 1;
            }else if(dp[i-1][1] > 0 && dp[i-1][1] + 1 <= sz){
                dp[i][1] = dp[i-1][1] + 1;
            }
            if(dp[i-1][1] > 0){
                dp[i][0] = 1;
            }else if(dp[i-1][0] > 0 && dp[i-1][0] + 1 <= sz){
                dp[i][0] = dp[i-1][0] + 1;
            }
        }
        //when there is no streak that ends at i'th index considering both '0' and
        //'1' as last element, it is impossible to create string with max_group_size of sz
        //need to increase sz
        if(dp[i][0] == 0 && dp[i][1] == 0)
            return false;
    }
    return true;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int i,j,k;
    getchar();
    int ca=1;
    while(t--){
        gets(in);
        n = strlen(in);
        int ans;
        int l,r,mid;
        l = 1;
        r = n;
        int mx_group = 0;
        for(i=0;i<n;i++){
            if(in[i] != '?'){
                for(j=i+1;j<n;j++){
                    if(in[j] != in[j-1]){
                        break;
                    }
                }
                mx_group = max(mx_group, j-i);
                i = j-1;
            }
        }
        while(l<=r){
            mid = MID(l,r);
            if(check(mid)){
                ans = mid;
                if(ans == mx_group)
                    break;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        printf("Case %d: %d\n",ca, ans);
        ca++;
    }
    return 0;
}
