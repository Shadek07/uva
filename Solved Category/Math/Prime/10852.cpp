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
#define N 10001

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


int main(void)
{
 	
 	 unsigned long  int n,i,temp;
 	
 	 sieve();

	 unsigned long  int pr;
	int t;

	ans[1] = 0;
	cin >> t;
	int sz;
	sz = primeList.size();
	
	unsigned long low,high,mid;
 	while(t--)
 	{
		  cin >> n;
		  /*low = 0;
		  high = sz-1;
		  temp = 99999;
		  while(low<high)
		  {
			  mid = (low+high)/2;
			  pr = primeList[mid];
			  if(2*pr>n)
			  {
				  high = mid-1;
				  if(pr<temp)
					  temp = pr;
			  }
			  else
			  {
				  low = mid+1;
			  }
		  }

		  cout << temp << endl;*/
		  for(i = 0;primeList[i] <= n;i++)
		  {
			  if(2*primeList[i] > n)
			  {
				  cout << primeList[i] << endl;
				  break;
			  }
		  }

		         
    }
 	return 0;
}
