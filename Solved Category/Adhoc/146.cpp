#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> v;
vector<char> ::iterator it;

int main(void)
{

	char in[50];

	int len,i,j,k,check;

	int count;

	while(1)
	{
		gets(in);

		len = strlen(in);

		if( len == 1 && in[0] == '#')
		{
			break;
		}

		check = 0;

		count = 0;

		for( i = 0; i < len; i++)
		{

			v.push_back(in[i]);
		}

		do
		{
			if( count == 1)
			{
				for( it = v.begin(); it != v.end(); it++)
				{
					check = 1;
					cout << *it ;
				}

				break;
			}

			count++;

		}while(next_permutation(v.begin(),v.end()));

		if( check == 0)
		{
              cout << "No Successor";
		}

		cout << endl;

		v.clear();

			
	}


	return 0;
}