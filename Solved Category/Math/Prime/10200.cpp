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
#define pi acos(-1.0)
#define N 1000001
#define LL unsigned  long
using namespace std;
bool mark [N];
vector<unsigned long int> primeList;
multiset<unsigned  long int> st;
#define eps 1e-9
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
	
	primeList.push_back(2);
	for(i = 3;i< N;i++)
	if(mark[i])
	primeList.push_back(i);	

}



bool prime_check(unsigned  long n)
{
		  int i = 0;
		  unsigned long temp = n;
		  int sz = primeList.size();
		  unsigned long  int pr;
		  unsigned long int n1 = n;
		  unsigned long int base;
		  bool ch;
		  st.clear();
		  base = sqrt(n1*1.0);
		  while(i<sz && primeList[i] <= base)
		  {
			  pr = primeList[i];
			  ch = false;
			  while(n1%pr == 0)
			  {
				  n1 /= pr;	
                  st.insert(pr);			  
			  }
			  base = sqrt(n1*1.0);
			  i++;
		  }
		  if(n1>1)
			  st.insert(n1);
		  if(st.size()==1)
		  return true;
		  else
		  return false;
          		  
}

int main(void)
{
 	
 	 unsigned   long int a,b,n,i,temp;
 	int cnt;
 	int total;
 	double perc;
 	 sieve();
 	 //freopen("1.txt","r",stdin);
	 //freopen("2.txt","w",stdout);
 	 int dp[10001];
 	 dp[0] = 1;
 	 for(i = 1;i<= 10000;i++)
 	 {
                 n = i*i + i + 41;
                 if(n<1000001)
                 {
                              if(mark[n])
                              dp[i] = dp[i-1]+1;
							  else
								  dp[i] = dp[i-1];
                 }
                 else
                 {
                     if(n==2)
                     dp[i] = dp[i-1]+1;
                     else if(n%2==0)
                     dp[i] = dp[i-1];
                     else 
					 {
						 if(prime_check(n))
							dp[i] = dp[i-1]+1;
						 else
							 dp[i] = dp[i-1];
					 }
                 }
           
     }
     
     while(cin >> a >> b)
     {
           cnt = dp[b];
           if(a>0)
           cnt -= dp[a-1];
           
         
           total = b-a+1;
           perc = (cnt*100.0)/total;
		   perc += eps;
           printf("%.2lf\n",perc);
                    
     }
	 
 	return 0;
}
