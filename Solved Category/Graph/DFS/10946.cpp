#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define SIZE 100

vector <int> adj[SIZE][SIZE];
vector <int> adj1[SIZE][SIZE];

bool visited[SIZE][SIZE];
int v;
int cnt;
int ind;
char in[100][100];

struct ans
{
	int c;
	int ct;
}p[2500];

int comp( ans a,  ans b)
{
	if( a.ct != b.ct)
		return a.ct > b.ct;
	else
		return a.c < b.c;
}

void visit(int u,int v,char c)
{
	int i;
	visited[u][v]=true;
	for(i=0;i<adj[u][v].size();i++)
	if(!visited[adj[u][v][i]][adj1[u][v][i]] && in[adj[u][v][i]][adj1[u][v][i]] == c)
	{
		cnt++;
	    visit(adj[u][v][i],adj1[u][v][i],c);
	}
}

int DFS(int d,int n)
{
	int i,ncomp=0;
	int k;
	for(i=0;i< d;i++)
		for( k = 0; k < n; k++)
		{
			if(!visited[i][k] && in[i][k] != '.')
			{
				ncomp++;
				cnt = 1;
				visit(i,k,in[i][k]);
				p[ind].c = int(in[i][k]);
				p[ind].ct = cnt;
				ind++;
			}
		}

		sort(p,p+ind,comp);

	return ncomp;
}

int main(void)
{
	
	int d,i,j;

    int image = 1;

	int n;
	memset(in,'.',sizeof(in));

	while(1)
	{
		cin >> d >> n;
		if( d == 0 && n == 0)
			break;
		getchar();
		for(i = 0; i < d; i++)
		{
			gets(in[i]);
		}

		ind = 0;

		for(i = 0; i < d; i++)
		{
			for( j = 0; j < n; j++)
			{
				if( in[i][j] != '.')
				{

					if( i-1>= 0)
					{
						if(in[i-1][j] == in[i][j])
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j);
						}
						
					}
					/*if( i-1>= 0 && j-1 >= 0)
					{
						if(in[i-1][j-1] == in[i][j])
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j-1);
						}
						
					}*/
					if(  j-1 >= 0)
					{
						if(in[i][j-1] == in[i][j])
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j-1);
						}
						
					}
					if(  j+1 < n)
					{
						if(in[i][j+1] == in[i][j])
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j+1);
						}
						
					}
					/*if( i+1 < d && j+1 < d)
					{
						if(in[i+1][j+1] == in[i][j])
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j+1);
						}
						
					}*/
					if( i+1 < d)
					{
						if(in[i+1][j] == in[i][j])
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j);
						}
						
					}
					/*if( i-1 >= 0 && j+1 < d)
					{
						if(in[i-1][j+1] == in[i][j])
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j+1);
						}
						
					}*/
					/*if( i+1 < d && j-1 >= 0)
					{
						if(in[i+1][j-1] == in[i][j])
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j-1);
						}
						
					}*/
				}
			}
		}

		int a = DFS(d,n);

	    cout <<"Problem " <<  image++ << ":" << endl;

		for( i = 0; i < ind; i++)
		{
			cout << char(p[i].c) << " " << p[i].ct << endl;
		}

		memset(visited,false,sizeof(visited));
		memset(in,'.',sizeof(in));

		
	}

	


	return 0;
}
