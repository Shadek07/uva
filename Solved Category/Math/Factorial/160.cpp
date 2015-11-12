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
#define N 105
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


int main ()
{
	sieve ();
	

	int s, t;
	int cases = 0;

	int i;

	int N1;
	int count,res;
	int newLine;

	while (cin >> N1) 
	{
		if(N1 == 0)
			break;

	
		printf("%3d! =",N1);

		if(N1<=1)
		{
			printf("  0\n");
			continue;
		}

		i = 0;
		count = 0;
		newLine = 0;

		while(1)
		{
			res = 0;
			int tmp = primeList[i];
			int t1 = primeList[i];
			if(primeList[i] <= N1)
			{
				while(tmp <= N1)
				{
					res += floor(N1*1.0/tmp);
					tmp *= t1;
				}

			}
			else
				break;

			if(newLine == 1)
			{
				cout << "      ";   //six spaces
				newLine = 0;
			}

			printf("%3d",res);
			count++;
			if(count == 15)
			{
				count = 0;
				cout << endl;
				newLine = 1;
			}

			i++;     //finding next prime
		}

		if(count > 0)
		cout << endl;
	
	}

	return 0;
}

