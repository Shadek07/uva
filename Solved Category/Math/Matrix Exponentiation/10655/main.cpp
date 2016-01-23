
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
long long int p,q;
long long **square( long long **c)
{
	long long ** a = new  long long*[2];
	int i,j,k,x,y;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long long[2];
		for(j = 0; j < 2; j++)
			a[i][j] = 0;
	}

	

	for(i = 0;i<2;i++)
	{
		for(j = 0;j<2;j++)
		{
			for(x = 0;x<2;x++)
			{
				a[i][j] = (a[i][j] + (c[i][x]*c[x][j]));
			}
		}
	}
	return a;
}

long long **fastexp(long long **b,long long power)
{
	long long **a = new long long*[2];
	long i,j;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long long[2];
		//for(j = 0; j < 3; j++)
			//a[i][j] = 0;
	}

	if(power == 1)
	{
		a[0][0] = p;
		a[0][1] = -q;
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

		long long ** c = new long long*[2];
		long long ** d = new  long long*[2];
		long i,j,x;
		for(i = 0; i < 2; i++)
		{
			c[i] = new long long[2];
			d[i] = new long long[2];
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
					d[i][j] = (d[i][j] + (c[i][x]*b[x][j]));
				}
			}
		}
		return d;
	}
	
}
int spaceCount(char in[100]){
    int i;
    int cnt=0;
    for(i=0;in[i];i++){
        if(in[i] == ' ')
            cnt++;
    }
    return cnt;
}
int main(void)
{	
	long long **a = new long long*[2];
	long i,j;
	long long int n;
	char in[100];
	long long ans;
	for(i = 0; i < 2; i++)
	{
		a[i] = new long long[2];
		//for(j = 0; j < 2; j++)
			//a[i][j] = 0;
	}

	while(gets(in))
	{
            
			int cnt = spaceCount(in);
			if(cnt==1)
                break;
            sscanf(in,"%lld %lld %lld",&p,&q,&n);
            if(n == 0){
                cout << 2 << endl;
                continue;
            }
            if(n==1){
                cout << p << endl;
                continue;
            }
            if(n==2){
                ans = -2*q;
                ans += p*p;
                cout << ans << endl;
                continue;
            }
			a[0][0] = p;
			a[0][1] = -q;
			a[1][0] = 1;
			a[1][1] = 0;
			/*
             a^n + b^n = (a^(n-1)+b^(n-1))*(a+b) - a*b*(a^(n-2)+b^(n-2))
             Xn = a^n + b^n
             Xn = pXn-1 - qXn-2
             (p -q)      (Xn-1)         (pXn-1 + qXn-2)         (Xn  )
                    x               =                      =
             (1 0)      (Xn-2)         ( Xn-1 +  0  )          (Xn-1)
             from this
                (p -q)^(n-1)     (X1)     (Xn)   
                            x          =
                (1 0)           (X0)     (Xn-1)
             Using fast exponentation you can solve this. X0 = 2 and X1 = p */
              
			long long ** c = new long long*[2];
			for(i = 0; i < 2; i++)
			{
				c[i] = new long long[2];
			}

			c = fastexp(a,n-1);

			cout << (c[0][0]*p + c[0][1]*2LL) << endl;
	}

	return 0;
}
