
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

typedef pair<int,int> pa;

stack<pa> st;
int dim[27][2]; //dimension
unsigned long long ans;

int main(void)
{
	int i,j,k,a,b;
	int n;
	char c;
	char in[1000];
	cin >> n;
	getchar();
	int len;
	pa p1,p2,p3;
	bool ch;
	for(i = 0;i<n;i++)
	{
		scanf("%c %d %d",&c,&a,&b);
		getchar();
		dim[c-'A'][0] = a;
		dim[c-'A'][1] = b;
	}
	
	while(gets(in))
	{
		len = strlen(in);
		if(len == 1)
		{
			cout << 0 << endl;
			continue;
		}

		ch = true;
		ans = 0;
		for(i = 0;i<len;i++)
		{
			if(in[i] >= 'A' && in[i] <= 'Z')
			{
				p1.first = dim[in[i]-'A'][0];
				p1.second = dim[in[i]-'A'][1];
				st.push(p1);
			}
			else if(in[i] == ')')
			{
				p2 = st.top();
				st.pop();
				p1 = st.top();
				st.pop();
				if(p1.second != p2.first)
				{
					ch = false;
					break;
				}
				p3.first = p1.first;
				p3.second = p2.second;
				st.push(p3);
				ans += p1.first*p1.second*p2.second;
			}
		}

		if(ch)
		{
			cout << ans << endl;
		}
		else
			cout << "error\n";
		while(!st.empty())
			st.pop();

	}
	return 0;
}
