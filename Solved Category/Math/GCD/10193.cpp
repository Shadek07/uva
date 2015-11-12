
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

int gcd(unsigned long int a,unsigned long int b)
{
    unsigned long int c;

	if( a < b)
	{
		c = a;
		a = b;
		b = c;
	}

    while(1)
    {
  		c = a%b;
  		if(c==0)
  		  return b;
  		a = b;
  		b = c;
    }
}
int main(void)
{
	int len,i,j,k;
	int t;
	char in[1000];
	cin >> t;
	getchar();
	unsigned long int a,b;
	int ca = 1;
	while(t--)
	{
		gets(in);
		len = strlen(in);
		len--;
		a = 0;
		i = 0;
		while(len>=0)
		{
			a = a + (in[i]-'0')*pow(2.,len);
			len--;
			i++;
		}

		gets(in);
		len = strlen(in);
		len--;
		b = 0;
		i = 0;
		while(len>=0)
		{
			b = b + (in[i]-'0')*pow(2.,len);
			len--;
			i++;
		}
		
		a =gcd(a,b);
		cout << "Pair #" << ca++ << ": ";
		if(a>1)
			cout << "All you need is love!\n";
		else
			cout << "Love is not all you need!\n";


	}
	return 0;
}