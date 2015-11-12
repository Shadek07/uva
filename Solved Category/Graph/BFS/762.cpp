
#include<iostream>
#include<vector>
#include<cstring>
#include <map>
#include<cmath>
#include<queue>
#include<cstdio>

using namespace std;

#define  un 0
#define  dis 1
#define comp 2;
#define SIZE 10000
//bool visited[SIZE];
int v;

//char in[25][26];
int cnt = 0;

//const int LineMax = 1000;

//const int NULLCHAR = '\0';

//typedef char LineType[LineMax];

vector<int>adj[10000];

queue<int> q;

int step;

int state[10000];

bool flag[10000];

int in_queue[10000];

int p[10000];

int src,dest;

int se;

int search();

char to[1000];
int n;

int no_route;

char save[10000][50];

void recursive(int a)
{
	
	if(p[a] != -1)
	{	
		recursive(p[a]);	
		cout << save[p[a]] << " " << save[a] << endl;
			  			           
	}

}



int search()
{
	int i;

	for(i = 0; i < n; i++)
		if((strcmp(save[i],to)) == 0)
			return i;

		strcpy(save[n],to);
		
		return n++;

}

int BFS()
{
 	 
 	 int u,i;
 	 
 	 

	 memset(flag,false,sizeof(flag));
	 memset(p,-1,sizeof(p));
     

     p[src] = -1;

	 flag[src] = true;
     
     q.push(src);
     
     while(!q.empty())
     {
          u = q.front();
          q.pop();

          int  tmp;
		  int size;

		  size = adj[u].size();

          for(i = 0; i < adj[u].size(); i++)
          {
			    tmp = adj[u][i];

		   		if(adj[u][i] == dest)
		   		{

					       no_route = 0;
				 			 
				 			 step = 0;
							 p[adj[u][i]] = u;
				 			 int se = dest;
				 			 while(p[se] != -1)
				 			 {
			  			           se = p[se];
			  			           step++;
			  			     }

							 

							 recursive(dest);							 			  			     
			  			     while(!q.empty())
			  			          q.pop();

							
			  			     
			  			     return 1;
		 			 
		 			 
				 			 
 			    }
 			    else
 			    {
				 	

					if(flag[ adj[u][i] ] == false)
					{
						flag[ adj[u][i] ] = true;
						p[adj[u][i]] = u;
						q.push(adj[u][i]);
					}
				}
   		  }
   		  
   		  state[u] = comp;
           
     }
     
     return 1;
 	 
}



int main(void)
{
	
	int i;

    int image = 1;
	
	int t,n;


	

	int ind9,ind10;



	char a2[1000],b2[1000];

	while(cin >> t)
	{
		


		int j2 = 1;

		n = 0;

		for(i = 0; i < t; i++)
		{
			

			cin >> a2 >> b2;

			strcpy(to,a2);

			 ind9 = search();

			  strcpy(to,b2);

			 ind10 = search();

			adj[ind9].push_back(ind10);
			adj[ind10].push_back(ind9);

		
			
		}

		cin >> a2 >> b2;

		strcpy(to,a2);

		ind9 = search();

		strcpy(to,b2);

		ind10 = search();

		src = ind9;

		dest = ind10;


		no_route = 1;

		if(image == 1)
			image = 0;
		else
			cout << endl;

		int a = BFS();

		

		if(no_route == 1)
			cout << "No route\n";

		
		char c = getchar();
		c = getchar();

		if(c != '\n')
			break;

	    //cout << a  << endl;

		

		//memset(visited,false,sizeof(visited));

		memset(save,'\0',sizeof(save));

		for( i = 1; i <= 9999; i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
		}



		
	}

	


	return 0;
}
