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
#define N 31650
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long long int res;
unsigned long int ans[1000001];
set<unsigned long long int> st;
multiset<unsigned long long int> st1;
multiset<unsigned long long int>::iterator it;
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
			  //ch = false;
			  while(n1%pr == 0)
			  {
				  n1 /= pr;	
				  st1.insert(pr);
				  //ch = true;
			  }
			  base = sqrt(n1);
			  i++;
			  //if(ch)
				  //st.insert(pr);

		  }
		  if(n1>1)
		  {
			  //st.insert(n1);
			  st1.insert(n1);
		  }		  
}

bool is_prime(unsigned long n)
{
	unsigned long i,j,k;
	if(n == 2)
		return true;
	if(n%2 == 0)
		return false;
	for(i = 3;i*i<=n;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int digit_sum(unsigned long a)
{
	int d;
	d = 0;
	unsigned long b = a;
	while(b>0)
	{
		d += b%10;
		b/= 10;
	}
	return d;
}
int main(void)
{	
 	 unsigned long  long int n,i,temp,m,a,b,n1,pre;	
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
	 cin >> t;
	 while(t--)
	 {
		 cin >> m;
		 n = m;
		 while(++n)
		 {
			 if(is_prime(n))
				 continue;
			 a = digit_sum(n);
			 st1.clear();
			 prime_factors(n);
			 b = 0;
			 int f1 = 0;
			 int sum1;
			 for(it = st1.begin();it != st1.end();it++)
			 {
              if(f1 == 0)
              {
                    f1 = 1;
                    pre = *it;
                    sum1 = digit_sum(*it);
                    b += sum1;
              }
              else
              {
                  if(*it == pre)
                  {
                         b += sum1;
                  }
                  else
                  {
                      pre = *it;
                      sum1 = digit_sum(*it);
                      b += sum1;
                  }
              }
            
			 }
			 if(a == b)
			 {
				 cout << n << endl;
				 break;
			 }

		 }
	 }
 	return 0;
}
