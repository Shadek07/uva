#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int in1[8];
char gl[260];
int ln;
int ind;
char in[105][260];
void permute(int n)
{
	int ok,i,k;
    ok = 0;
	while(ok == 0)
	{
		k = 0;
		for(i = 0; i < ln;i++)
		{
			if(gl[i] == '#')
				cout << in[ind];
			if(gl[i] == '0')
			{
				cout << in1[k++];
			}
			
		}
		cout << endl;

		ok = 1;
		for(i = 0; i < n;i++)
		{
			if(in1[i] != 9)
			{
				ok = 0;
				continue;
			}
		}

		for(i = n-1; i> 0;i--)
		{
			if(in1[i] < 9)
			{
				in1[i]++;
				break;
			}
			if( in1[i] == 9)
			{
				in1[i] = 0;
				if(in1[i-1] < 9)
				{
					in1[i-1]++;
					break;
				}
				else
					continue;
				
			}
		}
	}
}

int main(void)
{
	int i;
	int dic,rule,j,k,cnt,len,k1;
	
    char rl[260];

	while(scanf("%d",&dic) == 1)
	{

		getchar();
		for(i = 0; i < dic; i++)
		{
			gets(in[i]);
		}
		cout << "--" << endl;
		cin >> rule;
		getchar();
		for(i = 0; i < rule; i++)
		{
			gets(rl);
			strcpy(gl,rl);

			len = strlen(rl);
			ln = len;
			cnt = 0;
			for(j = 0; j < len; j++)
			{
				if(rl[j] == '0')
					cnt++;
			}

			if(cnt > 1)
			{
				for(j = 0; j < dic;j++)
				{
					ind = j;
					for(i = 0; i < cnt; i++)
					{
						in1[i] = 0;
					}

					permute(cnt);
				}

			}
			else
			{
				for(j = 0; j < dic;j++)
				{
					ind = j;
					for(k1 = 0; k1 < 10; k1++)
					{

						for(k = 0; k < len; k++)
						{
							if(rl[k] == '#')
							{
								cout << in[j];
							}
							if(rl[k] == '0')
							{
								cout << k1;
							}

						}

						cout << endl;
					}
					
				}

			}
			

		}


	}



	return 0;
}
