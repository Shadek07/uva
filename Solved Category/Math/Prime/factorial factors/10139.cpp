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

unsigned long count_factors(unsigned long n2)
{
		  int i = 0;
		  unsigned long temp = n2;
		  int sz = primeList.size();
		  unsigned long int pr;
		  unsigned long int n1 = n2;
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
				  if(t)
				  {
  					st.insert(pr);
  					st1.insert(pr);
				  }
			  }
			  base = sqrt(n1);
			  i++;
		  }
		  if(n1>1)
		  {
        //if(n1 > n)
        //ch = false;
			  res++;
			  st.insert(n1);
			  st1.insert(n1);
		  }
		  return res;
}

int main(void)
{

	unsigned long int n1;
  unsigned long int res,i;
	unsigned long int a,b;
	unsigned long int cnt;
	
	sieve ();
	//ofstream cout("2.txt");
	
	while(scanf("%d %d",&n,&m) == 2)
	{		
		if(m == 0)
		{
			 cout << m << " does not divide " << n << "!\n";
			 continue;
		}
		if(n>= m)
		{
         cout << m << " divides " << n <<"!\n";
         continue;  
    }
		t = true;
		ch = true;
		res = count_factors(m);
		t = false;
		if(ch == false)
		{
          cout << m << " does not divide " << n << "!\n";
    		st.clear();
    		st1.clear();
    		continue;
   }
		for(it = st1.begin(); it != st1.end();it++)
		{
			a = *it;
			//cout << a << endl;
			b = count(st.begin(),st.end(),a);
			cnt = 0;
			unsigned long int pw;
			pw = a;
			n1 = n;
			while(pw <= n1)
			{
			  cnt += n1 / pw; 
			  if(a<=(n1*1.0/pw))
			  pw *= a;
			  else
				  break;
			}
			if(cnt < b)
			{
				ch = false;
				break;
			}
		}
		if(ch)
		{
			cout << m << " divides " << n <<"!\n";
		}
		else
			cout << m << " does not divide " << n << "!\n";
		st.clear();
		st1.clear();

	}



	return 0;
}
