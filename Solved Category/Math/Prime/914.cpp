
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
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

#define upper 1000002

vector<int> prime;
bool mark[1000002];
void sieve ()
{

	unsigned long int i,j;

	memset (mark, true, sizeof (mark));

	mark [0] = mark [1] = false;

	for (  i = 4; i < upper; i += 2 ) mark [i] = false;

	for (  i = 3; i * i <= upper; i += 2 ) {
		if ( mark [i] ) {
			for ( j = i * i; j < upper; j += 2 * i ) 
				mark [j] = false;
		}
	}

	prime.clear ();
	prime.push_back (2);

	for (  i = 3; i < upper; i += 2 ) 
	{
		if ( mark [i] ) prime.push_back (i);
	}

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	sieve();
	int sz = prime.size();
	int t;
	cin >> t;
	int a,b;
	int lo,hi,m;
	int l,h;
	//cout << sz << endl;
	int ch;
	while(t--)
	{
		cin >> a >> b;
		lo = 0;
		hi = sz-1;
		while(lo<hi)
		{
			l = (lo+hi)/2;
			ch = prime[l];
			if(prime[l] >= a &&(l==0 || prime[l-1]<a))
			{
				break;
			}
			if(prime[l] > a)
			{
				hi = l;
			}
			else if(prime[l] < a)
			{
				lo = l+1;
			}
			if(lo+1==hi)
			{
				if(prime[lo] >= a)
				{
					l = lo;
				}
				else if(prime[hi] >= a)
					l = hi;
				else
					l = -1;
				break;
			}
		}

		lo = 0;
		hi = sz-1;
		while(lo<hi)
		{
			h = (lo+hi)/2;
			ch = prime[h];
			if(prime[h] <= b &&(h==sz-1 || prime[h+1]>b))
			{
				break;
			}
			if(prime[h] > b)
			{
				hi = h-1;
			}
			else if(prime[h] < b)
			{
				lo = h;
			}
			if(lo+1==hi)
			{
				if(prime[hi] <= b)
				{
					h = hi;
				}
				else if(prime[lo] <= b)
				{
					h = lo;
				}
				else
					h = -1;
				break;
			}
		}
		if(l == -1 || h == -1 || l>h)
		{
			cout << "No jumping champion\n";
			continue;

		}
		int prev = prime[l];
		//cout << prev << endl;
		map<int,int> mp;
		for(l++;l <= h;l++)
		{
			if(prime[l] > b)
				break;
			mp[abs(prime[l]-prev)]++;
		    //cout << "diff :" << *l-prev << " " << mp[abs(*l-prev)] << endl;
			prev = prime[l];
		}
		map<int,int>::iterator it;
		int mxd=-1;
		for(it = mp.begin(); it != mp.end();it++)
		{
			if(it->second > mxd)
			{
				mxd = it->second;
				a = it->first;
			}
		}
	//	cout << mxd << " " << a << endl;
		if(mxd == -1)
		{		
			cout << "No jumping champion\n";
			continue;
		}

		b=0;

		for(it = mp.begin(); it != mp.end();it++)
		{
			if(it->second == mxd && it->first != a)
			{
				b = 1;
				break;
			}

		}
		if(b==1)
		{
			cout << "No jumping champion\n";
			continue;
		}
		else
			cout << "The jumping champion is " << a << endl;

	}
     return 0;
}
