#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;

#define  un 0
#define  dis 1
#define comp 2;


vector<int>adj[70];

queue<int> q;

int step;

int state[69];

bool flag[69];

int in_queue[69];

int p[69];

int src,dest;

int cnt = 0;

int get;

void BFS()
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
							 get = 0;
							 p[adj[u][i]] = u;
				 			 int se = dest;
							 //cout << se << " ";
				 			 while(p[se] != -1)
				 			 {
			  			           se = p[se];
								   //cout << se << " ";
			  			           step++;
								   get++;
			  			     }
			  			     
			  			     while(!q.empty())
			  			          q.pop();

							 //cout << "Finish\n";
			  			     
			  			     //return 1;
							 
							 return;
		 			 
		 			 
				 			 
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
     
     //return 1;
	 return;
 	 
}

int main(void)
{
 	
 	int i,j,a,b;

	char first[10],second[10];
 	
 	
 	
 	int t = 1,t1;
 	
 	i = 0;

    
	for(i = 1; i < 9; i++)
	{
		for(j = 1; j < 9; j++)
		{

			t = (i-1)*8;
			t += j;

			a = i;
			b = j;

			b -= 2;
			a--;

			if(b> 0 && a > 0)
			{

				t1 = (a-1)*8;
				t1 += b;
				if( t1 >= 1 && t1 <= 64)
				{

					adj[t].push_back(t1);
					cnt++;
				}
			}

			a = i;
			b = j;

		
				b -= 2;
				a++;
	            if(b > 0 && a < 9)
				{
					t1 = (a-1)*8;
					t1 += b;
					if( t1 >= 1 && t1 <= 64)
					{

						adj[t].push_back(t1);
							cnt++;
					}
				}


			a = i;
			b = j;

			b += 2;
			a++;

			if(b <9  && a < 9)
				{
			t1 = (a-1)*8;
			t1 += b;
			if( t1 >= 1 && t1 <= 64)
			{

			    adj[t].push_back(t1);
				cnt++;
			}

			}
			a = i;
			b = j;

			b += 2;
			a--;
			if(b <9  && a > 0)
			{

				t1 = (a-1)*8;
				t1 += b;
				if( t1 >= 1 && t1 <= 64)
				{
						cnt++;

					adj[t].push_back(t1);
				}
			}


			a = i;
			b = j;

			a -= 2;
			b--;

			if(b > 0  && a > 0)
				{

			t1 = (a-1)*8;
			t1 += b;
				if( t1 >= 1 && t1 <= 64)
				{
						cnt++;

					adj[t].push_back(t1);
				}
			}

			a = i;
			b = j;

			a -= 2;
			b++;

           if(b < 9  && a > 0)
			{
			t1 = (a-1)*8;
			t1 += b;
			if( t1 >= 1 && t1 <= 64)
			{

			    adj[t].push_back(t1);
					cnt++;
			}

		   }
			a = i;
			b = j;

			a += 2;
			b++;
            if(b < 9  && a <9)
			{
			t1 = (a-1)*8;
			t1 += b;
			if( t1 >= 1 && t1 <= 64)
			{

			    adj[t].push_back(t1);
					cnt++;
			}

			}
			a = i;
			b = j;

			a += 2;
			b--;

			if(b > 0  && a < 9)
			{
			t1 = (a-1)*8;
			t1 += b;
				if( t1 >= 1 && t1 <= 64)
				{

					adj[t].push_back(t1);
						cnt++;
				}
			}

		}
	}
	  
	

	//cout << cnt << endl;

 	
 	while(cin >> first >> second)
 	{	       
		     src = first[1] - 48;
			 src--;

			 src = src*8;

			 t = first[0] - 'a' + 1;
			 src += t;

			 dest = second[1] - 48;
			 dest--;
			 dest = dest*8;
			 t = second[0] - 'a' + 1;
			 dest += t;

			 //cout << src << " " << dest<< endl;

			 if(src != dest)
			 {
		
			    BFS();
			    printf("To get from %s to %s takes %d knight moves.\n",first,second,get);
			 }
			 else
			 {
				 printf("To get from %s to %s takes 0 knight moves.\n",first,second);

			 }

		
		  	  
  	          	 
	 		  
    }
 	
 	
 	
 	return 0;
}
