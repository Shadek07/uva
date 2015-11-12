#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cstdlib>

using namespace std;

int cal[1010][1010];

int main(void)
{

	int W,N,i,j;
	int a,b,p1 = 0;
	int t;
	char in[10000],in1[100];
	char *p;


	cin >> t;

	getchar();
	getchar();

	while(t--)
	{
		cin >> W >> N;
		getchar();

		

		int cal[1000][1000];
		/*for(i = 1; i <= W;i++)
		{
			for(j = 1; j <=N; j++)
			{
				cal[i][j] = -1;
			}
		}*/

		memset(cal,-1,sizeof(cal));

		for(i = 1;i<= W;i++)
		{
			gets(in);

			int ln = strlen(in);
			

			p = strtok(in,"! \"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			j = 0;

			while( p != NULL)
			{

				strcpy(in1,p);
				if(j == 0)
				a =	atoi(in1);
				else
				{
					b =	atoi(in1);

				}
				if( j > 0)
				{
					cal[a][b] = 0;
				}

				j++;
				
				p = strtok(NULL,"! \"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			}

		}

		//getchar();
		//getchar();
		/*if(cal[1][1] == 0 || cal[W][N] == 0)
		{
				if(p1 == 0)
					p1 = 1;
				else
					cout << endl;
				cout << 0 << endl;
				continue;

		}*/

		cal[1][1] = 1;

		for(i = 2; i <= N; i++)
		{
			if(cal[1][i] != 0)
			cal[1][i] = cal[1][i-1];  
		}

		for(i = 2; i <= W; i++)
		{
			for(j = 1; j <= N; j++)
			{
				if(cal[i][j] != 0)
				{
					cal[i][j] = 0;
					if(j >= 2)
					{
						cal[i][j] += cal[i][j-1];
					}

					cal[i][j] += cal[i-1][j];
				}
			}
		}

		if(p1 == 0)
			p1 = 1;
		else
			cout << endl;
		cout << cal[W][N] << endl;
	}

	return 0;
}