
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

#define MX 1000000

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

double x;

map<long long int,int> mp;

int main(void)
{
    
    
    double mx = 2147483648;
    //double mx = 100;
    long long int i;
    for(i=-46342;i <= 46342;i++)
	{
		if(i > -2 && i < 2)
			continue;
		long long int a = i;
		long long int p = 2;
		while(i > 0 && a <= mx/i)
		{
			a = a*i;
			if(!mp[a])
			{
				mp[a] = p;
			}
			else if(mp[a] < p)
			{
				mp[a] = p;
			}
			p++;			
		}
		a = i;
		if(i<0)
			mp[i] = 1;
	    p = 3;
		while(i<0 && -a <= mx/(i*i))
		{
			a = a*(i*i);
		    if(!mp[a])
			{
				mp[a] = p;
			}
			else if(mp[a] < p)
			{
				mp[a] = p;
			}
			p+=2;
		}
	}
    
    while(scanf("%lf",&x))
	{
		if(x == 0)
			break;
		if(mp[x])
		{
			printf("%d\n",mp[x]);
		}
		else
			printf("%d\n",1);
			
		
	}
    return 0;
}
