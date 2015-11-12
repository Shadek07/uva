#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define min(a,b) (a>b?b:a)

char in[1011];
char pal[1011];

int m[1001][1001];
//char in[100][100];

vector<int> v;

int main(void)
{

	int t,t1 = 0;

	int i,j,len,k;

	int a,b,c,d;

	cin >> t;

	getchar();

	while(t--)
	{
		
		gets(in);
		
		len = strlen(in);
		
		
		for(i = 0; i < len; i++)
		{
			m[i][i] = 0;
			
		}

		for(i = 0; i < len - 1; i++)
		{
			if(in[i] == in[i+1])
				m[i][i+1] = 0;
			else
				m[i][i+1] = 1;
		}

		for(k = 2; k < len; k++)
		{
			for(i = 0,j=k; i < len - k; i++,j++)
			{
				if((in[i] == in[j]))
					m[i][j] = m[i+1][j-1];
				else
				{
					a = m[i+1][j-1];
					b = m[i][j-1];
					c = m[i+1][j];
					d = min(a,b);
					d = min(d,c);
					d += 1;
					m[i][j] = d;

				}
			}
		}

		cout << "Case " << ++t1<< ": " << m[0][len-1] << endl;


		

	}

	return 0;
}