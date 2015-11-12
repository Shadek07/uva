#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
	int t,len;
	char in[10];
	cin >> t;
	getchar();
	while(t--)
	{
		gets(in);

		len = strlen(in);

		if(len == 5)
		{
			cout << 3 << endl;
		}
		else
		{
			if((in[0] == 'o' && in[2] == 'e')||(in[1] == 'n' && in[2] == 'e')||(in[0] == 'o' && in[1] == 'n'))
			{
				cout << 1 << endl;

			}
			else
			{
				cout << 2 << endl;
			}
		}

	}
	return 0;
}