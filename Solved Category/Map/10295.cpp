#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main(void)
{
	map<string,int> mp;
	unsigned long int m,n,res,a;
	int i,j,k;
	string s1,s2;

	cin >> m >> n;

	for(i = 0; i < m; i++)
	{
         cin >> s1 >> a;
		 mp[s1] = a;
	}

	while(n--)
	{
		res = 0;
		while(1)
		{
			cin >> s1;
			if(s1.compare(".") == 0)
			{
				cout << res << endl;
				break;
			}
			else
			{
				if(mp.find(s1) != mp.end())
					res += mp[s1];
			}
		}
	}

	return 0;
}