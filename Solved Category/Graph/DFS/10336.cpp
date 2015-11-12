#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define SIZE 100

vector <int> adj[SIZE][SIZE];
vector <int> adj1[SIZE][SIZE];

bool visited[SIZE][SIZE];
bool letter[26];
int v;

char in[100][101];

struct st
{
	int comp;
	int index;
}p[26];

bool comp(st a, st b)
{
	if( a.comp == b.comp)
		return a.index < b.index;
	return a.comp > b.comp;
}

void visit(int u,int v,char c)
{
	int i;
	visited[u][v]=true;
	for(i=0;i<adj[u][v].size();i++)
	if(!visited[adj[u][v][i]][adj1[u][v][i]] && in[adj[u][v][i]][adj1[u][v][i]] == c)
	visit(adj[u][v][i],adj1[u][v][i],c);
}

int DFS(int d,int d1,char c)
{
	int i,ncomp=0;
	int k;
	for(i=0;i< d;i++)
		for( k = 0; k < d1; k++)
		{
			if(!visited[i][k] && in[i][k] == c)
			{
				ncomp++;
				visit(i,k,c);
			}
		}

	return ncomp;
}

int main(void)
{
	
	int d,d1,i,j,a;

    
	int image = 1;

	int t;

	char c,c1;

	cin >> t;
	

	while(t--)
	{
		scanf("%d %d",&d,&d1);
		
		getchar();
		for(i = 0; i < d; i++)
		{
			gets(in[i]);
		}

		memset(letter,false,sizeof(letter));

		for(i = 0; i < d; i++)
		{
			for( j = 0; j < d1; j++)
			{


				    c = in[i][j];
				
                    letter[c-97] = true;

					if( i-1>= 0)
					{
						if(in[i-1][j] == c)
						{
							adj[i][j].push_back(i-1);
							adj1[i][j].push_back(j);
						}
						
					}
					
					if(  j-1 >= 0)
					{
						if(in[i][j-1] == c)
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j-1);
						}
						
					}
					if(  j+1 < d1)
					{
						if(in[i][j+1] == c)
						{
							adj[i][j].push_back(i);
							adj1[i][j].push_back(j+1);
						}
						
					}
					
					if( i+1 < d)
					{
						if(in[i+1][j] == c)
						{
							adj[i][j].push_back(i+1);
							adj1[i][j].push_back(j);
						}
						
					}
				
				
				
			}
		}

		int measure = 0;

		for( i = 0; i < 26; i++)
		{
           if( letter[i] == true)
		   {
		          int a = DFS(d,d1,'a'+i);
				   p[i].comp = a;
				   p[i].index = i;
				   measure++;
					  
		   }
		}

		sort(p,p+26,comp);

		cout << "World #" << image++ << endl;

		for( i = 0; i < measure; i++)
		{
			cout << char('a' + p[i].index) << ": " << p[i].comp << endl;
		}

	    

		memset(visited,false,sizeof(visited));

		
	}

	


	return 0;
}
