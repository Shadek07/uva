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

unsigned long  int res;
long int mu[N];
long int M[N];
int num;
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

bool is_square_free(unsigned long n)
{
	  int i = 0;
	  unsigned long temp = n;
	  int sz = primeList.size();
	  unsigned long  int pr;
	  unsigned long int n1 = n;
	  unsigned long int base;
	  if(n == 2)
	  {
		  num=1;
		  return 1;
	  }
	  base = sqrt(n1);
	  while(i<sz && primeList[i] <= base)
	  {
		  pr = primeList[i];
		  int cnt=0;
		  while(n1%pr == 0)
		  {
			  n1 /= pr;	
			  cnt++;
			  if(cnt>1)
				  return false;
			  num++;
		  }
		  i++;
		  base = sqrt(n1);
	  }
	  if(mark[n1])
		  num++;
	  return true;		  
}

int main(void)
{	
 	 unsigned long  int n,i,temp,m,a,b,n1;	
 	 sieve();
	 mu[1] = 1;
	 M[1] = 1;
	 for(i = 2;i<N;i++)
	 {
		 num = 0;
		 if(!is_square_free(i))
		 {
			 mu[i] = 0;
			 M[i] = M[i-1];
		 }
		 else
		 {
			 if(num%2==0)
				 mu[i] = 1;
			 else
				 mu[i] = -1;
			 M[i] = M[i-1] + mu[i];
		 }
	 }
	 int ca = 1;
	 //ofstream cout("2.txt");
	 while(cin >> n && n)
	 {
	      printf("%8d%8d%8d\n",n,mu[n],M[n]);
	 }
 	return 0;
}
