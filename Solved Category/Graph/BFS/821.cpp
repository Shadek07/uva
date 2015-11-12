#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<set>

using namespace std;

#define  un 0
#define  dis 1
#define comp 2;


vector<int>adj[102];
queue<int> q;
set<int> st;
set<int>::iterator it;
set<int>::iterator it1;


int step;

int state[102];

bool flag[102];

//int in_queue[102];

int p[102];

int src,dest;

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
				 			 while(p[se] != -1)
				 			 {
			  			           se = p[se];
			  			           step++;
			  			     }
			  			     
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
 	
 	int i,j,a,b,k;
 	
 	int size;
 	
 	int t = 1;;
 	
 	i = 0;
 	
 	while(cin >> a >> b)
 	{
		if(!a && !b)
			break;

		st.insert(a);
		st.insert(b);

		adj[a].push_back(b);
        
         while(cin >> a >> b)
		 {			  	   
			  	   if(!a && !b)
					   break;
				   
			  	   adj[a].push_back(b);
				   st.insert(a);
		           st.insert(b);
			       			  	  					 
		 } 
	    
	     
	     size = st.size();

		 int cnt = 0;
	     
	     cout << "Case " << t++ << ": ";

        
		 for (it=st.begin(),k=0; it!=st.end(); it++,k++)
		 {
	     
			 src = *it;
			 a = 0;
			 //for(it1 = st.begin();a<=k+1;it1++,a++)
				 //;
			 for(it1 = st.begin(); it1 != st.end(); it1++)
			 {
		  		  
				 
				 dest = *it1;
			
				 if( src != dest)
				 {
					  BFS();
		  			  
  					  //printf("%2d to %d: %d\n",src,dest,step);

					  cnt += step;
				 }
			 }
		 }

		 int div = size*(size-1);
		 

	

		 double res = cnt*1.0/div;

		 printf("average length between pages = %.3f clicks\n",res);

		 for(i = 0; i <= 101;i++)
			 if(!adj[i].empty())
			 adj[i].clear();

			 st.clear();

	 		  
    }
 	
 	
 	
 	return 0;
}
