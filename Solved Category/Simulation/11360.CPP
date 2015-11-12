#include<iostream>

using namespace std;

void inc();
void dec();
void transpose();
void col(int a,int b);
void row(int a,int b);
char mat[9][10],r[20];
int size;

int main(void)
{

	int t,i,j,rule,cn = 1;
	

	cin >> t;


	while(t--)
	{
		cin >> size;
		getchar();

		for( i = 0; i < size; i++)
		{
			gets(mat[i]);
		}

		cin >> rule;
		getchar();

		for( i = 0; i < rule; i++)
		{
             gets(r);
			 if( r[0] == 't')
				 transpose();
			 if( r[0] == 'i')
				 inc();
			 if(r[0] == 'd')
				 dec();
			 if( r[0] == 'r')
			 {
				 row(r[4]-48,r[6]-48);
			 }
			 if( r[0] == 'c')
			 {
				 col(r[4]-48,r[6]-48);
			 }

		}

		cout << "Case #" << cn++ << endl;
		for( i = 0; i < size; i++)
		{
			for( j = 0; j < size; j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}

		cout << endl;

	}

	return 0;
}

void inc()
{
	int i,j,k;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			k = mat[i][j]-48;
			k = k+1;
			k %= 10;
			mat[i][j] = char(k+48);
		}
	}
}

void dec()
{
	int i,j,k;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			k = mat[i][j]-48;
			k = k-1;
		    if( k == -1)
				k = 9;
			mat[i][j] = char(k+48);
		}
	}
}
void transpose()
{
	char tmp[9][10];
	int i,j;
	for( i = 0; i < size; i++)
	{
		for( j = 0; j < size; j++)
		{
			tmp[j][i] = mat[i][j];
		}
	}
	for( i = 0; i < size; i++)
	{
		for( j = 0; j < size; j++)
		{
			mat[i][j] = tmp[i][j];
		}
	}
}

void col(int a,int b)
{
	int i;
	char j;

	for( i = 0;  i < size; i++)
	{
		j = mat[i][a-1];
		mat[i][a-1] = mat[i][b-1];
		mat[i][b-1] = j;
	}
}
void row(int a,int b)
{
	int i;
	char j;

	for( i = 0;  i < size; i++)
	{
		j = mat[a-1][i];
		mat[a-1][i] = mat[b-1][i];
		mat[b-1][i] = j;
	}
}