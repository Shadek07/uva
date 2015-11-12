
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

unsigned long long int n,m;

unsigned long long MOD;
long long int ad[20];
long long int fd[20];
long long int base[20][20];
int d;

unsigned long long **square(unsigned long long **c)
{
	unsigned long long ** a = new unsigned long long*[d];
	int i,j,k,x,y;
	for(i = 0; i < d; i++)
	{
		a[i] = new unsigned long long[d];
		for(j = 0; j < d; j++)
			a[i][j] = 0;
	}

	

	for(i = 0;i<d;i++)
	{
		for(j = 0;j<d;j++)
		{
			for(x = 0;x<d;x++)
			{
				a[i][j] = (a[i][j] + (c[i][x]%MOD*c[x][j]%MOD)%MOD)%MOD;
			}
		}
	}

	return a;

}

unsigned long long **fastexp(unsigned long long **b,unsigned long long power)
{
	unsigned long long **a = new unsigned long long*[d];
	long i,j;
	for(i = 0; i < d; i++)
	{
		a[i] = new unsigned long long[d];
	}

	if(power == 1)
	{
		for(i = 0;i<d;i++)
		{
              for(j = 0;j<d;j++)
              {
                    a[i][j] = base[i][j];
              }
        }
		return a;

	}
	else if(power%2 == 0)
	{
		a = fastexp(b,power/2);
		a = square(a);
		return a;
	}
	else if(power%2 == 1)
	{

		unsigned long long ** c = new unsigned long long*[d];
		unsigned long long ** d1 = new unsigned long long*[d];
		long i,j,x;
		for(i = 0; i < d; i++)
		{
			c[i] = new unsigned long long[d];
			d1[i] = new unsigned long long[d];
			for(j = 0; j < d; j++)
			{
				c[i][j] = 0;
				d1[i][j] = 0;
			}
		}		

		c = fastexp(b,power-1);
		for(i = 0;i<d;i++)
		{
			for(j = 0;j<d;j++)
			{
				for(x = 0;x<d;x++)
				{
					d1[i][j] = (d1[i][j]%MOD + (c[i][x]%MOD*b[x][j]%MOD)%MOD)%MOD;
				}
			}
		}
		
		return d1;


	}
	
}
int main(void)
{	
	
    //freopen("2.txt","w",stdout);
	while(cin >> d >> n >> m)
	{

			if(!d && !n && !m)
				break;

			unsigned long long **a = new unsigned long long*[d];
        	long i,j;
        	for(i = 0; i < d; i++)
        	{
        		a[i] = new unsigned long long[d];
        		for(j = 0;j<d;j++)
        		      a[i][j] = 0;       		
        	}

			for(i = 0;i<d;i++)
			{
                  cin >> a[0][i];
            }
            
            for(i = 1;i<d;i++)
            a[i][i-1] = 1;
            
            for(i = 0;i<d;i++)
            {
                  cin >> fd[i];
            }

			if(n <= d)
			{
                 cout << fd[n-1] << endl;
                 continue;
            }
            
            for(i = 0;i<d;i++)
            {
                  for(j = 0;j<d;j++)
                  {
                        base[i][j] = a[i][j];
                  }
            }
			MOD = m;
			unsigned long long ** c = new unsigned long long*[d];
			for(i = 0; i < d; i++)
			{
				c[i] = new unsigned long long[d];
				
			}

			c = fastexp(a,n-d);
			
			unsigned long long int ans = 0;
			for(i = 0;i<d;i++)
			{
                  ans = (ans + (fd[d-i-1]%MOD*c[0][i]%MOD)%MOD)%MOD;
            } 
            cout << ans << endl;
            
			
	}

	return 0;
}
