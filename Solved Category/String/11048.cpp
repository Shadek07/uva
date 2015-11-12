
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
#include <bitset>
#include<fstream>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))
map<string,int> mp;
char dict[10001][30];
int n;

string nearest(string s)
{
	int i,j,k;
	string word,tmp;
	string ret = "-";
	int len1,len2;

	len1 = s.length();

	for(i = 0;i<n;i++)
	{
		word = dict[i];
		len2 = word.length();
		if(abs(len1-len2) >= 2)
			continue;
		if(abs(len1-len2) == 1)
		{
			
			if(len1>len2)
			{
				for(j = 0;j<len1;j++)
				{
					//if(j == 0)
						//tmp = s.substr(j+1,len1-j-1);
					//else
					tmp = s.substr(0,j) + s.substr(j+1,len1-j-1);
					if(tmp == word)
						return word;
				}
			}
			else
			{
				for(j = 0;j<len2;j++)
				{
					tmp = word.substr(0,j) + word.substr(j+1,len2-j-1);
					if(tmp == s)
						return word;
				}

			}
		}
		if(len1 == len2)
		{
			j = 0;
			for(k = 0;k<len1;k++)
				if(word[k] != s[k])
					j++;
			if(j == 1)
			{
				//cout << "j: " << j << endl;
				return word;
			}
			k = 0;
			bool got_at_last = false;
			for(j = 0;j<len1-1;j++)
			{
				if(word[j] == s[j])
					continue;
				else if(word[j] == s[j+1] && word[j+1] == s[j])
				{
					k++;					
					if(j == len1-2)
					got_at_last = true;
					j++;

				}
				else if(word[j] != s[j])
				{
					k=2;
					break;
				}
			}
			if(!got_at_last && word[len1-1] != s[len1-1])
				k=2;
			if(k == 1)
			{
				//cout << "k: " << k << endl;
				return word;
			}
		}
	}

	return ret;

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	//ifstream f1("2.txt");
	//ifstream f3("3.txt");
	int i,j,k,q;
	char in[530],in1[530];
	string s,s1;
	/*i = 0;
	while(getline(f1,s))
	{
		getline(f3 , s1);
		if(s.compare(s1) !=0)
		{
			cout << i << endl;
			cout << s << endl << endl;
		}
		i++;

	}
	return 0;*/
	cin >> n;
	getchar();
	string ans;
	for(i = 0;i<n;i++)
	{
		gets(in);
		strcpy(dict[i],in);
		mp[in] = i+1;
	}
	cin >> q;
	getchar();
	while(q--)
	{
		gets(in);
		if(mp[in])
		{
			cout << in << " is correct\n";
			continue;
		}
		else
		{
			ans = nearest(in);
			if(ans.compare("-") == 0)
				cout << in << " is unknown\n";
			else
				cout << in << " is a misspelling of " << ans << endl;
		}

	}

     return 0;
}