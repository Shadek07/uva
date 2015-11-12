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
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000001
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

unsigned long  int res;
unsigned long int ans[1000001];
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

unsigned long count_factors(unsigned long n)
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
				  res ++;
				  n1 /= pr;				  
			  }
			  base = sqrt(n1);
			  i++;
		  }
		  if(n1>1)
			  res++;
		  return res;
}

int main(void)
{
 	
 	 unsigned long  int n,i,temp;
 	
 	 sieve();

	 unsigned long  int pr;

	ans[1] = 0;
	for(i = 2;i<=1000000;i++)
	{
		ans[i] = ans[i-1] + count_factors(i);
	}

	
 	while(cin >> n)
 	{
		  cout << ans[n] << endl;       
    }
 	return 0;
}
