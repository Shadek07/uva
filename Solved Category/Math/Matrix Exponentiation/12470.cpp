
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;

unsigned long long n,m;


#define MOD 1000000009

unsigned long long **square(unsigned long long **c)
{
	unsigned long long ** a = new unsigned long long*[3];
	int i,j,k,x,y;
	for(i = 0; i < 3; i++)
	{
		a[i] = new unsigned long long[3];
		for(j = 0; j < 3; j++)
			a[i][j] = 0;
	}

	

	for(i = 0;i<3;i++)
	{
		for(j = 0;j<3;j++)
		{
			for(x = 0;x<3;x++)
			{
				a[i][j] = (a[i][j] + (c[i][x]%MOD*c[x][j]%MOD)%MOD)%MOD;
			}
		}
	}

	return a;

}

unsigned long long **fastexp(unsigned long long **b,unsigned long long power)
{
	unsigned long long **a = new unsigned long long*[3];
	long i,j;
	for(i = 0; i < 3; i++)
	{
		a[i] = new unsigned long long[3];
		//for(j = 0; j < 3; j++)
			//a[i][j] = 0;
	}

	if(power == 1)
	{
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		a[1][2] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		return a;

	}
	else if( power%2 == 0)
	{
		//return square(fastexp(b,power/2));
		a = fastexp(b,power/2);
		a = square(a);
		return a;
	}
	else if(power%2 == 1)
	{

		unsigned long long ** c = new unsigned long long*[3];
		unsigned long long ** d = new unsigned long long*[3];
		long i,j,x;
		for(i = 0; i < 3; i++)
		{
			c[i] = new unsigned long long[3];
			d[i] = new unsigned long long[3];
			for(j = 0; j < 3; j++)
			{
				c[i][j] = 0;
				d[i][j] = 0;
			}
		}		

		c = fastexp(b,power-1);
		for(i = 0;i<3;i++)
		{
			for(j = 0;j<3;j++)
			{
				for(x = 0;x<3;x++)
				{
					d[i][j] = (d[i][j]%MOD + (c[i][x]%MOD*b[x][j]%MOD)%MOD)%MOD;
				}
			}
		}
		
		return d;


	}
	
}
int main(void)
{	
	unsigned long long **a = new unsigned long long*[3];
	long i,j;
	for(i = 0; i < 3; i++)
	{
		a[i] = new unsigned long long[3];
		//for(j = 0; j < 2; j++)
			//a[i][j] = 0;
	}

	while(scanf("%llu",&n) == 1)
	{

			if(n == 0)
				break;

			if(n == 1)
			{
				cout << 0 << endl;
				continue;
			}
			if(n == 2)
			{
				cout << 1 << endl;
				continue;
			}
			if(n == 3)
			{
				cout << 2 << endl;
				continue;
			}

			a[0][0] = 1;
			a[0][1] = 1;
			a[0][2] = 1;
			a[1][0] = 1;
			a[1][1] = 0;
			a[1][2] = 0;
			a[2][0] = 0;
			a[2][1] = 1;
			a[2][2] = 0;

			
			unsigned long long ** c = new unsigned long long*[3];
			long i,j;
			for(i = 0; i < 3; i++)
			{
				c[i] = new unsigned long long[3];
				//for(j = 0; j < 3; j++)
					//c[i][j] = 0;
			}

			c = fastexp(a,n-3);

			cout << ((c[0][0]*2)%MOD + c[0][1]%MOD)%MOD << endl;
	}

	return 0;
}
