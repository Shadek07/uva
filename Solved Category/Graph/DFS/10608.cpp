#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define SIZE 30005

vector <int> adj[SIZE];



bool visited[SIZE];
int v;

char in[25][26];
int cnt = 0;

void visit(int u)
{
	int i;
	visited[u] = true;
	for(i=1;i<=adj[u].size();i++)
	if(!visited[adj[u][i-1]])
	{
	   cnt++;
	   visit(adj[u][i-1]);
	}
}

int DFS(int d)
{
	int i,ncomp=0;
	
	int max = 0;
	int k;
		for( k = 1; k <= d; k++)
		{
			
			if(!visited[k])
			{
				cnt = 1;
				ncomp++;
				visit(k);
				if(cnt > max)
					max = cnt;

			}
		}

	return max;
}

int main(void)
{
	
	int d,i,j;

    int image = 1;
	
	int t,m,n;
	int a1,b1;

	cin >> t;

	while(t--)
	{
		cin >> m >> n;
		getchar();
		for(i = 0; i < n; i++)
		{
			cin >> a1 >> b1;
			adj[a1].push_back(b1);
			adj[b1].push_back(a1);
			
		}


		int a = DFS(m);

	    cout << a  << endl;

		memset(visited,false,sizeof(visited));

		for( i = 1; i <= m; i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
		}

		
	}

	


	return 0;
}
