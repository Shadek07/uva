
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
typedef pair<long long int,long long int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
#define eps 1e-9
set<pii> pnts;
vpii vppnts;

//check whether b is strictly greater than a
bool isGreater(long double a, long double b){ 
    if(a < b-eps)
        return true;
    return false;
}
long double dist(int a, int b){
    ull x = (ull)((vppnts[a].first - vppnts[b].first)*(vppnts[a].first - vppnts[b].first));
    ull y = (ull)((vppnts[a].second - vppnts[b].second)*(vppnts[a].second - vppnts[b].second));
    long double d = (long double)x+y;
    d = sqrt(d);
    return d;
}

long double dist(pii p1, pii p2){
    ull a = (ull)((p1.first-p2.first)*(p1.first-p2.first));
    ull b = (ull)((p1.second-p2.second)*(p1.second-p2.second));
    long double d = (long double)a + b;
    return sqrt(d);
}
int position_sort(pii p1, pii p2){
    if(p1.first < p2.first)
        return 1;
    if(p1.first == p2.first && p1.second < p2.second)
        return 1;
    return 0;
}

long double cross_product(pii p1, pii p2){
    long double ux = p1.first - vppnts[0].first;
    long double uy = p1.second - vppnts[0].second;
    long double vx = p2.first - vppnts[0].first;
    long double vy = p2.second - vppnts[0].second;
    return ux*vy - uy*vx;
}

long double cross_product(pii p0, pii p1, pii p2){
    long double ux = p1.first - p0.first;
    long double uy = p1.second - p0.second;
    long double vx = p2.first - p0.first;
    long double vy = p2.second - p0.second;
    return ux*vy - uy*vx;
}

int angle_sort(pii p1, pii p2){
        
    double temp;
    temp = cross_product(p1,p2);
	if(fabs(temp-0.0)< eps) //when cross_product value is zero
	{
	    //then sort according to closest distance
		return dist(p1,vppnts[0]) < dist(p2,vppnts[0])-eps;
	}
	else
		return temp > 0;
}

//convex hull algorithm, return convex hull perimeter
long double Graham_scan(){
    sort(all(vppnts), position_sort);
    sort(vppnts.begin()+1,vppnts.end(), angle_sort);
    
    vppnts.pb(vppnts[0]);
    int n = vppnts.size();
    int m = 0;
    int i;
    
    vpii hull_pnts;
    for(i=0;i<n;i++){
        /**
        as long as last 2 points in the convex hull and a new point makes clockwise (<0) direction
        remove the latest point in the hull
        */  
        while(m>=2 && isGreater(cross_product(hull_pnts[m-2],hull_pnts[m-1], vppnts[i]),0)){
            m--;
            hull_pnts.pop_back();
        }
        hull_pnts.pb(vppnts[i]);
        m++;    
    }
    int sz =  hull_pnts.size();
    long double dis=0;
    forl(i,0,sz-1){
        dis += dist(hull_pnts[i], hull_pnts[i+1]);
    }
    return dis;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n,i,j;
    int t;
    cin >> t;
    long double d;
    
    long long int a,b;
    set<pii>::iterator it;
    int sz;
    while(t--){
        cin >> d >> n;
        pnts.clear();
        vppnts.clear();
        forl(i,0,n){
            cin >> a >> b;
            pnts.insert({a,b});
        }
        for(it = pnts.begin(); it != pnts.end(); it++){
            vppnts.pb(*it);
        }
        sz = vppnts.size();
        if(sz == 1){
            printf("%.5Lf\n", d);
            continue;
        }
        if(sz == 2){
            long double d1 = 2*dist(0,1);
            if(isGreater(d1,d)){
                printf("%.5Lf\n",d);
            }else{
                printf("%.5Lf\n",d1);
            }
            continue;
        }
        long double dis = Graham_scan();
        if(isGreater(dis,d)){
            printf("%.5Lf\n",d);
        }else{
            printf("%.5Lf\n",dis);
        }
    }
    return 0;
}
