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

using namespace std;

#define M 1<<15

vector<int> primeList,v;



bool prime[100009];

void sieve()
{
	int i,j,k,l,m;
	prime[0] = false;
	prime[1] = false;

	for(i = 4; i< M; i += 2)
	{
		prime[i] = false;
	}

	for(i = 3; i < M; i += 2)
	{
		if(prime[i])
		{
			for(j = i*i; j < M; j += 2*i)
			{
				prime[j] = false;
			}
		}
	}

    
	primeList.push_back (2);

	for (  i = 3; i <= M; i += 2 ) 
	{
		if (prime[i]) primeList.push_back (i);
	}

	int size = primeList.size();

}

int main(void)
{
	memset(prime,true,sizeof(prime));
	int a,b,start,i,j,k,size,s;
	int elem[32001];
	int diff[32001];
	sieve();

	diff[0] = 2;
	elem[0] = 2;
	size = primeList.size();

	for(i = 1;i<size;i++)
	{
		diff[i] = primeList[i]-primeList[i-1];
		if(diff[i] != diff[i-1])
			elem[i] = 2;
		else
			elem[i] = elem[i-1]+1;
	}
	 
	while ( scanf("%d %d", &a, &b)==2 ) 
	{
		if(a==0 && b==0)
			break;
		if( a >= b)
		{
			s = a;
			a = b;
			b = s;
			//continue;
		}

        for(i = 0;i<size;i++)
		{
			if(primeList[i] >= a)
			{
				start = i;
				break;
			}
		}

		for(i = start;primeList[i]<=b;i++)
		{
			if(elem[i]>=3 && elem[i+1] == 2 && primeList[i-elem[i]+1]>=a)
			{
				cout << primeList[i-elem[i]+1];
				for(j =i-elem[i]+2;j<=i;j++)
				{
					cout << " " << primeList[j];
				}
				cout << endl;
			}
		}

	
	}

	return 0;
}