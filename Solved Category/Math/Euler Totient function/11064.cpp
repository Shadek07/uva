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
#define N 47000
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long long int res;
unsigned long int ans[1000001];
set<unsigned long long int> st;
multiset<unsigned long long int> st1;
set<unsigned long long int>::iterator it;
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
		  unsigned long long int temp = n;
		  int sz = primeList.size();
		  unsigned long  long int pr;
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
 	 unsigned long  long int n,i,temp,m,a,b,n1;	
 	 sieve();
	 int t;
	 int ca = 1;
	 //unsigned long  int 
	 //ofstream cout("2.txt");
	 //ofstream f1("3.txt");
	 //ofstream f2("1.txt");
	 
	 /*for(i = 0; i<1000;i++)
	 {
         f1 << i << endl;
   }
   ifstream f3("3.txt");*/
	 while(cin >> m)
	 {
		if(m== 1 || m == 2)
		{
			cout << 0 << endl;
			continue;
		}
		st.clear();
		st1.clear();
		prime_factors(m);
		n = m;
		n1 = 1;
		for(it = st.begin();it != st.end();it++)
		{
			n/= *it;
			temp = count(st1.begin(),st1.end(),*it);
			n1 *= (temp+1);
		}
		for(it = st.begin();it != st.end();it++)
		{
			n *= (*it-1);
		}
		//cout << n1 << endl;
		cout << m-n-n1+1 << endl;
	 }
 	return 0;
}
