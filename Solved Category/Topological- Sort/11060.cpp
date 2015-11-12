#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int indegree[105];
bool taken[105];
bool check[101][105];

map<string,int> mp;
map<int,string> rev;
vector<int> v[105];
char in[100];
char next[100];
char word[105][100];
int main(void)
{
	int m,n,i,j,k,a,b;
	string s1,s2;
	int ca = 1;

	int count,ind;

	while(scanf("%d",&m) == 1)
	{
		
		ind = 1;
		getchar();

		for(i = 0; i < m;i++)
		{
			cin >> in;
			strcpy(word[i+1],in);
			s1 = in;
			mp[s1] = ind;
			rev[ind] = s1;
			ind++;
		}

		for(i = 1; i <= m;i++)
		{
			indegree[i] = 0;
			taken[i] = 0;
			for(j = 1; j <= m;j++)
				check[i][j] = false;
		}

		//memset(indegree,0,sizeof(indegree));
		//memset(taken,false,sizeof(taken));
		//memset(check,false,sizeof(check));

		count = 0;
		cin >> n;
		for( i = 0; i < n; i++)
		{
             cin >> in >> next;
			 s1 = in;
			 s2 = next;
			 a = mp[s1];
			 b = mp[s2];
             indegree[b]++;
			 v[a].push_back(b);
			 check[a][b] = true;
		}

		cout << "Case #" << ca++ << ": Dilbert should drink beverages in this order: ";

		while(count != m)
		{
			for(i = 1; i <= m; i++)
			{
				if(indegree[i] == 0 && taken[i] == false)
				{
					cout << word[i];

					count++;

					if( count != m)
						cout << " ";
					else
						cout << "\n";
					taken[i] = true;
					for( j = 0; j < v[i].size(); j++)
					{
                       if( check[i][v[i][j]] == true)
					   {
							indegree[v[i][j]]--;
							check[i][v[i][j]] = false;
					   }
						
					}

					i = 0;
				}
			}
		}

		cout << ".\n\n";
		for(i = 0; i <= m;i++)
			if(!v[i].empty())
				v[i].clear();

	}

	return 0;
}