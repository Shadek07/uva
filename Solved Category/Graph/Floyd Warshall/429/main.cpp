
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

#define MAX 201
#define INF 9999999

char words[MAX][11];
map<string,int> mp;
int dis[MAX][MAX];
int ok(char f[11], char s[11]){
    int len = strlen(f);
    int i;
    int cnt=0;
    forl(i,0,len){
        if(f[i] != s[i])
            cnt++;
    }
    return cnt==1;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    int ca=1;
    cin >> t;
    int i,j,k;
    getchar();
    getchar();
    char in[50];
    while(t--){
       
       if(ca>1){
            //cout << endl;
            printf("\n");
       }
       mp.clear();
       int ind=1;
       i=0;
       while(true){
           gets(words[i]);
           if(words[i][0] == '*')
               break;
           mp[words[i]] = ind++;
           i++;
       }
       forl(i,0,ind){
           forl(j,0,ind){
               if(i == j){
                  dis[i][j] = 0;
                  continue;
               }
               dis[i][j] = INF;
               if(strlen(words[i]) == strlen(words[j]) && ok(words[i], words[j])){
                   dis[i][j] = 1;
               }
           }
       }
       //floyd-warshall
       forl(k,0,ind){
           forl(i,0,ind){
               forl(j,0,ind){
                   if(i != j && i != k && j != k && dis[i][k] != INF && dis[k][j] != INF){
                       dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                   }
               }
            }
       }
       while(gets(in)){
            if(strlen(in) == 0){
                break;
            }
            istringstream is(in);
            string a,b;
            is >> a >> b;
            int x,y;
            x = mp[a]-1;
            y = mp[b]-1;
            int ans = 0;
            if(a != b){
                ans = dis[x][y];
            }
            cout << a << " " << b << " " << ans << endl;
            //printf("%s %s %d\n",a.c_str(),b.c_str(),ans);
       } 
       ca++;
    }
    return 0;
}
