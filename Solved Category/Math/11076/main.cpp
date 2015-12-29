

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

#define MAX 100005
#define INF 9999999
typedef pair<int, vi> vip;
map<vip, ull> mp;
map<vip, bool> mpb;
int n;
ull fact[13];
/**
fill up n positions using n digits in vector v where some digits may have more than one occurrence
*/
ull getCount(int n, vi v){
    ull cnt = 1;
    ull i;
    cnt = fact[n];
    for(i=0;i<10;i++){
        if(v[i] >1){
            cnt /= fact[ v[i] ];
        }
    }
    return cnt;
}
ull doit(vip vp){
    
   if(vp.first == n){
        return 0;
   }
   int ind = vp.first;
   vip tmp = vp;
   int i;
   ull sum=0;
   vector<int> v = vp.second;
   vector<int> vtmp;
   if(mpb[vp]){
        return mp[vp];
   }
   forl(i,0,10){
       if(v[i] > 0){
            vtmp = v;
            vtmp[i]--;
            tmp = vp;
            tmp.first++;
            tmp.second = vtmp;
            ull val = i*pow(10.0,n-ind-1); //place a digit(i) at index 'ind' from left
            sum += getCount(n-ind-1,vtmp)*val;
            sum += doit(tmp);
       }
   }
   mpb[vp]=true;
   mp[vp] = sum;
   return sum;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    ull ans;
    int a;
    fact[0] = fact[1] = 1;
    ull i;
    forl(i,2,13){
        fact[i] = fact[i-1]*i;
    }
    while(cin >> n){
        if(n==0)
            break;
        //mp.clear();
        //mpb.clear();
        /**
        v[i] is the counter of digit i
        */
        vector<int> v(10,0);
        forl(i,0,n){
            scanf("%d",&a);
            v[a]++;
        }
        vip vp;
        vp.first = 0;
        vp.second = v;
        ans = doit(vp);
        //cout << ans << endl;
        printf("%llu\n",ans);
    }
    return 0;
}

