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

using namespace std;

#define max1(a,b) a > b ?a :b

int lis[2005];
int lds[2005];


int wg[2005];
int main(void)
{
	int test,n,i,j;
	cin >> test;

	while(test--)
	{
		cin >> n;

		if(n == 0)
		{
			cout << 0 << endl;
			continue;
		}

		for(i = 0; i < n;i++)
		{
			cin >> wg[i];
		}

		reverse(wg,wg+n);

		for(i = 0; i < n; i++)
		{
			lis[i] = 1;
			lds[i] = 1;
		}

		for(i = 0;i < n-1; i++)
		{
			for(j = i+1; j < n; j++)
			{
				if(wg[j] > wg[i] && lis[i] + 1 > lis[j])
				{
					lis[j] = lis[i] + 1;
				}
				if(wg[j] < wg[i] && lds[i] + 1 > lds[j])
				{
					lds[j] = lds[i] + 1;
				}
			}
		}

		

		int mx = 0;

		for(i = 0;i<n;i++)
		{
			mx = max1(mx,lis[i]+lds[i]-1);
			//cout << lis[i] << " " << lds[i] << endl;
		}
		cout << mx << endl;

	}

	return 0;
}