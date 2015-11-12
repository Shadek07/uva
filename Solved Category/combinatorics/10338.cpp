#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

vector<int> v1;
int cnt[30];
char in[30];

double nCr(int n)
{
	int k;
	register int i,j;
	double c,d;
	int ind,ind1,size;
	size = v1.size();

	c=d=1;

	ind = ind1 = 0;

	for(i = 1;i <= n;i++)
	{
		c*=i;

		if(ind < size)
		{
			if(ind1 == 0)
			{
				ind1 = 1;
			}
			else
			{
				ind1++;
			}

			d*=ind1;

			if(ind1 == v1[ind])
			{
				ind1 = 0;
				ind++;
			}
		}

		if( !fmod(c,d) && (d!=1) )
		{	
			c/=d;
			d=1;
		}
	}

	return c;
}


int main(void)
{
	int n,m,i,j,len;
	int ca = 1;
	int t;
	cin >> t;
	getchar();
	while(t--)
	{
		gets(in);
		len = strlen(in);
		memset(cnt,0,sizeof(cnt));
		for(i = 0; i < len; i++)
		{
			cnt[in[i] - 'A']++;

		}

		for(i = 0; i < 26; i++)
		{
			if(cnt[i] > 1)
			{
				v1.push_back(cnt[i]);
			}
		}
		

		cout << "Data set " << ca++ << ": ";
		printf("%.0lf\n",nCr(len));

		v1.clear();
		
		
    
	}
	return 0;
}