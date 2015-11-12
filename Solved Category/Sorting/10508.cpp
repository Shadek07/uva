#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

char stock[10000][1000];

vector<int> v1[10000];
map<string,int> mp;

char fin[10000][1000];
int ind = 0;
int color[10000];

struct word
{
	char in[10000];
	int index;
	int diff;
}wr[10000];

int comp(word a, word b)
{
	if(a.diff < b.diff)
		return 1;
	else
		return 0;
}

int match_char(char first[10000],char second[10000])
{
	int len,i,cnt  = 0;
	len = strlen(first);

	for(i = 0; i < len; i++)
	{
		if(first[i] != second[i])
			cnt++;
	}

	return cnt;
}

/*int get_id(char in[10000])
{
	int i,j;
	for(i = 0; i <= ind; i++)
	{
		if(strcmp(fin[i],in) == 0)
			return i;
	}

	strcpy(fin[ind],in);

	ind++;
	return ind-1;
}*/

void visit(int i)
{
	int j,k;
	if(!color[i])
	{
		cout << fin[i] << endl;
		color[i] = 1;
	}
	for(j = 0; j < v1[i].size(); j++)
	{
		if(!color[v1[i][j]])
		{
			visit(v1[i][j]);

		}
	}

}

int main(void)
{
	int m,n,i,j,k;
	int id1,id2;

	char first[10000],target[10000],in[10000];

	while(cin >> m >> n)
	{
		ind = 1;
		getchar();
		gets(first);
		strcpy(stock[0],first);
		gets(target);
		strcpy(stock[1],target);
        for(i = 2; i < m; i++)
		{
			gets(in);
			strcpy(stock[i],in);
			k = match_char(in,first);
			wr[i-2].index = i;
			wr[i-2].diff = k;
			strcpy(wr[i-2].in,in);
		}

		
		sort(wr,wr+m-2,comp);

		cout << first << endl;

		for(i = 0; i < m - 2; i++)
		{
			cout << wr[i].in << endl;
		}

		cout << target << endl;

		/*for(i = 0; i < m-1; i++)
		{
			for(j = i+1; j < m; j++)
			{
				k = match_char(stock[i],stock[j]);

				if(k == 1)
				{
					
					if(mp[stock[i]])
					{
						id1 = mp.find(stock[i])->second;
					}
					else
					{
						mp[stock[i]] = ind++;
						strcpy(fin[ind-1],stock[i]);
						id1 = ind-1;
					}

					if(mp[stock[j]])
					{
						id2 = mp.find(stock[j])->second;
					}
					else
					{
						mp[stock[j]] = ind++;
						strcpy(fin[ind-1],stock[j]);
						id2 = ind - 1;
					}
					
					v1[id1].push_back(id2);
					v1[id2].push_back(id1);
				}

			}
		}

		memset(color,0,sizeof(color));

		//id1 = get_id(first);
		id1 = mp.find(first)->second;
		visit(id1);

		for(i = 0; i < m; i++)
		{
			if(!v1[i].empty())
				v1[i].clear();
		}

		mp.clear();*/

	    


	}

	return 0;
}
