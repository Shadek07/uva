#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<cstdio>
using namespace std;

int main(void)
{
	char in[10000],*p;
	int c[1000];
	int x[1000];
	int i,j,a,b,n,k,k1,d;
	long int ans;
	while(gets(in))
	{
			i = 0;
			p = strtok(in," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");
			while( p != NULL)
			{

				a = atoi(p);
				c[i++] = a;
				p = strtok(NULL," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");
			}
			n = i-1;

			gets(in);
			i = 0;
			p = strtok(in," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");
			while( p != NULL)
			{

				a = atoi(p);
				x[i++] = a;
				p = strtok(NULL," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");
			}

			ans = 0;

			b = x[0];

			for(j = n,k=0; j >= 0; j--,k++)
			{
				d = pow(abs(x[0]),j);

				if(j == 0)
				{
					ans += c[k];
					break;
				}

				

				else if(b < 0)
				{
					
					if(j%2 == 1)
					{
						ans += (c[k]*d)*-1;
						
					}
					else
					{
						ans += (c[k]*d);

					}
				}
				else if( b > 0)
				{
					ans += (c[k]*d);

				}
			}

			cout << ans;

			for(k = 1; k < i; k++)
			{
				ans = 0;

				b = x[k];

				for(j = n,k1 = 0; j >= 0; j--,k1++)
				{
					d = pow(abs(b),j);

					if(j == 0)
					{
						ans += c[k1];
						break;
					}

					 
					else if(b < 0)
					{
						
						if(j%2 == 1)
						{
							ans += (c[k1]*d)*-1;
							
						}
						else
						{
							ans += (c[k1]*d);

						}
					}
					else if( b > 0)
					{
						ans += (c[k1]*d);

					}
				}

				cout << " " << ans;

			}

			cout << endl;

	}

	return 0;
}