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
#define N 32000
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

int gcd(int a,int b)
{
    int c;

	if( a < b)
	{
		c = a;
		a = b;
		b = c;
	}

    while(1)
    {
  		c = a%b;
  		if(c==0)
  		  return b;
  		a = b;
  		b = c;
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
	 unsigned long long int dp[200001];
	 dp[0] = 0;
	 dp[1] = 2;
	 dp[2] = 3;
	 for(i = 3;i<= 200000;i++)
	 {
		m = i;
		st.clear();
		st1.clear();
		prime_factors(m);
		n = m;
		for(it = st.begin();it != st.end();it++)
		{
			n/= *it;
		}
		for(it = st.begin();it != st.end();it++)
		{
			n *= (*it-1);
		}
		dp[i] =dp[i-1] + n;
	 }
	 //cout << dp[199999] << endl;
     while(cin >> m)
     {
               if(m == 0)
                    break;
               if(m==1)
               {
                       cout << 0  << "/" << 1 << endl;
                       continue;
               }
               if(m == 2)
               {
                    cout << 1 << "/" << 1 << endl;
                    continue;
                }
               
               int low,high,mid;
               low = 1;
               high = 200000;
               if(m > dp[199999])
               {
                    n1 = 200000;
                    goto nt;
               }
               
               while(low <= high)
               {
                         //cout << "here?\n";
                         mid = (high+low)/2;
                         if(dp[mid] < m)
                         {
                             low = mid;
                         }
                         else if(dp[mid] > m)
                         {
                              high = mid;
                         }
                         if(mid-1 >= 0 && dp[mid] >= m && dp[mid-1] < m)
                         {
                              n1  = mid;
                              break;
                         }  
               }
               
               //cout << n1 << endl;
               nt:
               int cnt = m - dp[n1-1];
               for(i = 1;i<= n1;i++)
               {
                     if(gcd(i,n1) == 1)
                     {
                                  cnt--;
                                  if(cnt == 0)
                                  {
                                      cout << i<<"/" << n1 << endl;
                                      break;
                                  }
                     }
               }
               
     }	 
 	return 0;
}
