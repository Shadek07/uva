#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<queue>
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
int corr;
map<string,int> mp;

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
							 corr = 1;
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

	int test,dataset = 1;
	int shipment_size;
	int n,m,query,i,j,a,b;
	string s1,s2;
	int ind;
	cin >> test;
	getchar();
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	while(test--)
	{
		cout << "DATA SET  " << dataset++ << endl << endl;
		cin >> n >> m >> query;
		getchar();
		ind  = 1;
		for(i = 0; i < n;i++)
		{
			cin >> s1;
			mp[s1] = ind++;
		}
		getchar();

		for(i = 0; i < m;i++)
		{
			cin >> s1 >> s2;
			a = mp[s1];
			b = mp[s2];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for(i = 0; i < query;i++)
		{
			cin >> shipment_size >> s1 >> s2;
			getchar();
			src = mp[s1];
			dest = mp[s2];
			corr = 0;
			BFS();
			if(corr == 1)
			{
				cout << "$" << shipment_size*get*100 << endl;
			}
			else
			{
				cout << "NO SHIPMENT POSSIBLE\n";
			}
		}

		cout << endl;


		for(i = 0;i < 40; i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
		}

		mp.clear();

	}

	cout << "END OF OUTPUT\n";
	return 0;
}