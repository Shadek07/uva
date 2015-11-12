#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include<fstream>

#define pi acos(-1.0)
#define N 46342
#define LL unsigned long
using namespace std;

bool mark [N];
vector <unsigned long int> primeList;
vector <int> factors [1000 + 10];

unsigned long  int res;
//unsigned long int ans[1000001];
multiset<unsigned long int> st;
set<unsigned long int> st1;
set<unsigned long int>::iterator it;
bool t;
bool ch;
unsigned long int m,n;
map<unsigned long int,unsigned long int> mp;

void sieve ()
{
	unsigned long int i,j;

	memset (mark, true, sizeof (mark));

	mark [0] = mark [1] = false;

	for (  i = 4; i < N; i += 2 ) mark [i] = false;

	for (  i = 3; i * i <= N; i += 2 ) {
		if ( mark [i] ) {
			for ( j = i * i; j < N; j += 2 * i ) mark [j] = false;
		}
	}

	primeList.clear ();
	primeList.push_back (2);

	for (  i = 3; i < N; i += 2 )
	{
		if ( mark [i] ) primeList.push_back (i);
	}

}

unsigned long long count_factors(unsigned long n2)
{
		  int i = 0;
		  unsigned long temp = n2;
		  int sz = primeList.size();
		  unsigned long int pr;
		  unsigned long int n1 = n2;
		  unsigned long int base;
		  res = 0;
		  bool ch;
		  base = sqrt(n1*1.0);
		  while(i<sz && primeList[i] <= base)
		  {
			  pr = primeList[i];
			  ch = false;
			  while(n1%pr == 0)
			  {
				  res ++;
				  n1 /= pr;

  				st.insert(pr);
  				st1.insert(pr);
  				if(mp[pr])
  				mp[pr]++;
  				else
  				mp[pr] = 1;

			  }
			  base = sqrt(n1*1.0);
			  i++;
		  }
		  if(n1>1)
		  {
			  res++;
			  st.insert(n1);
			  st1.insert(n1);
			  if(mp[n1])
  				mp[n1]++;
  			 else
  				mp[n1] = 1;
		  }
		  return res;
}

int main(void)
{

	unsigned long long int n1;
    unsigned long long int res,i;
	unsigned long long int a,b;
	unsigned long long int cnt;

	sieve ();
	//ofstream cout("2.txt");
    int ca = 1;
	while(scanf("%d",&n) == 1)
	{

        if(n == 0)
        break;
        st.clear();
		st1.clear();
		mp.clear();
        cout << "Case " << ca++ << ": ";
        if(n == 1)
        {
             cout << 2 << endl;
             continue;
        }
        b = pow(2.0,31)-1;
        if(n == b)
        {
             cout << "2147483648\n";
             continue;
        }
        
        a = count_factors(n);
        if(st1.size() == 1)
        {
              a = *(st1.begin());
              b = pow(a*1.0,mp[a]*1.);
              b += 1;
              cout << b << endl;
              continue;
        }
        else
        {
            b = 0;
            for(it = st1.begin(); it != st1.end();it++)
            {
                   a = *it;
                   a = pow(a*1.0,mp[a]*1.0);
                   b += a;
            }
            cout << b << endl;
        }
		

	}
	return 0;
}
