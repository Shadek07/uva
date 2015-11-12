#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define  un 0
#define  dis 1
#define comp 2;


vector<int>adj[301];
queue<int> q;

int step;

int state[301];

bool flag[301];

int in_queue[301];

int p[301];

int src,dest;
int no;

void print(int b)
{


	if(p[b] != -1)
	{
		print(p[b]);
		if(b == dest)
			cout << b << endl;
		else
			cout << b << " ";
		
	}
	else
	{
		cout << b << " ";
	}

}

int BFS()
{
 	 
 	 int u,i;
 	 
 	 

	 memset(flag,false,sizeof(flag));

	 memset(p,-1,sizeof(p));
     
     //state[src] = dis;

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
				 			 
				 			 step = 0;
							 p[adj[u][i]] = u;
				 			 int se = dest;
				 			 /*while(p[se] != -1)
				 			 {
			  			           se = p[se];
								   
			  			           step++;
			  			     }*/

							 no = 1;

							 print(dest);
			  			     
			  			     while(!q.empty())
			  			          q.pop();

							 //cout << "Finish\n";
			  			     
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
 	
 	int i,j,a,b,d;
 	
	char str[10000],*str2;
 	
 	
 	int t = 1;;
 	
 	i = 0;
 	
 	while(cin >> a)
 	{
	    

         for(j = 0; j<a; j++)
         {
		  	   
		  	      /* cin >> b;
				   getchar();
             while(1)
			 {
				 c = getchar();
				 if(c == '\n')
					 break;
			  	  cin >> d;
				   
			  	   adj[b].push_back(d);				   
				   c = getchar();
				   if(c == '\n')
					   break;
			 }*/

			 scanf("%s",str);
			 strtok(str,"-");
			 str2=strtok(NULL,",");
			 while(str2!=NULL)
			 {
				d=atoi(str2);
				adj[j+1].push_back(d);
				str2=strtok(NULL,",");
			 }
	     }
	     
	     cin >> b;
	     
	     cout << "-----" << endl;
	     
	     for( i = 0; i < b; i++)
	     {
		  	  cin >> src >> dest;

			  no = 0;
		
			  BFS();
		  	  
			  if(no == 0)
				  cout << "connection impossible\n";
  	          //printf("%2d to %2d: %d\n",src,dest,step);
			  
         }

		 

		 for(i = 0; i <= a;i++)
			if(!adj[i].empty())
				 adj[i].clear();

		 
	 		  
    }
 	
 	
 	
 	return 0;
}
