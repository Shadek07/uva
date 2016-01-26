
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

#define MAX 201
#define INF 9999999

bool dp[MAX][MAX][MAX];
int a,b,c,d;
int mx[3];
struct state{
    int arr[3];
    int cost;
};
/**
min priority queue: minimum value will come first
*/
bool operator<(const state &a, const state &b)
{
  return a.cost > b.cost;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    cin >> t;
    int diff;
    int ans;
    int i,j;
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        mx[0] = a;
        mx[1] = b;
        mx[2] = c;
        priority_queue<state> pq;
        state st,tmp;
        st.arr[0] = 0;
        st.arr[1] = 0;
        st.arr[2] = c;
        st.cost = 0;
        ms(dp,false);
        dp[0][0][c] = true;
        pq.push(st);
        diff = 500;
        ans = 99999999;
        while(!pq.empty()){
            st = pq.top();
            pq.pop();
            forl(i,0,3){
               if(st.arr[i] == d){
                    ans = st.cost;
                    diff=0;
                    break;
               }else if(st.arr[i] < d && d-st.arr[i] < diff){
                   diff = d-st.arr[i];
                   ans = st.cost;
               }
            }
            if(diff==0)
                break;
            forl(i,0,3){
                forl(j,0,3){
                    if(i==j)
                        continue;
                    int mn = min(st.arr[i], mx[j]-st.arr[j]);
                    if(mn == 0)
                        continue;
                    tmp = st;
                    tmp.arr[i] -= mn;
                    tmp.arr[j] += mn;
                    tmp.cost += mn;
                    if(!dp[tmp.arr[0] ][tmp.arr[1]][tmp.arr[2]]){
                        dp[tmp.arr[0] ][tmp.arr[1]][tmp.arr[2]] = true;
                        pq.push(tmp);
                    }
                }
            }
        }
        //cout << ans << " " << d-diff << endl;
        printf("%d %d\n",ans,d-diff);
    }
    return 0;
}
