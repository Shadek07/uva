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

int main(void)
{

	int t,ca = 1;

	char in[10001],c;
	char out[10001];
	char two[101][101];
	char one[500],three[500],four[500];
	int i,j,k,l,len,len1,b,ind;

	int down;

	int index;

	int check;

	double a;

	cin >>  t;
	getchar();

	while(t--)
	{
		gets(in);

		len = strlen(in);

		j = 0;

		for( i = 0; i < len ; i++)
		{
			if( (in[i] >= 'A' && in[i] <= 'Z' ) || ( in[i] >= 'a' && in[i] <= 'z'))
			{
				out[j] = in[i];
				j++;
			}
		}

		out[j] = '\0';

		len1 = j;

		cout << "Case #" << ca++ <<":\n";


		a = sqrt(len1);

		check = 1;

		if( a - int(a) == 0 )
		{

			ind = 0;

			index = a;

			for( i = 0; i < a; i++)
			{
				for( j = 0; j < a; j++)
				{
					two[i][j] = out[ind];
					ind++;

				}

				two[i][j] = '\0';
			}

            down = a-1;

			for( i = 0; i < a ; i++)
			{
				for( j = 0; j < a; j++)
				{
					one[j] = two[j][i];
				}
				one[j] = '\0';

				for( j = 0; j < a; j++)
				{
					three[j] = two[index-i-1][index-j-1];
					
				}

				three[j] = '\0';

				for( j = 0; j < a; j++)
				{
					four[j] = two[index-j-1][index-i-1];
				}
				four[j] = '\0';

				if( strcmp(two[i],one) != 0)
				{
					check = 0;
				}
				if( strcmp(two[i],three) != 0)
				{
					check = 0;
				}
				if( strcmp(two[i],four) != 0)
				{
					check = 0;
				}

				if( check == 0)
				{
					cout << "No magic :(\n";
					break;
				}
				


			}

			if( check == 1)
			{
				cout << a << endl;
			}




			
		}
		else
		{
			if( check == 1)
			{

				cout << "No magic :(\n";
			}
		}

	}


	return 0;
}