#include<iostream>
#include<cmath>
#include<cstdio>
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

	int N,T,P;

	int t;
	cin >> t;
	while(t--)
	{
		scanf("%d %d %d",&N,&T,&P);
		
		n = T - N*P + N - 1;
		m = N-1;
		//cout << n << " " << m << endl;
		printf("%.0lf\n",nCr(n,m));
		
    
	}
	return 0;
}