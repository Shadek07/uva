#include<iostream>

using namespace std;
#define min(a,b) (a<b?a:b)

bool m[1001][1001];

int part[1010];

char in[1010];
int len;

void calculate()
{
	int i,j,a,b,k;

	len = strlen(in);

	for(i = 0; i < len; i++)
		m[i][i] = true;
	for(i = 0; i < len - 1; i++)
	{
		if(in[i] == in[i+1])
			m[i][i+1] = true;
		else
			m[i][i+1] = false;
	}
	for(k = 2; k < len; k++)
	{
		for(i = 0,j=k; i < len - k; i++,j++)
		{
			if((in[i] == in[j]) && (m[i+1][j-1] == true))
				m[i][j] = true;
			else
			{
				m[i][j] = false;

			}
		}
	}


}

void partition()
{

	int i,j,k;
	int km;
	int min;
	part[0] = 1;
	if(len > 1)
	{
	     if(in[0] == in[1])
			 part[1] = 1;
		 else
			 part[1] = 2;
	}
	for( i = 2; i < len; i++)
	{
		min = 1000000;
		for(j = 0; j <= i; j++)
		{
			if(m[j][i] == true)
			{
				k = 1;
				if(j > 0)
					k += part[j-1];
				if(k < min)
					min = k;
				
			}
		}
		if(min == 1000000)
			part[i] = part[i-1] + 1;
		else

		part[i] = min;
	}

	cout << part[len-1] << endl;

}

int main(void)
{
	int t;

	cin >> t;

	getchar();

	while(t--)
	{
		gets(in);
		calculate();
		partition();		

	}

	return 0;

}

