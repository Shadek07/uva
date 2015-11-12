#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

bool comp(char a, char b)
{
	if(tolower(a) == tolower(b))
	{
		if((a >= 'A' && a <= 'Z' )&&(b >= 'a' && b <= 'z'))
			return true;
		else
			return false;
	}
	else
		return tolower(a) < tolower(b);
}

int main(void)
{
	int t,len;
	char in[100];

	cin >> t;
	
	getchar();

	while(t--)
	{
		gets(in);
		len = strlen(in);
		sort(in,in+len,comp);
		do
		{
			cout << in << endl;
		}
		while(next_permutation(in,in+len,comp));
	}

	return 0;
}