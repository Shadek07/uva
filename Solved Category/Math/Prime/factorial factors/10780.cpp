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
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 10005
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long  int res;
unsigned long int ans[1000001];
set<int> st;
multiset<int> st1;
set<int>::iterator it;


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

void prime_factors(unsigned long n)
{
		  int i = 0;
		  unsigned long temp = n;
		  int sz = primeList.size();
		  unsigned long  int pr;
		  unsigned long int n1 = n;
		  unsigned long int base;
		  res = 0;
		  bool ch;
		  base = sqrt(n1);
		  while(i<sz && primeList[i] <= base)
		  {
			  pr = primeList[i];
			  ch = false;
			  while(n1%pr == 0)
			  {
				  n1 /= pr;	
				  st1.insert(pr);
				  ch = true;
			  }
			  base = sqrt(n1);
			  i++;
			  if(ch)
				  st.insert(pr);

		  }
		  if(n1>1)
		  {
			  st.insert(n1);
			  st1.insert(n1);
		  }
		  
}

int main(void)
{	
 	 unsigned long  int n,i,temp,m,a,b,n1;	
 	 sieve();
	 int t;
	 cin >> t;
	 int ca = 1;
	 //ofstream cout("2.txt");
	 while(t--)
	 {
		cin >> m >> n;
		st.clear();
		st1.clear();
		prime_factors(m);
		int ans=99999,cnt;
		for(it = st.begin();it != st.end();it++)
		{
			temp = *it;
			cnt = 0;
			n1 = n;
			b = count(st1.begin(),st1.end(),temp);
			a = temp;
			while(n1/a>0)
			{
				cnt += n1/a;
				a *= temp;
			}
			b = cnt/b;
			if(b < ans)
				ans = b;

		}

		cout << "Case " << ca++ << ":\n";
		if(ans != 0)
		cout << ans << endl;
		else
			cout << "Impossible to divide\n";


	 }
 	return 0;
}
