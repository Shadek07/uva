
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
int main(void)
{
	int i,j,k;
	int page,a,b,line;
	int n,l,c;
	char word[1001][71];
	char in[100001];
	string s;
	while(cin >> n >> l >> c)
	{
		getchar();
		gets(in);
		s = in;
		istringstream is(s);
		i = 0;
		while(is>>in)
		{
			strcpy(word[i],in);
			i++;
		}
		page = 0;
		j = 0;
		line=0;
		a = 0;
		while(j<i)
		{
			a += strlen(word[j]);
			j++;
			while(a+1+strlen(word[j])<= c)
			{
				a += 1+strlen(word[j]);
				j++;
			}
			line++;
			a = 0;
			if(line == l)
			{
				page++;
				line = 0;
			}

		}
		if(line>0)
			page++;
		cout << page << endl;

	}
	return 0;
}