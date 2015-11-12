#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<string>

using namespace std;

map<string,int> mp;
char in[6];
string s3;
char taken[6];
int inde;
void calculate(char c,int ind,int limit)
{
	int i;
	char c1;
	if(ind > limit)
		return;
	else if(ind == limit)
	{
		s3 = "";
		for(i = 0; i < limit;i++)
		{
			s3 += taken[i];
		}

		mp[s3] = inde++;

		return;
	}
	else
	{
		for(c1 = c;c1 <= 'z';c1++)
		{
			taken[ind] = c1;
			calculate(c1+1,ind+1,limit);
		}
	}

}

void ini()
{
	 int i,j;
	 
	 string s1;

	 inde = 1;
	for(i = 0;i<26;i++)
	{
		s1 = "";
		s1 += char(i+'a');
		mp[s1] = inde++;
	}
}
int main(void)
{
	string s1;

    int i,j;
	ini();
	calculate('a',0,2);
	calculate('a',0,3);
	calculate('a',0,4);
	calculate('a',0,5);
	
	while(gets(in))
	{
		s1 = in;
		cout << mp[s1] << endl;
	}
	

}