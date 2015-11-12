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

bool comp(char a,char b)
{
	if(a>b)
		return true;
	else
		return false;
}
int main(void)
{
	char in[15];
	char large[15];
	int len,i,j,k;
	unsigned long long int a,b;
	while(gets(in))
	{
		len = strlen(in);
		strcpy(large,in);
		if(len == 1 && in[0] == '0')
		{
			cout << "0 - 0 = 0 = 9 * 0\n";
			continue;
		}
		
		sort(in,in+len);
		sort(large,large+len,comp);
		//cout << in << endl;
		//cout << large << endl;
		//a = atoi(large);
		a = 0;
		i = 0;
		while(i<len)
		{
                a = a*10 + large[i]-'0';
                i++;
    }
		k = 0;
		i = 0;
		while(in[i++] == '0')
		k++;
		b = in[i-1]-'0';
		b = b*pow(10.0,k);
		while(i<len)
		{
			b = b*10 + (in[i]-'0');
			i++;
		}

		cout << a << " - " << b << " = " << a-b << " = " << "9 * " << (a-b)/9 << endl;

	}
	return 0;
}
