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
struct recipe
{
	char name[500];
	long int cost;
}r[101];

map<string,int> ingredient;

void stringToUpper(string &s)
{
   for(unsigned int l = 0; l < s.length(); l++)
  {
    s[l] = toupper(s[l]);
  }
}

bool comp(const recipe a, const recipe b)
{
	if(a.cost < b.cost)
		return true;
	else if(a.cost == b.cost && strcmp(a.name,b.name) < 0)
		return true;
	return false;
}
int main(void)
{
	int binder;
	char name[500];
	string nam;
	char ch[500],ch1[500];
	int cost;
	int i,j,k;
	int n,m,b;
	int cnt;
	cin >> binder;
	getchar();
	while(binder--)
	{
		gets(name);
		nam = name;
		stringToUpper(nam);
		cin >> m >> n >> b;
		ingredient.clear();
		for(i = 0;i<m;i++)
		{
			cin >> ch >> cost;
			ingredient[ch] = cost;
		}

		getchar();
		for(i = 0; i <n;i++)
		{
			gets(ch);
			cin >> cnt;
			long int total = 0;
			for(j = 0;j<cnt;j++)
			{
				cin >> ch1 >> k;
				total += ingredient[ch1]*k;
			}
			getchar();
			strcpy(r[i].name,ch);
			r[i].cost = total;
		}

		sort(r,r+n,comp);

		cout << nam << endl;
		bool h = true;
		for(i = 0;i<n;i++)
		{
			if(r[i].cost <= b)
			{
				cout << r[i].name << endl;
				h = false;
			}
		}
		if(h)
		{
			cout << "Too expensive!\n";
		}
		cout << endl;
	}

	return 0;

}