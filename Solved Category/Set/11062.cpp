
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<list>
using namespace std;


set<string> st;
set<string> ::iterator it;
int main(void)
{
	char in[100000];
	char temp[10000];
	int i,j,k,len;
	bool t;
	char c;
	int cnt = 0;
	t = false;
	string s1,s,s2;
	j = 0;
	
	while(gets(in))
	{
		len = strlen(in);
		if(len == 0)
			continue;
		if(t==false)
			j = 0;
		for(i = 0;i<len;i++)
		{
			if(in[i] >= 'a' && in[i] <= 'z')
			{
				temp[j++] = in[i];
				if(i == len - 1)
				{
					temp[j] = '\0';
					j = 0;
					t = false;
					st.insert(temp);
					cnt++;

				}
			}
			else if(in[i] >= 'A' && in[i] <= 'Z')
			{
				temp[j++] = tolower(in[i]);
				if(i == len - 1)
				{
					temp[j] = '\0';
					j = 0;
					t = false;
					st.insert(temp);
					cnt++;

				}
			}
			else if(in[i] == '-')
			{
				if(i == len-1)
				{
					t = true;
				}
				else
					temp[j++] = in[i];
			}
			else
			{
				if(j>0)
				{
					temp[j] = '\0';
					j = 0;
					t = false;
					st.insert(temp);
					cnt++;

				}
			}


		}
		if(t == false && j > 0)
		{
			temp[j] = '\0';
			j = 0;
			t = false;
			st.insert(temp);
			cnt++;

		}
		
	}

	for(it = st.begin(); it != st.end();it++)
		cout << *it << endl;
	st.clear();
	return 0;
}
