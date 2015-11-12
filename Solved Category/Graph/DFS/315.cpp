#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

vector<int> v[101];
int del;
int visit[101];
int start;
int n;
char in[10000];

void dfs(int a)
{
	int i;

	visit[a] = true;

	for(i = 0; i < v[a].size();i++)
	{
		if(v[a][i] != del && visit[v[a][i]] == 0)
			dfs(v[a][i]);
	}
}

int crital_check()
{
	int i;
	for(i = 1;i <= n; i++)
	{
		if(visit[i] == 0 && i != del)
			return 1;
	}

	return 0;

}

int  main(void)
{
	
	char *p;
	int a,b,i,j;
	int critical;
	while(1)
	{
		cin >> n;

		getchar();
		if(!n)
			break;
		while(1)
		{
			gets(in);
			p = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			a = atoi(p);
			if(a != 0)
			{
				
				p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
				while( p != NULL)
				{
					b = atoi(p);
					v[a].push_back(b);
					v[b].push_back(a);
					p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");

				}

			}
			else
			{
				break;
			}
		}

		critical = 0;
		memset(visit,0,sizeof(visit));

		del = 1;
        dfs(2);

		critical += crital_check();

		for( i = 2;i <= n; i++)
		{
			memset(visit,0,sizeof(visit));
			del = i;
			dfs(1);
			critical += crital_check();

		}

		cout << critical << endl;

		for(i = 0; i <= 100;i++)
		{
			if(!v[i].empty())
				v[i].clear();
		}


	}

	return 0;
}