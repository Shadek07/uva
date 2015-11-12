#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

#define Forth 1
#define Right 2
#define Left 3

char in[8][10];

char fnd[8] = "IEHOVA#";

int m,n;

int position(int i,int j,char c)
{
	if(i-1 >= 0)
		if(in[i-1][j] == c)
			return Forth;
	if(j-1 >= 0)
		if(in[i][j-1] == c)
			return Left;

	if(j+1 < n)
		if(in[i][j+1] == c)
			return Right;

}

int main(void)
{
	int t;

	cin >> t;

	int i,j,k,p;

	while(t--)
	{
		cin >> m >> n;
		getchar();

		for(i=0;i<m;i++)
		{
			gets(in[i]);
		}

		for(i=0;i<n;i++)
			if(in[m-1][i] == '@')
				break;
		int a,b;

		a = m-1;

		b = i;
		for(j = 0; j < 7; j++)
		{
			p = position(a,b,fnd[j]);
			if(p == 1)
			{
				cout << "forth";
				a--;
			}
			if(p == 2)
			{
				cout << "right";
				b++;
			}
			if(p == 3)
			{
				cout << "left";
				b--;
			}
			if( j == 6)
				cout << endl;
			else
				cout << " ";

		}

	}
	return 0;
}