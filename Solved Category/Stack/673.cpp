#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
#include<cstring>

using namespace std;

stack<char> s1;

int main(void)
{
    int t,i;

	char in[200],c;

	int len;

	int ch = 1;


	cin >> t;

	getchar();

	while(t--)
	{
		gets(in);

		len = strlen(in);


		ch = 1;

		for(i = 0; i < len; i++)
		{
			if(in[i] == '(' || in[i] == '[')
				s1.push(in[i]);
			else if(in[i] == ')')
			{
				if(s1.empty())
				{
					cout << "No\n";
					ch = 0;
					goto next;
				}
				while(!s1.empty())
				{
					c = s1.top();
					s1.pop();
					if(c == '(')
						break;
				}
			}
			else if(in[i] == ']')
			{
				if(s1.empty())
				{
					cout << "No\n";
					ch = 0;
					goto next;
				}
				while(!s1.empty())
				{
					c = s1.top();

					s1.pop();
					if(c == '[')
						break;


				}
			}
		}

next:

	

	
		if(!s1.empty())
		{
			cout << "No\n";
		}

	    else if(ch == 1)
		{
			cout << "Yes\n";
		}

		while(!s1.empty())
		{
			s1.pop();
		}				
	}


	return 0;
}

