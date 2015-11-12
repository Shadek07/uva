#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;
char in[1009];
int len;
int divide(int by)
{
	int s = 0,i;
	for(i = 0; i < len;i++)
	{
		s = ((s*10 + in[i] - '0')%by);
		s %= by;
	}

	return s;
}
int main(void)
{
	int t,i;
	int all[13],a,ch,b;
	cin >> t;
	getchar();
	while(t--)
	{
		gets(in);
		len = strlen(in);
		cin >> a;
		ch = 1;
		for(i = 0; i < a;i++)
		{
			cin >> b;
			if(divide(b) != 0)
				ch = 0;

		}

		getchar();

		cout << in << " - "; 

		if(ch)
		{
			cout << "Wonderful.\n";
		}
		else
		{
			cout << "Simple.\n";

		}


	}
	return 0;
}