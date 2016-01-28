/**
verdict: TLE
runtime : > 1s
*/
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

int dp[MAX][MAX][2];
char in[MAX];
int n;
int mx_group;
int final_ans;
int doit(int ind, int streak, int is_one){
    if(streak > final_ans){
        return n;
    }
    if(ind == n){
        return streak;
    }
    int &res = dp[ind][streak][is_one];
    int t,local;
    int i,j;
    if(res == -1){
        res = MAX;
        if(in[ind] == '?'){
            t = MAX;
            //opposite
            int fir;
            if(is_one){
                local = streak;
                t = max(local, doit(ind+1, 1, 0));
                fir = 0;
                res = min(res, t);
            }else{
                local = streak;
                t = max(local, doit(ind+1, 1, 1)); 
                fir=1;
                res = min(res, t); 
            }
            //same
            if(ind+1 < n && in[ind+1] != '?' && streak+1 <= mx_group){
                int value = 1^(in[ind+1]=='1');
                if(value != fir){
                    if(value == is_one){
                        res = min(res, doit(ind+1, streak+1, is_one));
                    }else{
                        local = streak;
                        t = max(local, doit(ind+1, 1, value));
                        res = min(res, t);
                    }
                }
                
            }
            
        }else{
            int cur = (in[ind] == '1');
            t = MAX;
            //same
            if(cur == is_one){
                i = ind+1;
                while(i<n && in[i] != '?'){
                    int ch = (in[i] == '1');
                    if(ch != cur)
                        break;
                    i++;
                }
                if(streak+(i-ind) <= mx_group){
                    local = streak;
                    t = max(local, doit(i, streak+(i-ind), cur));
                    res = min(res, t); 
                }
            }else{//opposite
                local = streak;
                t = max(local, doit(ind+1, 1, cur));
                res = min(res, t);
            }
        }
    }
    if(ind == 1){
        final_ans = min(final_ans, res);
    }
    return res;
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
        ms(dp,-1);
        n = strlen(in);
        final_ans = n;
        int ans = MAX;
        mx_group = 0;
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
        mx_group += 1;
        final_ans = mx_group;
        if(in[0] != '?'){
            ans = min(ans, doit(1, 1, (in[0] == '1')));
        }else{
           ans = min(ans, doit(1, 1, 0)); 
           ans = min(ans, doit(1, 1, 1)); 
        }
        printf("Case %d: %d\n",ca, ans);
        ca++;
    }
    return 0;
}
