#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string.h>
#include<algorithm>
using namespace std;
int li;

	char in[30],c;
	char next[30];
	void rev();
int main(void)
{
	int rer,palin,len,i;
	char save[40] = {'A','.','.','.','3','.','.','H','I','L','.','J','M','.','O','.','.','.','2','T','U','V','W','X','Y','5'};
	char digit[10] = {'1','S','E','.','Z','.','.','8','.'};
	while(gets(in))
	{
		len = strlen(in);

		li = len;

		strcpy(next,in);

		//strrev(next);
		rev();


		rer = palin = 0;

		if(strcmp(next,in) == 0)
			palin = 1;
		int ind;
		ind = 0;

		for(i = 0;i < len; i++)
		{
			if(!isdigit(in[i]))
			{
				if(save[in[i]-'A'] != '.')
				{
					next[ind++] = save[in[i] - 'A'];
				}
				//else
					//next[i] = in[i];
			}
			else
			{
				
				if(digit[in[i]-'1'] != '.')
				{
					next[ind++] = digit[in[i] - '1'];
				}
			//	else
				//	next[i] = in[i];

			}
		}

		next[ind] = '\0';
	//	cout << next << endl;

		//strrev(next);
		li = ind;
		rev();

	//	cout << next << endl;

		if(strcmp(next,in) == 0)
			rer = 1;
		if(!rer && !palin)
		{
			cout << in << " -- " << "is not a palindrome.\n\n";
		}
		if(palin && !rer)
		{
			cout << in << " -- " << "is a regular palindrome.\n\n";

		}
		if(!palin && rer)
		{
			cout << in << " -- " << "is a mirrored string.\n\n";
		}
		if(palin && rer)
		{
			cout << in << " -- " << "is a mirrored palindrome.\n\n";
		}

	}
	return 0;
}

void rev()
{
	int i,j;

	char c;
	for(i = 0,j = li-1;i<j;i++,j--)
	{
		c = next[i];
		next[i] = next[j];
		next[j] = c;
	}
}