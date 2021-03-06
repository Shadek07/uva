
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

#define MAX 1005
#define INF 9999999

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t;
    char in[MAX];
    int cnt[10];
    cin >> t;
    getchar();
    int i,j,k,ca=1;
    int sum;
    while(t--){
        gets(in);
        k = strlen(in);
        ms(cnt,0);
        sum=0;
        forl(i,0,k){
            cnt[in[i]-'0' ]++;
            sum += in[i]-'0';
        }
        printf("Case %d: ",ca++);
        k = cnt[3] + cnt[6] + cnt[9];
        if(k == 0){
           
           bool found=false;
           forl(i,1,10){
               if(i == 3 || i == 6 || i ==  9|| cnt[i] == 0){
                    continue;
               }
               if((sum-i)%3 == 0){
                  found = true;
                  break;
               }
                
           }
           if(found){
               printf("S\n");  
           }else{
               printf("T\n"); 
           }
           continue;
        }
        if(sum%3 != 0)
            k++;
        
        if(k&1){
            printf("S\n");
        }else{
            printf("T\n");
        }
    }
    return 0;
}
