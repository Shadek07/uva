#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

double nCr(int n,int m,int r,int s)
{
	int k;
	register int i,j,p,q;
	int x,y;
	double c,d;
	c=d=1;
	k=(m>(n-m))?m:(n-m);
	x=(s>(r-s))?s:r-s;
	for(j=1,p=1,q=x+1,i=k+1;(i<=n)||(q<=r);i++,p++,q++,j++)
	{
		if(i<=n)
		{
			c*=i;
			d*=j;
			c /= d;
			d = 1;
			/*if( !fmod(c,d) && (d!=1) )
			{	
				c/=d;
				d=1;
			}*/
		}
		if(q<=r)
		{
			c*=p;
			d*=q;
			c /= d;
			d = 1;
			/*if( !fmod(c,d) && (d!=1) )
			{	
				c/=d;
				d=1;
			}*/

		}
	}
	return c;
}
/* A sample main function */
int main(void)
{
	int n,m;
	int p,q;
	 double p1,q1;
	while((scanf("%d %d %d %d",&n,&m,&p,&q)) == 4)
	{
		
	
		//cout << n <<" things taken " << m << " at a time is "; 
		p1 = nCr(n,m,p,q);
		//q1 = nCr(p,q);
		printf("%.5lf\n",p1);
		//cout << " exactly.\n";
    
	}
	return 0;
}