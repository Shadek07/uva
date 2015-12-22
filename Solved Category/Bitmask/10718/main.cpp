
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
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    ull n,l,u;
    ull i;
    ull one = 1;
    while(cin >> n >> l >> u){
        /**
        we are building answer incrementally from zero
        */
        ull value = 0;
        for(i=31;i>=0;i--){
            if((n&(1<<i))){ //bit is already set in n
                //sum += (1<<i);
                /**
                if we do not want to set this bit
                    and maximum value that we would be able to get is less than l,
                    then we have no other way but to set it although this bit is already
                    set in n
                    maximum value using bits from 0 to i-1 is 2^i - 1
                */
                if(value + (one<<(i)) - 1 < l){
                    value += one<<i;
                }
            }else{
                /**
                to get maximum OR value with n we should try to set this bit
                with a condition that final value is <= u
                */
                if(value + (one<<(i)) <= u){
                    value += one<<i;
                }
            }
            if(i==0)
                break;
        }
        cout << value << endl;
    }
    return 0;
}

