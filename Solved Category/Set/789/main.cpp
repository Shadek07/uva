
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

map<string,int> mp;
set<int> st[100001];
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char c;
    //c = getchar();
    //getchar();
    char in[10000];
    int ind;
    
    ind = 1;
    int len;
    int i,j,k;
    int line=1;
    vector<string> v;
    string s;
    s = 'a';
    s += 'b';
    //cout << s << endl;
    bool fir=true;
    while(gets(in)){
        if(fir){
            c = in[0];
            fir = false;
            continue;
        }
        len = strlen(in);
        for(i=0;i<len;i++){
            
            if(in[i] >= 'A' && in[i] <= 'Z'){
                if(in[i] == c){
                   s = in[i];
                    for(j=i+1;j<len;j++){
                        if(in[j] >= 'A' && in[j] <= 'Z'){
                            s += in[j];
                        }else{
                            break;
                        }
                    }
                    if(!mp[s]){
                        mp[s] = ind++;
                        v.pb(s);
                        st[ind-1].insert(line);
                        
                    }else{
                        st[ mp[s]].insert(line);
                    } 
                }else{
                    for(j=i+1;j<len;j++){
                        if(in[j] >= 'A' && in[j] <= 'Z'){
                                
                        }else{
                            break;
                        }
                    }
                }
                i = j;
            }
        }
        line++;
    }
    sort(all(v));
    int sz = v.size();
    set<int>::iterator it;
    for(i=0;i<sz;i++){
        cout << v[i];
        j = mp[v[i]];
        for(it = st[j].begin(); it != st[j].end(); it++){
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
