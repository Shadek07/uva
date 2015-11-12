
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


int MOD;

unsigned long long **square(unsigned long long **c)
{
	unsigned long long ** a = new unsigned long long*[2];
	int i,j,k,x,y;
	for(i = 0; i < 2; i++)
	{
		a[i] = new unsigned long long[2];
		for(j = 0; j < 2; j++)
			a[i][j] = 0;
	}

	

	for(i = 0;i<2;i++)
	{
		for(j = 0;j<2;j++)
		{
			for(x = 0;x<2;x++)
			{
				a[i][j] = (a[i][j] + (c[i][x]%MOD*c[x][j]%MOD)%MOD)%MOD;
			}
		}
	}

	return a;

}

unsigned long long **fastexp(unsigned long long **b,unsigned long long power)
{
	unsigned long long **a = new unsigned long long*[2];
	long i,j;
	for(i = 0; i < 2; i++)
	{
		a[i] = new unsigned long long[3];
		//for(j = 0; j < 3; j++)
			//a[i][j] = 0;
	}

	if(power == 1)
	{
		a[0][0] = 1;
		a[0][1] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
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

		unsigned long long ** c = new unsigned long long*[2];
		unsigned long long ** d = new unsigned long long*[2];
		long i,j,x;
		for(i = 0; i < 2; i++)
		{
			c[i] = new unsigned long long[2];
			d[i] = new unsigned long long[2];
			for(j = 0; j < 2; j++)
			{
				c[i][j] = 0;
				d[i][j] = 0;
			}
		}		

		c = fastexp(b,power-1);
		for(i = 0;i<2;i++)
		{
			for(j = 0;j<2;j++)
			{
				for(x = 0;x<2;x++)
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
	unsigned long long **a = new unsigned long long*[2];
	long i,j;
	int f0,f1,m;
	for(i = 0; i < 2; i++)
	{
		a[i] = new unsigned long long[2];
		//for(j = 0; j < 2; j++)
			//a[i][j] = 0;
	}

    int t;
    cin >> t;
	while(t--)
	{

           cin >> f0 >> f1 >> n >> m;
			
			MOD = pow(10.0,m);

			if(n == 0)
			{
				cout << f0%MOD << endl;
				continue;
			}
			if(n == 1)
			{
				cout << f1%MOD << endl;
				continue;
			}
			

			a[0][0] = 1;
			a[0][1] = 1;
			a[1][0] = 1;
			a[1][1] = 0;
			
			unsigned long long ** c = new unsigned long long*[2];
			long i,j;
			for(i = 0; i < 2; i++)
			{
				c[i] = new unsigned long long[2];
				//for(j = 0; j < 3; j++)
					//c[i][j] = 0;
			}

			c = fastexp(a,n-1);

			cout << (((c[0][0]*(f1)%MOD)%MOD)%MOD + ((c[0][1]*(f0)%MOD)%MOD)%MOD)%MOD << endl;
	}

	return 0;
}
