
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<sstream>
using namespace std;


int  N=1001,  M=1001;  
int  order[101],top_place; 
bool v[101];
int  comp[101];  //   component  id 
int  curr_comp; 
map<string,int> mp;
map<int,string> pm;
vector<int> adj[30];
vector<int> rev[30];
vector<int> component[30];
int cnt;
set<int> st;

int fall;
void  dfs(int  a)   
{ 
   if (v[a])  
	   return; 
   v[a]=true; 
   int i;
   int len = adj[a].size();
   for (i =  0 ; i <len;i++) 
   {
	   if(v[adj[a][i]] == false)
		  dfs(adj[a][i]); 
   }

   top_place--; 
   order[top_place] = a; 
}

//dfs  on  the  reversed  graph 
void  dfs_rev(int  a)    
{ 
	 int i,len;
     if(!v[a])  
		return; 

     v[a] = false; 
     comp[a] = curr_comp;
	 component[curr_comp].push_back(a);
	 len = rev[a].size();

     for(i=0;i<len;i++)  
	 {
		 if(v[rev[a][i]] == true)
			dfs_rev(rev[a][i]); 
	 }
} 

void  top()  
{ 
     int  i; 
     top_place  = N+1; 
     for(i=1;  i<=N;i++)  
		 v[i]=false; 
	//memset(v,false,sizeof(v));
     for(i=1;  i<=N;i++)  
		 if(!v[i])  
			 dfs(i); 
} 


void  scc()  
{ 
     int  i,j,a,b,k; 
     top(); 
     //for(i=1;  i<=N;i++)  
		// v[i]=false; 
	 //memset(v,false,sizeof(v));
	 cnt = 0;
     for(i=1;i<=N;i++) 
     { 
          int  j  = order[i]; //j is a vertex, i is finishing time for vertex j
          if(v[j])  
		  { 
			  curr_comp = cnt++; 
			  dfs_rev(j); 
		  } 
   } 

   
   for(i = 0;i<cnt;i++)
   {
	   j = component[i].size();
	   cout << pm[component[i][0]];
	   for(k = 1;k<j;k++)
	   {
		   cout << ", " << pm[component[i][k]];
	   }
	   cout << endl;
	   component[i].clear();
   }

	 

   //return cnt;//num of SCCs
} 

int main(void)
{
	
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[100],in1[100];
	string s1;
	int i,m,n,a,b;
	bool ch = true;
	int ind;
	int t;
    int ca=1;
	while(cin >> n >> m)
	{
		if(!n && !m)
			break;
		ind = 1;		
		for(i = 0;i<m;i++)
		{
			cin >> in >> in1;
			if(!mp[in])
			{
				mp[in] = ind++;
				pm[ind-1] = in;
				a = ind-1;
			}
			else
				a = mp[in];
			if(!mp[in1])
			{
				mp[in1] = ind++;
				pm[ind-1] = in1;
				b = ind-1;
			}
			else
				b = mp[in1];

			adj[a].push_back(b);
			rev[b].push_back(a);
		}

		N = n;

		if(ca==1)
			;
		else
			cout << endl;
		cout << "Calling circles for data set " << ca++ << ":\n";

		scc();
		
		


		for(i = 1;i<=N;i++)
		{
			adj[i].clear();
			rev[i].clear();
		}
		mp.clear();
		pm.clear();
	}	
	return 0;
}