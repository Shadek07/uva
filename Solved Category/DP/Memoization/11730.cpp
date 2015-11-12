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
#define N 1010
#define LL unsigned long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];
queue<int> qe;
int step[1010];

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

	for ( i = 3; i < N; i += 2 ) 
	{
		if ( mark [i] ) primeList.push_back (i);
	}

	
}

void next()
{
	int i,j,a,b;
		for(i = 2;i < 998;i++)
		{
			a  = i;
			for(j = 0;j < primeList.size();j++)
			{
				b = primeList[j];
				if(b == i)
					continue;
				if(a%b == 0)
				{
					factors[i].push_back(b);
					while(a%b == 0)
						a /= b;
				}
			}
		}

}

int main(void)
{

		int i,j,k,a,b,s,t;
		int ca = 1;
		sieve();
		next();
	

		

		while(1)
		{
			cin >> s >> t;
			if(!s && !t)
				break;
			memset(step,9999999,sizeof(step));
			if(s == t )
			{
				cout << "Case " << ca++ << ": 0" << endl;
				continue;
			}
			if(s == 1)
			{
				cout << "Case " << ca++ << ": -1" << endl;
				continue;

			}
			if(s > t )
			{
				cout << "Case " << ca++ << ": -1" << endl;
				continue;
			}

			qe.push(s);
			step[s] = 0;

			while(!qe.empty())
			{
				a = qe.front();
				qe.pop();
				for(i = 0; i < factors[a].size();i++)
				{
					int d = factors[a][i];
                    if(a+factors[a][i] <= t)
					{
						
						if(step[a] + 1 < step[a + factors[a][i]])
						{
							step[a + factors[a][i]] = step[a] + 1;
							qe.push(a+factors[a][i]);
						}

					}
				}
			}

			if(step[t] < 1000)
				cout << "Case " << ca++ << ": " << step[t] << endl;
			else
				cout << "Case " << ca++ << ": " << -1 << endl;


		}
}