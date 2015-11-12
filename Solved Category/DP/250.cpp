
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



double in[50][50];
double rcal[50][50];
double ccal[50][50];
double rdiff[50];
double cdiff[50];
int main(void)
{
	int m,n,i,j,ca=1;
	double rmin,cmin,a,b,c;
	while(1)
	{
		cin >> m >> n;
		if(!m && !n)
			break;
		for(i = 0; i < m;i++)
		{
			for(j = 0; j < n;j++)
			{
				cin >> in[i][j];

			}
		}

		

		for(i = 0; i < n; i++)
			ccal[0][i] = in[0][i];
		for(i = 1; i < m;i++)
		{
			for(j = 0; j < n ; j++)
				ccal[i][j] = ccal[i-1][j] + in[i][j];
		}

		for(i = 0; i < m; i++)
			rcal[i][0] = in[i][0];
		for(i = 1; i < n;i++)
		{
			for(j = 0; j < m ; j++)
				rcal[j][i] = rcal[j][i-1] + in[j][i];
		}

		//cout << rcal[4][n-1] << endl;

		cdiff[0] = ccal[m-1][0];
		rdiff[0] = rcal[0][n-1];

		for(i = 1; i < n;i++)
		{
			cdiff[i] = cdiff[i-1] + ccal[m-1][i];
		}

		for(i = 1; i < m;i++)
		{
			rdiff[i] = rdiff[i-1] + rcal[i][n-1];
		}

		cmin = fabs(cdiff[n-1] - cdiff[0]);
		rmin = fabs(rdiff[m-1] - rdiff[0]);
		


		int d1 = 1,d2 = 1;

		
		for(i = 1; i < m-1;i++)
		{
			a = rdiff[i] - rcal[i][n-1];
			b = rdiff[m-1] - rdiff[i];

			c = fabs(a-b);

			if(c <= rmin+1e-6)
			{
				rmin = c;
				d2 = i+1;
			}
		}

		a = rdiff[m-2];

		if(a <= rmin+1e-6)
		{
			rmin = a;
			d2 = m;
		}

		for(i = 1; i < n-1;i++)
		{
			a = cdiff[i] - ccal[m-1][i];
			b = cdiff[n-1] - cdiff[i];
			c = fabs(a-b);
			if(c <= cmin+1e-6)
			{
				cmin = c;
				d1 = i+1;
			}
		}

		a = cdiff[n-2];
		if(a <= cmin+1e-6)
		{
			cmin = a;
			d1 = n;
		}


		cout << "Case " << ca++ << ": center at (" << d2 << ", " << d1 << ")\n";

	}

	return 0;
}