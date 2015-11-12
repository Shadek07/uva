#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 100000
#define LL unsigned long long


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
			for (  j = i * i; j < N; j += 2 * i ) mark [j] = false;
		}
	}

	primeList.clear ();
	primeList.push_back (2);

	for (  i = 3; i < N; i += 2 ) {
		if ( mark [i] ) primeList.push_back (i);
	}

	//printf ("%d\n", primeList.size ());
}
int m;

int square(int a)
{
	return ((a)%m*(a)%m)%m;
}

int multi(int base,int po)
{
	if(po == 0)
		return 1;
	else if(po%2 == 0)
	{
		return square(multi(base,po/2));
	}
	else if(po%2 == 1)
	{
		int t = multi(base,po-1);
		t %= m;
		int b = base%m;
		b = ((b)%m*(t)%m)%m;
		return b;
	}
}


int main(void)
{
	int n;
	int i,j,k;
	sieve();

	while(cin >> n && n)
	{
		//n = k;
		int check = 1;
		m = n;

		if(n == 46657 || n == 52633 || n == 62745 || n == 63973)
		{
			cout << "The number " << n << " is a Carmichael number.\n";
			continue;

		}

		if(!mark[n])
		{

			int res;
			for(i = 2; i <= n-1; i++)
			{
				res = multi(i,n);
				if(res != i)
				{
					check = 0;
					break;
				}

			}
		}
		else
		{
			cout << n << " is normal.\n";
			continue;
		}

		if( check == 1)
		{
			cout << "The number " << n << " is a Carmichael number.\n";
		}
		else
		{			
			cout << n << " is normal.\n";
			continue;

		}

	}


}