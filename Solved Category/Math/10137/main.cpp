
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int d,c;
    int n;
    int arr[MAX];
    int i,j;
    int high,low;
    while(cin >> n){
        if(n==0)
            break;
        int sum=0;
        forl(i,0,n){
            scanf("%d.%d",&d,&c);
            d *= 100;
            arr[i] = d+c;
            sum += d+c;
        }
        int low = floor(sum*1.0/n);
        if(low*n < sum){ //difference between any two amounts is maximum 1 cent 
            high = low+1;
        }else{ //equal
            high = low;
        }
        int lesser=0;
        int upper=0;
        forl(i,0,n){
            if(arr[i] == low || arr[i] == high)
                continue;
            if(arr[i] < low){
                lesser += low-arr[i];
            }else{
                upper += arr[i]-high;
            }
        }
        int ans = max(upper, lesser);
        cout << "$" << ans/100 << ".";
        if(ans%100<10)
            cout << "0";
        cout << ans%100 << endl;
        
    }
    return 0;
}
