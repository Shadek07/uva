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
map<string,int> mp;
int main(void)
{
	int p,g,i,j,k;
	int  a,b;
	char in[25];
	char line[2000];
	int ca =1;
	char *q;
	int sum=0.1;
	int sum1;
	//cout << sum << endl;
	int ch;
	while(cin >> p >> g)
	{
		ca =1;
		getchar();
		for(i = 0;i<p;i++)
		{
			//cin >> in >> a;
			scanf("%s %d.%d",in,&a,&b);
			mp[in] = a*10 + b;
		}
		getchar();
		int len;
		for(i = 0;i<g;i++)
		{
			gets(line);
			sum = 0;
			q = strtok(line," !\"#$%&\'()*+,-./:;?@[\\]^_`{|}~");
			while(q != NULL)
			{
				if(q[0] == '>' || q[0] == '<' || q[0] == '=')
				{
					len = strlen(q);
					strcpy(in,q);
					q = strtok(NULL," !\"#$%&\'()*+,-./:;?@[\\]^_`{|}~");
					ch = atoi(q)*10;				
					break;
				}
				sum += mp[q];
				q = strtok(NULL," !\"#$%&\'()*+,-./:;?@[\\]^_`{|}~");
			}
			cout << "Guess #" << ca++;
			sum1 = sum;
			if(len == 1 && in[0] == '<')
			{
				if(sum1 < ch)
					cout << " was correct.\n";
				else
					cout << " was incorrect.\n";
			}
			else if(len == 1 && in[0] == '>')
			{
				if(sum1 > ch)
					cout << " was correct.\n";
				else
					cout << " was incorrect.\n";
			}
			else if(len == 1 && in[0] == '=')
			{
				if(sum1 == ch)
					cout << " was correct.\n";
				else
					cout << " was incorrect.\n";
			}
			else if(len == 2 && in[0] == '<')
			{
				if(sum1 <= ch)
					cout << " was correct.\n";
				else
					cout << " was incorrect.\n";
			}
			else if(len == 2 && in[0] == '>')
			{
				if(sum1 >= ch)
					cout << " was correct.\n";
				else
					cout << " was incorrect.\n";
			}
		}
		mp.clear();

	}

	return 0;
}
