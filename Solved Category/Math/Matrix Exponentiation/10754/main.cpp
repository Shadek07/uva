
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

#define MAX 25
#define INF 9999999

long long int a[MAX];
long long int c[MAX];
long long int n,m,K;

long long int mod1(long long int a)
{
    long long int r = a % m;
    return r < 0 ? r + m : r;
}

long long int mod(long long int a)
{
   long long int b = (a < 0) ? (m - ((-a) % m)) : (a % m);
   return b%m;
}

long long int mult(long long a, long long b){
    
    return ((a%m)*(b%m))%m;
}

vector< vector<long long> > square(vector< vector<long long> > c){
    vector< vector<long long > > a(K+1, vector<long long> (K+1,0));
    int i,j,x;
    forl(i,0,K+1){
        forl(j,0,K+1){
            forl(x,0,K+1){
                a[i][j] = (a[i][j] + c[i][x]*c[x][j])%m;
            }
        }
    }
    return a;
}

vector< vector<long long> > fastexp(vector< vector<long long> >b,long long power)
{
	vector< vector<long long > > a(K+1, vector<long long> (K+1,0));
	vector< vector<long long > > c(K+1, vector<long long> (K+1,0));
	vector< vector<long long > > d(K+1, vector<long long> (K+1,0));
	int i,j,x;

	if(power == 1)
	{
		forl(i,0,K){
            a[0][i] = ::c[i+1]; //global array, not local
        }
        a[0][K] = 1;
        forl(i,1,K){
            a[i][i-1] = 1;
        } 
        a[K][K] = 1;
		return a;
	}
	else if( power%2 == 0)
	{
		//return square(fastexp(b,power/2));
		a = fastexp(b,power/2);
		a = square(a); //a^p = ((a^x))^2 where x is p/2 and p is even
		return a;
	}
	else if(power%2 == 1)
	{
		c = fastexp(b,power-1);
		for(i = 0;i<K+1;i++)
		{
			for(j = 0;j<K+1;j++)
			{
				for(x = 0;x<K+1;x++)
				{
					d[i][j] = (d[i][j] + c[i][x]*b[x][j])%m;
				}
			}
		}
		return d;
	}
	
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    
    
    //http://www.outsbook.com/uva/?page=problem_hints&category=107
    
    int t;
    cin >> t;
    int i,j,k;
    int ca=1;
    while(t--){
        cin >> k >> m >> n;
        K = k;
        if(ca==1){
            ca=0;
        }else{
            cout << endl;
        }
        fore(i,1,k+1){
            cin >> c[i];
            c[i] = mod(c[i]);
            //cout << c[i] << endl;
        }
        forl(i,0,k){
            cin >> a[i];
            a[i] = mod(a[i]);
            //cout << a[i] << endl;
        }
        long long int ans=0;
        if(n < K){
            ans = a[n];
            cout << ans << endl;
        }else{
            vector< vector<long long > > r(k+1, vector<long long> (k+1,0));
            vector< vector<long long > > p(k+1, vector<long long> (k+1,0));
            
            // | c1 c2 ... ck 1 |     |a(k-1)|       |a(k)  |
            // | 1  0  0 ...  0 |     |a(k-2)|       |a(k-1)|
            // | 0  1  0 ...  0 |  x  ...          = 
            // | 0  0  1 ...  0 |                    ...
            // | ....                 |a(0)  |
            // | 0  0  ...    1 |     |c(k+1)|       |c(k+1)|
            
            forl(i,0,k){
                p[0][i] = c[i+1];
            }
            p[0][k] = 1;
            forl(i,1,k){
                p[i][i-1] = 1;
            } 
            p[k][k] = 1;
            r = fastexp(p,n-K+1);
            fore(i,1,K){
                ans = (ans + r[0][i-1]*a[K-i])%m;
            }
            ans = (ans+r[0][K]*c[K+1])%m;
            cout << ans << endl;
        }
    }
    return 0;
}
