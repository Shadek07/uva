#include<iostream>
#include<cmath>
using namespace std;

double nCr(int n,int m)
{
	int k;
	register int i,j;
	double c,d;
	c=d=1;
	k=(m>(n-m))?m:(n-m);
	for(j=1,i=k+1;(i<=n);i++,j++)
	{
		c*=i;
		d*=j;
		if( !fmod(c,d) && (d!=1) )
		{ c/=d;
		d=1;
		}
	}
	return c;
}
/* A sample main function */
int main(void)
{
	int n,m;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(!n && !m)
			break;
		//cout << n <<" things taken " << m << " at a time is "; 
		printf("%.0lf\n",nCr(n,m));
		//cout << " exactly.\n";
    
	}
	return 0;
}