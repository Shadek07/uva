#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>

using namespace std;

map<int,int> mp;
int info[1000001];
int main(void)
{
	int n,s,i,j;

	j = 0;

	while(scanf("%d",&n) == 1)
	{
		if(mp[n])
		{
			mp[n]++;
		}
		else
		{
			mp[n] = 1;
			info[j++] = n;
		}
	}

	s = mp.size();

	//cout << s << endl;

	for(i = 0; i < s; i++)
	{
		j =  info[i];
		cout << j << " " << mp[j] << endl;			
	}

	return 0;
}