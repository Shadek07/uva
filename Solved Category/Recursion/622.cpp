
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

long int integer(string s);
long int component(string s);
long int factor(string s);
long int expression(string s);

long int integer(string s)
{
	int len,i;
	len = s.size();
	long int a = 0;
	for(i = 0;i<len;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			a = a*10 +(s[i]-'0');
		else
			return -1;
	}

	return a;

}
long int component(string s)
{
	int len;
	int i;
	len = s.size();
	long int a,b;
	bool ch = false;
	int cnt = 0;
	for(i = 0;i<len;i++)
	{
		if(s[i] == '(')
			cnt++;
		else if(s[i] == ')')
			cnt--;
		else if(i>0 && i<len-1 && s[i] == '*' && cnt==0)
		{
			ch = true;
			a = factor(s.substr(0,i));
			if(a != -1)
			{
				b = component(s.substr(i+1,len-i-1));
				if(b != -1)
					return a*b;
				else
					return -1;
			}
			else
				return -1;
		}
	}

	if(ch==false)
		return factor(s);

}

long int factor(string s)
{
	int len;
	len = s.size();
	if(s[0] == '(' && s[len-1] == ')')
	{
		return expression(s.substr(1,len-2));
	}
	else
		return integer(s);

}

long int expression(string s)
{
	int len;
	int i;
	len = s.size();
	long int a,b;
	bool ch = false;
	int cnt= 0;
	for(i = 0;i<len;i++)
	{
		if(s[i] == '(')
			cnt++;
		else if(s[i] == ')')
			cnt--;

		else if(i>0 && i<len-1 && s[i] == '+' && cnt==0)
		{
			ch = true;
			a = component(s.substr(0,i));
			if(a != -1)
			{
				b = expression(s.substr(i+1,len-i-1));
				if(b != -1)
					return a+b;
				else
					return -1;
			}
			else
				return -1;
		}
	}

	if(ch==false)
		return component(s);

}
int main(void)
{
	int t;
	char in[10000];
	string s;
	cin >> t;
	getchar();
	long int a;
	while(t--)
	{
		gets(in);
		s = in;
		a = expression(s);
		if(a == -1)
			cout << "ERROR\n";
		else
			cout << a << endl;

	}
	return 0;
}
