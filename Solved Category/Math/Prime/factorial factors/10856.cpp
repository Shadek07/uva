#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>


#define LL unsigned long long
#define MAXN 2703664
using namespace std;




unsigned long int *primeFactor;


int main(void)
{
 	
 		unsigned long  int n,i,j,temp;
 	
		unsigned long  int pr;
		int ca = 1;
		bool ch;
		primeFactor = new unsigned long int[MAXN];
		for(i = 0;i<MAXN;i++)
			primeFactor[i] = 0;
		for (i = 2; i * i < MAXN; i++)
		{
			// we didn't iterate over the whole interval cause we only need to
			// know a single prime factor for each composite
			if (primeFactor[i] == 0)
			{
				for ( j = i * i; j < MAXN; j += i)
					primeFactor[j] = i;
			}
		}
		for(i = 2; i < MAXN; i++)
		{
			if (primeFactor[i] == 0)
				primeFactor[i] = i;// sets every prime factor of a prime number as the prime it self
		}
		unsigned long int *nPrimeFactors;// we'll have the result here
		nPrimeFactors = new unsigned long int[MAXN];
		unsigned long int *nFactFactors;//total number of prime factors for x! in nFactFactors[x]

		nFactFactors = new unsigned long int[MAXN];
		nPrimeFactors[0] = nPrimeFactors[1] = 0;
		for (i = 2; i < MAXN; i++)
			nPrimeFactors[i] = 1 + nPrimeFactors[i / primeFactor[i]];

	
	
	nFactFactors[0] = 0;
	nFactFactors[1] = 0;
	nFactFactors[2] = 1;
	for(i = 3; i<2703664;i++)
	{
		nFactFactors[i] = nFactFactors[i-1]+nPrimeFactors[i];
	}
	//cout << nFactFactors[4] << endl;
	long int n1;
 	while(cin >> n1)
 	{
		 if(n1 < 0)
			break;
		 n = n1;
		 cout << "Case " << ca++ << ": ";
		 if(n == 0)
		 {
			 cout << "0!\n";
			 continue;
		 }
		  
	     int low,high,mid;
		 low = 0;
		 high = 2703663;
		 ch = false;
		 unsigned long int out = 2703664;
		 do
		 {
			 mid = (low+high)/2;

			 if(nFactFactors[mid] < n)
			 {
				 low = mid+1;
			 }
			 else
			 {
				 high = mid;
			 }

		 }while(low+1<high);

		 
		 if(nFactFactors[low]==n)
			 cout << low << "!" << endl;
		 else if(nFactFactors[high]==n)
			 cout << high <<"!"<< endl;
		 else
			 cout << "Not possible.\n";

    }
 	return 0;
}
