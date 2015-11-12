#include<iostream>

using namespace std;

#define MAX 200

int color[MAX];

int adj[MAX][MAX];

int degree[MAX];

bool dfs(int node, int col)
{
  if(color[node] != 0)
    {
      if(color[node] == col)
        {
          return true;
        }
      else
        {
          return false;
        }
    }
  color[node] = col;
  for(int i = 0; i < degree[node]; ++i)
    {
      if(!dfs(adj[node][i], -col))
        {
          return false;
        }      
    } 
  return true;
}

int main(void)
{

	int vertex,edges,a,b,i;

	while(1)
	{
		//memset(color,0,sizeof(color));
		memset(degree,0,sizeof(degree));

		cin >> vertex;
		if(!vertex)
			break;
		cin >> edges;

		for( i = 0; i < edges; i++)
		{
			cin >> a >> b;
			adj[a][degree[a]] = b;
			adj[b][degree[b]] = a;
			degree[a]++;
			degree[b]++;
			

		}

		memset(color,0,sizeof(color));

		int c = dfs(0,0);

		if(c)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.";
		


	}

	return 0;
}
