
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

#define MAX 2001
#define INF 9999999

bool mall2[MAX][MAX];
int dis[MAX][MAX];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

struct grid{
    int x,y,cost;
    grid(){}
    grid(int a,int b,int c){
        x = a;
        y = b;
        cost = c;
    }
};
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int a,b,i,j,k,x,y;
    int minx, maxx, miny, maxy;
    while(scanf("%d",&a) == 1){
        forl(i,0,2001){
            forl(j,0,2001){
                dis[i][j] = INF;
            }
        }
        if(a == 0)
            break;
        minx = 2001;
        maxx = 0;
        miny = 2001;
        maxy = 0;
        vector<pii> vpii;
        forl(i,0,a){
            scanf("%d %d",&j,&k);
            minx = min(minx,j);
            maxx = max(maxx,j);
            miny = min(miny,k);
            maxy = max(maxy,k);
            vpii.pb({j,k});
            dis[j][k] = 0;
        }
        int ans = INF;
        scanf("%d",&b);
        ms(mall2,false);
        forl(i,0,b){
           scanf("%d %d",&j,&k);
           minx = min(minx,j);
           maxx = max(maxx,j);
           miny = min(miny,k);
           maxy = max(maxy,k);
           mall2[j][k] = true;
        }
        queue<grid> pq;
        forl(i,0,a){
            pq.push(grid(vpii[i].first, vpii[i].second, 0));
        }
        grid p1,p2;
        while(!pq.empty()){
            p1 = pq.front();
            pq.pop();
            if(mall2[p1.x][p1.y] == true){
                ans = min(ans, p1.cost);
                continue;
            }
            forl(i,0,4){
                x = p1.x + dx[i];
                y = p1.y + dy[i];
                
                //prune the search space
                //x,y should be within min-mix limit
                if(x < minx || x > maxx || y < miny || y > maxy)
                    continue;
                if(x>=0 && x<2001 && y >= 0 && y < 2001 && dis[p1.x][p1.y] + 1 < dis[x][y]){
                    pq.push(grid(x,y,dis[p1.x][p1.y] + 1));
                    dis[x][y] = dis[p1.x][p1.y] + 1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
