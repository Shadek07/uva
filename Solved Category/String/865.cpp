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

map<char,char> mp;
int main(void)
{
	int t;
	string plain,subs;
	string in;
	int ch=0;
	int i,j,k;
	cin >> t;
	cin.ignore(100,'\n');
	cin.ignore(100, '\n');
	while(t--)
	{
		getline(cin,plain);
		getline(cin,subs);
		int len = plain.size();
		for(i=0;i<len;i++)
		{
			mp[plain[i]] = subs[i];
		}
		if(ch==0)
			ch = 1;
		else
			cout << endl;
		cout << subs << endl;
		cout << plain << endl;
		while(getline(cin,in))
		{
			if(in=="")
				break;
			len = in.size();
			for(i=0;i<len;i++)
				if(mp.find(in[i]) != mp.end())
				{
					cout << mp[in[i]];
				}
				else
					cout << in[i];
			cout << endl;
		}
		
		mp.clear();
	}
	return 0;
}