
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

typedef pair<unsigned long,unsigned long> pi;
vector<pi> v;
map<int,int> mp;
char out[105];
char in[105];
char in1[105];
int main(void)
{
	unsigned long a,b; 
	int cnt = 0;
	a = 1;
	b = 2;
	mp[1] = 1;
	mp[2] = 2;
	cnt = 3;
	while(b < pow(2.0,31))
	{
		unsigned long t = a;
		a = b;
		b = t+b;
		mp[b] = cnt;
		cnt++;

	}
	//cout << mp[4] << endl;

	int i,j,k,len;
	int t,n;
	unsigned long int val[1000];
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i = 0;i<n;i++)
			cin >> val[i];
		getchar();
		gets(in);
		len = strlen(in);
		j = 1;
		memset(in1,'-',sizeof(in1));
		for(i = 0;i<len;i++)
		{
			if(in[i] >= 'A' && in[i] <= 'Z')
				in1[j++] = in[i];
		}

		//in1[j] = '\0';

		memset(out,'-',sizeof(out));
		int mx = 0;
		j = 1;
		for(i = 0;i<n;i++)
		{
			a = mp[val[i]];
			
			if(a>mx)
				mx = a;
			if(a != 0)
			out[a] = in1[j++];
			
		}
		//cout << mx << endl;
		for(i = 1;i<=mx;i++)
		{
			if(out[i] == '-')
				cout << ' ';
			else
				cout << out[i];
		}

		cout << endl;
		

	}
	return 0;
}
