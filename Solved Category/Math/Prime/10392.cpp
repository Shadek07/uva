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
#define N 1000001
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long long int res;
unsigned long long int ans[1000001];
set<unsigned long long int> st;
multiset<unsigned long long int> st1;
set<unsigned long long int>::iterator it;
void sieve ()
{

	unsigned long long int i,j;

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

void prime_factors(unsigned long long n)
{
		  int i = 0;
		  unsigned long long int temp = n;
		  int sz = primeList.size();
		  unsigned long long int pr;
		  unsigned long long int n1 = n;
		  unsigned long long int base;
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
 	 unsigned long long int n,i,temp,m,a,b,n1;	
 	 sieve();
	 //cout << primeList.size();
	 int t;
	 int len;
	 int ca = 1;
	 char in[100];
	 while(gets(in))
	 {
		if(in[0] == '-')
			break;
		m = 0;
		len = strlen(in);
		for(i = 0;i<len;i++)
		{
			m = m*10 + (in[i]-'0');
		}
		st.clear();
		st1.clear();
		prime_factors(m);
		int ans=99999,cnt;
		for(it = st1.begin();it != st1.end();it++)
		{
			cout << "    " << *it << endl;

		}
		cout << endl;

		


	 }
 	return 0;
}
