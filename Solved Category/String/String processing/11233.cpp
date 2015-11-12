#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char in[25][25];

char plural[25][25];

char word[25];

int main(void)
{

	
	int L,N;
	
	int i,j,k;

	cin >> L >> N;

	getchar();

	for(i = 0; i < L; i++)
	{
		cin >> in[i] >> plural[i];
	}

	getchar();

	for(i = 0; i < N;i++)
	{
		gets(word);

		int l = strlen(word);

		for(j = 0; j < L; j++)
		{
			if(strcmp(in[j],word) == 0)
			{
				cout << plural[j] << endl;
				goto last;
			}
		}

		

		if(word[l-1] == 'y')
		{
			if(l > 1)
			{
				char c = word[l-2];
				if( !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
				{
					word[l-1] = 'i';
					word[l] = 'e';
					word[l+1] = 's';
					word[l+2] = '\0';
					cout << word << endl;
					goto last;
				}
			}
		}

		if(word[l-1] == 'o' || word[l-1] == 's' || word[l-1] == 'x')
		{
			word[l] = 'e';
			word[l+1] = 's';
			word[l+2] = '\0';
			cout << word << endl;
					goto last;
		}

		if(word[l-1] == 'h')
		{
			if(word[l-2] == 'c' || word[l-2] == 's')
			{
					word[l] = 'e';
					word[l+1] = 's';
					word[l+2] = '\0';
					cout << word << endl;
							goto last;

			}
		}

		word[l] = 's';
		word[l+1] = '\0';

		cout << word << endl;


        last:;
	}


	return 0;
}