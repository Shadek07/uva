#include<iostream>
#include<cstring>

using namespace std;

char dic[1000][11];
int dic_len[1000];
char test[1000];
int count1[1000][26];
int count2[26];

int main(void)
{

	int i,j,k,m,n;
	string s1;
	string::iterator it;

	i = 0;
	int cnt;

	while(1)
	{
		gets(dic[i]);
		j = strlen(dic[i]);

		dic_len[i] = j;

		if( j == 1 && dic[i][0] == '#')
			break;
		i++;
	}

	memset(count1,0,sizeof(count1));

	for( m = 0; m < i; m++)
	{
          for( n = 0; n < dic_len[m] ; n++)
		  {
			  count1[m][dic[m][n]-97]++;
		  }
	}

	while(1)
	{
		gets(test);
		j = strlen(test);

		if( j == 1 && test[0] == '#')
			break;

		s1 = test;

		cnt = 0;

		for(it = s1.begin();it < s1.end();it++)
		{
			if(*it == ' ')
			{
				s1.erase (it);
			}
		}

		memset(count2,0,sizeof(count2));

		strcpy(test,s1.c_str());

		j = strlen(test);

		for( n = 0; n < j ; n++)
		{
			  count2[test[n]-97]++;
		}


        int ch;
	
		for( n = 0; n < i; n++)
		{

			ch = 1;
			for( m = 0; m < 26; m++)
			{
				if( !(count2[m] >= count1[n][m]) )
				{
					ch = 0;
					break;
				}

			}

			if( ch == 1)
				cnt++;

		}

		cout << cnt << endl;
	}



	return 0;
}