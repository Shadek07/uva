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

enum dir {N,E,S,W};

int main(void)
{
	int r,c;
	char in[100][100];
	int i,j,k,a,b;
	int tab[100][100];
	while(cin >> r >> c)
	{
		getchar();
		if(!r && !c)
			break;
		for(i = 0;i<r;i++)
			gets(in[i]);
		bool fir = true;
		for(i = 0;i<r;i++)
		{
			for(j=0;j<c;j++)
				if(in[i][j]=='0')
					tab[i][j]=0;
				else
					tab[i][j]=-1;
		}

		dir d = E;
		a = r-1;
		b = 0;
		while(true)
		{
			if(d==E)
			{
				if(a+1<r && tab[a+1][b] != -1)
				{
					d = S;
					tab[a][b]++;
					a++;
					fir = false;
				}
				else if(b+1<c && tab[a][b+1]!=-1)
				{
					tab[a][b]++;
					b++;
					fir = false;
				}
				else
					d = N;

			}
			else if(d==W)
			{
				if(a-1>=0 && tab[a-1][b] != -1)
				{
					d = N;
					tab[a][b]++;
					a--;
					fir = false;
				}
				else if(b-1>=0 && tab[a][b-1]!=-1)
				{
					tab[a][b]++;
					b--;
					fir = false;
				}
				else
					d = S;

			}
			else if(d==S)
			{
				if(b-1>=0 && tab[a][b-1] != -1)
				{
					d = W;
					tab[a][b]++;
					b--;
					fir = false;
				}
				else if(a+1<r && tab[a+1][b]!=-1)
				{
					tab[a][b]++;
					a++;
					fir = false;
				}
				else
					d = E;

			}
			else//N
			{
				if(b+1<c && tab[a][b+1] != -1)
				{
					d = E;
					tab[a][b]++;
					b++;
					fir = false;
				}
				else if(a-1>=0 && tab[a-1][b]!=-1)
				{
					tab[a][b]++;
					a--;
					fir = false;
				}
				else
					d = W;

			}

			if(fir==false && a == r-1 && b == 0)
				break;
		}

		int res[5]={0};
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(tab[i][j]!=-1&&tab[i][j]<=4)
					res[tab[i][j]]++;
			}
		}
		printf("%3d%3d%3d%3d%3d\n",res[0],res[1],res[2],res[3],res[4]);


	}
	return 0;
}