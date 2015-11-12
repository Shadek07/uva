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

using namespace std;

int dots(char temp[5])
{
	int cnt = 0;
	int i;
	for(i = 0;i<3;i++)
		if(temp[i] == '.')
			cnt++;
	return cnt;
}
int main(void)
{
	int t;
	char in[105];
	char temp[5];
	int len,i,j,k,a;
	int cnt;
	cin >> t;
	getchar();
	int ca =1;
	while(t--)
	{
		cin >> len;
		getchar();
		gets(in);
		cnt = 0;
		i = 0;
		while(in[i] == '#')
			i++;
		for(;i<len;)
		{
			if(i+3<=len)
			{
				strncpy(temp,in+i,3);
				a =dots(temp);
				if(a>0)
				cnt++;
				i += 3;
				if(a == 1 && (temp[1] == '.' || temp[2] == '.'))
					i++;
				if(a == 2 && temp[0] == '#')
					i++;
				while(in[i] == '#')
					i++;
			}
			else
			{
				if(i == len-1)//one field remaining
				{
					if(in[i] == '.')
						cnt++;
					i++;
				}
				else//two field remaining
				{
					if(in[i] == '.' || in[i+1] == '.')
						cnt++;
					i += 2;
				}
			}
		}

		cout << "Case " << ca++ << ": " << cnt << endl;
	}
	return 0;
}
