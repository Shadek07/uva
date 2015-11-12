#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define SIZE 100

vector <int> adj[SIZE][SIZE];
vector <int> adj1[SIZE][SIZE];

bool visited[SIZE][SIZE];
int v;
int cnt;
int a1,b1;

char in[500][500];

void visit(int u,int v)
{
	int i;
	visited[u][v]=true;
	for(i=0;i<adj[u][v].size();i++)
	if(!visited[adj[u][v][i]][adj1[u][v][i]] && in[adj[u][v][i]][adj1[u][v][i]] == 'W')
	{
		cnt++;
	    visit(adj[u][v][i],adj1[u][v][i]);
	 }
}

int DFS(int d,int d1)
{
	int i,ncomp=0;
	int k;
	
		
	char c = in[a1-1][b1-1];
	if( c == 'W')
	{
		ncomp++;
		cnt = 1;
		visit(a1-1,b1-1);

	}
	else
	{
		cnt = 0;
	}
			
				
			
		

	return cnt;
}

int main(void)
{
	
	int d,i,j,k,l,a,b;

    int image = 1;
	int N,M;

	char s[100];

	int test;

	cin >> test;

	getchar();
	getchar();

	while(test--)
	{
	
            
		   k = 0;
	
		
			
			for(k = 0; ; k++)
			{
				gets(in[k]);
				if(!isalpha(in[k][0]))
					break;
			}

			N=k;

           for(j=0;in[k-1][j]!='\0';j++);

           M=j;


		   strcpy(s,in[k]);

		   	
            for(i = 0; i < N; i++)
			{
				for( j = 0; j < M; j++)
				{
					if( in[i][j] == 'W')
					{

						if( i-1>= 0)
						{
							if(in[i-1][j] == 'W')
							{
								adj[i][j].push_back(i-1);
								adj1[i][j].push_back(j);
							}
							
						}
						if( i-1>= 0 && j-1 >= 0)
						{
							if(in[i-1][j-1] == 'W')
							{
								adj[i][j].push_back(i-1);
								adj1[i][j].push_back(j-1);
							}
							
						}
						if(  j-1 >= 0)
						{
							if(in[i][j-1] == 'W')
							{
								adj[i][j].push_back(i);
								adj1[i][j].push_back(j-1);
							}
							
						}
						if(  j+1 < M)
						{
							if(in[i][j+1] == 'W')
							{
								adj[i][j].push_back(i);
								adj1[i][j].push_back(j+1);
							}
							
						}
						if( i+1 < N && j+1 < M)
						{
							if(in[i+1][j+1] == 'W')
							{
								adj[i][j].push_back(i+1);
								adj1[i][j].push_back(j+1);
							}
							
						}
						if( i+1 < N)
						{
							if(in[i+1][j] == 'W')
							{
								adj[i][j].push_back(i+1);
								adj1[i][j].push_back(j);
							}
							
						}
						if( i-1 >= 0 && j+1 < M)
						{
							if(in[i-1][j+1] == 'W')
							{
								adj[i][j].push_back(i-1);
								adj1[i][j].push_back(j+1);
							}
							
						}
						if( i+1 < N && j-1 >= 0)
						{
							if(in[i+1][j-1] == 'W')
							{
								adj[i][j].push_back(i+1);
								adj1[i][j].push_back(j-1);
							}
							
						}
					}
				}
			}


			if( image == 1)
				image = 2;
			else
				cout << endl;


		do
		{
			

			if(s[0]=='\0')break;

			sscanf(s,"%d %d",&a,&b);

			a1 = a;
			b1 = b;

			int a = DFS(M,N);

			

			cout << a << endl;

			memset(visited,false,sizeof(visited));

			

		}while(gets(s));


			
		memset(visited,false,sizeof(visited));

		//if(test >0)
		//getchar();

		
	}

	


	return 0;
}
