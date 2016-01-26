
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

#define MAX 100005
#define INF 9999999
int cnt[6];
int half;
bool found;
int prefix[7];
bool vis[7][60001];
void doit(int ind, int sum){
    if(found)
        return;
    if(ind == -1){
        if(sum == half){
            found = true;
        }
        return;
    }
    
    if(vis[ind][sum])
        return;
    int j=0,i;
    int tmp = sum + prefix[ind];
    int a = (half - tmp);
    
    if(a>0){
        /**
        we need to use at least one coin from (ind)'th coin
        */
        j = (a+ind)/(ind+1);
    }
    for(i=cnt[ind];i>=j;i--){
        tmp = sum + (ind+1)*(i);
        if(tmp <= half)
        doit(ind-1, tmp);
    }
    
    vis[ind][sum] = true;
    
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    int i,j,k;
    bool all_zero;
    int ca=1;
    int a,b,c;
    while(true){
        all_zero = true;
        int sum=0;
        forl(i,0,6){
            scanf("%d",&cnt[i]);
            sum += (i+1)*cnt[i];
            if(cnt[i] != 0)
                all_zero = false;
        }
        if(all_zero)
            break;
        printf("Collection #%d:\n",ca++);
        if(sum&1){
            cout << "Can\'t be divided.\n\n";
            continue;
        }
        forl(i,0,6){
           if(cnt[i] <= 1)
            continue;
           a = (i+1)*cnt[i]; 
           b = 0;
           forl(j,0,6){
               if(i == j)
                continue;
               b += (j+1)*cnt[j];
           }
           /**
           when total value in i'th coin is greater than the sum of other coin's value
           it is better to distribute some pairs of i'th coin between 2 participants 
           */
           if(a > b){
               a = a-b;
               k = a/(2*(i+1));
               cnt[i] -= 2*k;
               break;
           }
        }
        sum = 0;
        forl(i,1,7){
            sum += (i)*cnt[i-1];
        }
        if(sum&1){
           cout << "Can\'t be divided.\n\n";
           continue; 
        }
        half = sum/2;
        found = false;
        prefix[0] = 0;
        forl(i,1,6){
            prefix[i] = prefix[i-1] + (i)*cnt[i-1];
        }
        ms(vis,false);
        doit(5, 0);
        if(found){
            cout << "Can be divided.\n\n";
        }else{
            cout << "Can't be divided.\n\n";
        }
    }
    return 0;
}
