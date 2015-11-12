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
//#define INT_MAX 2147483647
//#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000002
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];

void sieve ()
{
	int i,j;
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

	for ( i = 3; i < N; i += 2 ) {
		if ( mark [i] ) primeList.push_back (i);
	}

	//printf ("%d\n", primeList.size ());
}



int make_sum(int n)
{

	int i = 0;

	while(n>0)
	{
		i += n%10;
		n /= 10;
	}

	return i;

}



int dp[1000002];

int main(void)

{
	 int t,t1 = 0,t2 = 0;

	 

	

	 
	 sieve ();

     //cout << primeList.size() << endl;
	 //cout << primeList[83] << endl;

	 int total = 0,i;

	 int check , c;

	 check = c = 1;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	for(i = 3; i <= 1000000; i++)
	{
		 c = make_sum(i);
		 if(mark[i] && mark[c])
		 	    dp[i] = dp[i-1] + 1;
		 else
			 dp[i] = dp[i-1];

	}

	scanf("%d", &t);

	 while( t--)
	 {

		 scanf("%d %d",&t1,&t2);
		 

		printf("%d\n",dp[t2] - dp[t1-1]);
		   

	 }



	return 0;
}

