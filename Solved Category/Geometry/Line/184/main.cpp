
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

#define MAX 100005
#define INF 9999999

int comp(pii p1, pii p2){
    if(p1.first < p2.first){
        return true;
    }
    if(p1.first == p2.first && p1.second < p2.second)
        return true;
    return false;
    
}

pii get_slope_pair(pii p1, pii p2){
    if(p1.first == p2.first){
        return {p1.first, 0};
    }else if(p1.second == p2.second){
        return {0, p1.second};
    }else{
        int y = p1.second - p2.second;
        int x = p1.first - p2.first;
        int gcd = __gcd( abs(y),abs(x));
        y /= gcd;
        x /= gcd;
        if(x<0 && y < 0)
        return {-y,-x};
        else if( (x>0 && y < 0) || (x<0 && y>0)){
            return {-abs(y), abs(x)};
        }else{
            return {y,x};
        }
    }
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    vpii vp, vpans;
    int a,b;
    int n;
    int i,j,k;
    //save a point with its slope in a line
    //first pair is slope (y/x), second pair is point
    map< pair<pii,pii>, int> mpslope;
    
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        vp.clear();
        
        vp.pb({a,b});
        n = 1;
        while(true){
            cin >> a >> b;
            if(a== 0 && b == 0)
                break;
            vp.pb({a,b});
            n++;
        }
        sort(all(vp), comp);
        bool found = false;
        bool fir = true;
        mpslope.clear();
        for(i=0;i<n;i++){
            for(j=i+1;j<n-1;j++){
                pii slope_pair = get_slope_pair(vp[i], vp[j]);
                 
                if(mpslope[make_pair(slope_pair, vp[j])]){ 
                    //the line with this slope and with this point is already calculated
                    continue;
                }
                vpans.clear();
                vpans.pb(vp[i]);
                vpans.pb(vp[j]);
                for(k=j+1;k<n;k++){
                    if(vp[i].first == vp[j].first && vp[i].first == vp[k].first){
                        vpans.pb(vp[k]);
                        continue;
                    }else if(vp[i].second == vp[j].second && vp[i].second == vp[k].second){
                        vpans.pb(vp[k]);
                        continue;
                    }
                    int x1 = vp[i].first;
                    int y1 = vp[i].second;
                    int x2 = vp[j].first;
                    int y2 = vp[j].second;
                    if(vp[k].first*(y1-y2) - vp[k].second*(x1-x2) == x1*(y1-y2) - y1*(x1-x2)){
                        vpans.pb(vp[k]);
                    }
                }
                if(vpans.size()>2){
                    found = true;
                    if(fir)
                    cout << "The following lines were found:\n";
                    fir = false;
                    for(k=0;k<vpans.size();k++){
                       //cout << "(   " << vpans[k].first << ",   " << vpans[k].second << ")";
                       printf("(%4d,%4d)",vpans[k].first,vpans[k].second);
                       mpslope[make_pair(slope_pair, vpans[k])] = 1;
                       //save this line slope in map
                    }
                    cout << endl;
                }
            }
        }
        if(!found)
            cout << "No lines were found\n";
        
    }
    return 0;
}

