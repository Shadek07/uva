#include<iostream>
#include<cmath>

using namespace std;

long n,m;
long d;

typedef long rt[2][2];
rt a,b,c;


long **square(long **c)
{
	long ** a = new long*[2];
	long i,j;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long[2];
		for(j = 0; j < 2; j++)
			a[i][j] = 0;
	}

	int p,q,r,s;

	p = c[0][0];
	q = c[0][1];
	r = c[1][0];
	s = c[1][1];

	int a1,b,c1,d1;

	a1 = (((p%d)*(p%d))%d + ((q%d)*(r%d))%d)%d;
	b = (((p%d)*(q%d))%d + ((q%d)*(s%d))%d)%d;
	c1 = (((r%d)*(p%d))%d + ((s%d)*(r%d))%d)%d;
	d1 = (((r%d)*(q%d))%d + ((s%d)*(s%d))%d)%d;

	//a1=fmod(a1*1.0, d*1.0);
//b =fmod(b*1.0, d*1.0);
//	c1 =fmod(c1, d*1.0);
//	d1= fmod(d1*1.0,d*1.0);

	a[0][0] = a1;
	a[0][1] = b;
	a[1][0] = c1;
	a[1][1] = d1;

	return a;

     
	//return g;
}

long **fastexp(long **b,long power)
{
	long **a = new long*[2];
	long i,j;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long[2];
		for(j = 0; j < 2; j++)
			a[i][j] = 0;
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

		long ** c = new long*[2];
		long i,j;
		for(i = 0; i < 2; i++)
		{
			c[i] = new long[2];
			for(j = 0; j < 2; j++)
				c[i][j] = 0;
		}

		

		c = fastexp(b,power-1);

		long p1 = c[0][0];
		long p2 = c[0][1];

		c[0][0] = ((c[0][0]%d) + (c[1][0]%d))%d;
		c[0][0] = fmod(c[0][0]*1.0,d*1.0);
		c[0][1] = ((c[0][1]%d) + (c[1][1]%d))%d;
		c[0][1] = fmod(c[0][1]*1.0,d*1.0);
		c[1][0] = fmod(p1*1.0,d*1.0);
		c[1][1] = fmod(p2*1.0,d*1.0);
		return c;


	}
	
}
int main(void)
{

	
	long **a = new long*[2];
	long i,j;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long[2];
		for(j = 0; j < 2; j++)
			a[i][j] = 0;
	}

	while(scanf("%ld %ld",&n,&m) == 2)
	{
		d = pow(2.0,m*1.0);
  
		if(n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		else if( n == 1)
		{
			cout << 1%d << endl;
			continue;
		}

		else
		{

			a[0][0] = 1;
			a[0][1] = 1;
			a[1][0] = 1;
			a[1][1] = 0;

			
			long ** c = new long*[2];
			long i,j;
			for(i = 0; i < 2; i++)
			{
				c[i] = new long[2];
				for(j = 0; j < 2; j++)
					c[i][j] = 0;
			}

			c = fastexp(a,n-1);

			cout << c[0][0] << endl;

		}

	}

	return 0;
}