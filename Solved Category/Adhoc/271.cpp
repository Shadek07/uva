#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
char in[300],c;
int main(void)
{

	int len,i,j,k;

	int valid;

	int t;

	while(gets(in))
	{

		len = strlen(in);

		valid = 0;

		t = 0;

		for(i = len-1; i >= 0; i--)
		{
			if(in[i] >= 'p' && in[i] <= 'z')
			{
				valid++;
				
			}

			if((in[i] >= 'C' && in[i] <= 'E')||in[i] == 'I')
			{
				if(valid >= 2)
				{
					valid--;
				}
				else
				{
					valid = 0;
					break;
				}
			}

			if(in[i] == 'N')
			{
				if(valid < 1)
				{
					valid = 0;
					break;
				}
				else
				{
					valid = valid;
					
				}
			}

		}

		
			if(valid == 1)
			cout << "YES\n";
			else
				cout << "NO\n";
		

	}

	return 0;
}