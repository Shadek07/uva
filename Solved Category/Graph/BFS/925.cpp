#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;

int pre[130][130];
int visited[130];
vector<int> v[130];
vector<int> list;
vector<string> vs;
queue<int> q;
int reach[130][130]; // reach[i][j] is 1 if j is reachable from i
int src;
int dest;
int flag;

struct all
{
	char in[130][50];
	int ind;

}sh[130];

struct just
{
	char in[50];
	int ind;

}js[130];

int comp(just a,just b)
{
	if(strcmp(a.in,b.in) < 0)
		return 1;
	else
		return 0;
}

void bfs()
{
	int a,b,i;
	q.push(src);
	
	while(!q.empty())
	{
		
		a = q.front();
		visited[a] = 1;
		q.pop();
		if(a == dest)
		{
			flag = 1;
			break;
		}
		
		visited[a] = 1;
		for(i = 0; i < v[a].size();i++)
		{
			if(visited[v[a][i]] == 0)
			q.push(v[a][i]);
		}
		

	}

	while(!q.empty())
		q.pop();

	

}
int main(void)
{
	map<string,int> mp;
	map<int,string> rev;
	char in[50];
	int t;
	string s1,s2;
	int i,j,k,ind,a,b;
	int course;
	cin >> t;

	while(t--)
	{
		cin >> course;
		getchar();
		ind = 1;
		
		for(i = 0; i < course;i++)
		{
			gets(in);
			s1 = in;
			mp[s1] = ind++;
			rev[ind-1] = s1;
			strcpy(js[ind-2].in,in);
			js[ind-2].ind = ind-1;
		}

		cin >> a;

		memset(pre,0,sizeof(pre));
		memset(reach,0,sizeof(reach));

		for(i = 0; i < a;i++)
		{
			cin >> in;
			s1 = in;
			j = mp[s1];
			cin >> b;
			for(k = 0; k < b;k++)
			{
				cin >> in;
				s1 = in;
				ind = mp[s1];
				pre[ind][j] = 1; //ind is a pre-requisite of j
				v[ind].push_back(j);
			}
		}

		for(i = 1; i <= course;i++)
		{
			memset(visited,0,sizeof(visited));
			src = i;
			for(j = 1; j <= course;j++)
			{
				memset(visited,0,sizeof(visited));
				if(j == i)
					continue;
				flag = 0;
				dest = j;
				bfs();
				if(flag == 1)
				{
					reach[i][j] = 1;
				}

			}

		}

		for(i = 1; i <= course;i++)
		{
			if(v[i].size() > 1)
			{
				for(j = 0; j < v[i].size();j++)
				{
					int test;
					test = v[i][j];
					for(k = 0; k < v[i].size() ;k++)
					{
						if(test == v[i][k])
							continue;
						if(reach[v[i][k]][test] == 1)
							pre[i][test] = 0;

					}
				}
			}
		}

		sort(js,js+course,comp);

		for(j = 0; j < course;j++)
		{
			for(i = 1; i <= course;i++)
			{
				if(pre[i][js[j].ind] == 1)
					vs.push_back(rev[i]);
			}

			s1 = rev[js[j].ind];
			sort(vs.begin(),vs.end());

			if(vs.size() > 0)
			{
				cout << s1 << " " << vs.size();
				for(k = 0;k<vs.size();k++)
				{
					cout << " " << vs[k];

				}
				cout << endl;
				vs.clear();
			}
		}

		for(i = 0;i < 130;i++)
		{
			if(!v[i].empty())
				v[i].clear();
		}

		mp.clear();
		rev.clear();
	}

	return 0;

}