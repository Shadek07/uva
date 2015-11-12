#include<iostream>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

char in[50000][10];
char all[100];
map<char,int> mp;
vector<int> vc[100];
int p[100];
int rank[100];
int elem[100];
void makeset(int a)
{
	p[a] = a;
	rank[a] = 0;
	elem[a] = 1;
}

int findset(int a)
{
	if(p[a] != a)
		return findset(p[a]);
	else
		return a;
}

void mergeset(int x,int y)
{
    int px,py;
	px = findset(x);
	py = findset(y);
	if(rank[x] > rank[y])
	{
		p[y] = x;
		elem[x] += elem[y];
		//elem[y] += elem[x];
	}
	else
	{
		p[x] = y;
		elem[y] += elem[x];
		//elem[x] += elem[y];
	}

	if(rank[x] == rank[y])
	{
		rank[y]++;
	}
}

int main(void)
{
	int t,i,j,len,ind,a,b,component,cnt;
	map<char,int>::iterator it;
	char c,c1;
	cin >> t;
	getchar();
	while(t--)
	{
		i = 0;
		while(1)
		{

			gets(in[i++]);
			if(in[i-1][0] == '*')
				break;
		}

		i -= 2;
		gets(all);
		len = strlen(all);
		ind = 1;
		for(j = 0; j < len;j++)
		{
			if(all[j] >= 'A' && all[j] <= 'Z')
			{
				mp[all[j]] = ind++;
				makeset(ind-1);
			}

		}

		component = ind-1;
		cnt = 0;

		for(j = 0; j <= i; j++)
		{
			c = in[j][1];
			c1 = in[j][3];
			a = mp[c];
			b = mp[c1];
			vc[a].push_back(b);
			vc[b].push_back(a);
			if(findset(a) != findset(b))
			{
				mergeset(a,b);
				component--;
			}
			else
			{
				cnt++;

			}

		}

		int s;
		s = mp.size();
		int num = 0;

		for(i = 1; i <= ind-1; i++)
		{
			if(vc[i].size() == 0)
				num++;
		}

		//cout << component << " " << num << endl;

		cout << "There are " << component - cnt - num << " tree(s) and " << num << " acorn(s).\n";

		mp.clear();
		for(i = 0; i < 100; i++)
		{
			if(!vc[i].empty())
				vc[i].clear();
		}
	}
	return 0;
}
