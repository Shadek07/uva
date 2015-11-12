#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define SIZE 100

vector <int> adj[SIZE][SIZE];
vector <int> adj1[SIZE][SIZE];

bool visited[SIZE][SIZE];
int v;

char in[100][101];

void visit(int u,int v)
{
	int i;
	visited[u][v]=true;
	for(i=0;i<adj[u][v].size();i++)
	if(!visited[adj[u][v][i]][adj1[u][v][i]] && in[adj[u][v][i]][adj1[u][v][i]] == '@')
	visit(adj[u][v][i],adj1[u][v][i]);
}

int DFS(int d,int d1)
{
	int i,ncomp=0;
	int k;
	for(i=0;i< d;i++)
		for( k = 0; k < d1; k++)
		{
			if(!visited[i][k] && in[i][k] == '@')
			{
				ncomp++;
				visit(i,k);
			}
		}

	return ncomp;
}

int main(void)
{
	
	int d,d1,i,j;

    int image = 1;
	

	while(1)
	{
		scanf("%d %d",&d,&d1);
		if(!d && !d1)
			break;
		getchar();
		for(i = 0; i < d; i++)
		{
			gets(in[i]);
		}

		for(i = 0; i < d; i++)
		{
			for( j = 0; j < d1; j++)
			{
				if( in[i][j] == '@')
				{

					if( i-1>= 0)
					{
						if(in[i-1][j] == '@')
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j);
						}
						
					}
					if( i-1>= 0 && j-1 >= 0)
					{
						if(in[i-1][j-1] == '@')
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j-1);
						}
						
					}
					if(  j-1 >= 0)
					{
						if(in[i][j-1] == '@')
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j-1);
						}
						
					}
					if(  j+1 < d1)
					{
						if(in[i][j+1] == '@')
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j+1);
						}
						
					}
					if( i+1 < d && j+1 < d1)
					{
						if(in[i+1][j+1] == '@')
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j+1);
						}
						
					}
					if( i+1 < d)
					{
						if(in[i+1][j] == '@')
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j);
						}
						
					}
					if( i-1 >= 0 && j+1 < d1)
					{
						if(in[i-1][j+1] == '@')
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j+1);
						}
						
					}
					if( i+1 < d && j-1 >= 0)
					{
						if(in[i+1][j-1] == '@')
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j-1);
						}
						
					}
				}
			}
		}

		int a = DFS(d,d1);

	    cout  << a << endl;

		memset(visited,false,sizeof(visited));

		
	}

	


	return 0;
}
