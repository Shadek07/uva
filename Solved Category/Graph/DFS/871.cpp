#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define SIZE 30

vector <int> adj[SIZE][SIZE];
vector <int> adj1[SIZE][SIZE];

bool visited[SIZE][SIZE];
int v;

char in[30][40];
int cnt;

void visit(int u,int v)
{
	int i;
	visited[u][v]=true;
	for(i=0;i<adj[u][v].size();i++)
	if(!visited[adj[u][v][i]][adj1[u][v][i]] && in[adj[u][v][i]][adj1[u][v][i]] == '1')
	{
		 cnt++;
	     visit(adj[u][v][i],adj1[u][v][i]);
	}
}

int DFS(int d,int d1)
{
	int i,ncomp=0;
	int k;
	int max;
	max = 0;
	for(i=0;i< d;i++)
		for( k = 0; k < d1; k++)
		{
			if(!visited[i][k] && in[i][k] == '1')
			{
				ncomp++;
				cnt = 1;
				visit(i,k);
				if(cnt > max)
					max = cnt;
			}
		}

	return max;
}

int main(void)
{
	
	int d,d1,i,j,i1;

    int image = 1;
	int t;

	cin >> t;

	getchar();
	getchar();
	
	i1 = 0;

	while(t--)
	{
		
	       gets(in[i1]);

		   d = strlen(in[i1]);

		   for(i1 = 1; i1 < d; i1++)
		   {
			   gets(in[i1]);
		   }

		   //getchar();
	   

			   int len = strlen(in[0]); 
			   //cout << len << endl;
			   for(i = 0; i < i1; i++)
				{
					for( j = 0; j < len; j++)
					{
						if( in[i][j] == '1')
						{

							if( i-1>= 0)
							{
								if(in[i-1][j] == '1')
								{
									adj[i][j].push_back(i-1);
									adj1[i][j].push_back(j);
								}
								
							}
							if( i-1>= 0 && j-1 >= 0)
							{
								if(in[i-1][j-1] == '1')
								{
									adj[i][j].push_back(i-1);
									adj1[i][j].push_back(j-1);
								}
								
							}
							if(  j-1 >= 0)
							{
								if(in[i][j-1] == '1')
								{
									adj[i][j].push_back(i);
									adj1[i][j].push_back(j-1);
								}
								
							}
							if(  j+1 < len)
							{
								if(in[i][j+1] == '1')
								{
									adj[i][j].push_back(i);
									adj1[i][j].push_back(j+1);
								}
								
							}
							if( i+1 < i1 && j+1 < len)
							{
								if(in[i+1][j+1] == '1')
								{
									adj[i][j].push_back(i+1);
									adj1[i][j].push_back(j+1);
								}
								
							}
							if( i+1 < i1)
							{
								if(in[i+1][j] == '1')
								{
									adj[i][j].push_back(i+1);
									adj1[i][j].push_back(j);
								}
								
							}
							if( i-1 >= 0 && j+1 < len)
							{
								if(in[i-1][j+1] == '1')
								{
									adj[i][j].push_back(i-1);
									adj1[i][j].push_back(j+1);
								}
								
							}
							if( i+1 < i1 && j-1 >= 0)
							{
								if(in[i+1][j-1] == '1')
								{
									adj[i][j].push_back(i+1);
									adj1[i][j].push_back(j-1);
								}
								
							}
						}
					}
				}

			    //cout << i1 << endl;

				int a = DFS(i1,strlen(in[0]));

				if(image == 1)
					image = 0;
				else
					cout << endl;

				cout  << a << endl;
				//cout << endl;

				memset(visited,false,sizeof(visited));

				for(i = 0; i <= 29; i++)
				{
					for( j = 0; j <= 29; j++)
					{
						adj[i][j].clear();
						adj1[i][j].clear();
					}
				}



			   i1 = 0;
			   if(t > 0)
				   getchar();
			  // break;
		

		
	}

	


	return 0;
}
