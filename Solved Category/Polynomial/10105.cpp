#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>

using namespace std;
int save[15];
int n,k;
int calculate()
{

	int i,p,j;

	double c,d;
	c=d=1;
    j = 1;
	for(i = 0,j = 1; i < k || j <= n; i++,j++)
	{
		 if(j <=n)
           c *= j;  
		 if(i >= k)
			 continue;
         p = save[i];
		 int k1;
		 for(k1 = 1; k1 <= p; k1++)
		 {
			 d *= k1;
			 if( !fmod(c,d) && (d!=1) )
			{	
				 c/=d;
				 d=1;
			}
		 }

		 if( !fmod(c,d) && (d!=1) )
		 {	
				c/=d;
				d=1;
		 }
	}

	 if( !fmod(c,d) && (d!=1) )
	 {	
				c/=d;
				d=1;
	}

	return c;


}
int main(void)
{
	
	int i;
	int res;
	while(cin >> n >> k)
	{
		for(i = 0; i < k; i++)
		{
			cin >> save[i];
		}

		res = calculate();

		cout << res << endl;

	}
	return 0;
}