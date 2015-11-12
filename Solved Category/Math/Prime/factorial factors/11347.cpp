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

void prime_factors( long n)
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
 	 unsigned long  long int n,i,temp,m,a,b,n1,cnt;	
 	 sieve();
	 int t;
	 cin >> t;
	 getchar();
	 int ca = 1;
	 char in[100];
	 long int i1,temp1;
	 //ofstream cout("2.txt");
	 bool ch;
	 while(t--)
	 {
		gets(in);
		st.clear();
		st1.clear();
		cnt = 0;
		n = 0;
		int len = strlen(in);
		i =0;
		while(in[i] >= '0' && in[i] <= '9')
		{
			n=n*10 + (in[i]-'0');
			i++;
		}
		
		cnt = len - i;
		if(n%cnt == 0)
		{
			for(i1 = n;i1>= cnt; i1-= cnt)
			{
				prime_factors(i1);
			}
		}
		else
		{
			temp1 = n%cnt;
			for(i1 = n;i1>= temp1; i1-= cnt)
			{
				prime_factors(i1);
			}

		}
		b = 1;
		ch = true;
		for(it = st.begin(); it != st.end(); it++)
		{
			a = count(st1.begin(),st1.end(),*it);
			a++;
			temp1=a;
			if(b > pow(10.0,18)/temp1)
			{
				ch = false;
				break;
			}
			else
				b *= a;

		}
		cout << "Case " << ca++ << ": ";
		if(b == 0 || ch==false)
			cout << "Infinity\n";
		else
			cout << b << endl;
		


	 }
 	return 0;
}
