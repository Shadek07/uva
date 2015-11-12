
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
int  order[2001],top_place; 
bool v[2001];
int  comp[2001];  //   component  id 
int  curr_comp; 
map<string,int> mp;
vector<int> adj[2001];
vector<int> rev[2001];

int cnt;
set<int> st;
int rep[2001]; //rep[i] is a representative vertex for i'th Strongly Connected Component(SCC)

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


bool  scc()  
{ 
     int  i,j,a,b; 
     top(); 
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

   if(cnt==1)
	   return true;
   else
	   return false;

   //return cnt;//num of SCCs
} 

int main(void)
{
	
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[100];
	string s1;
	int i,m,n,a,b,c;
	bool ch = true;
	int ind;
	int t;
    int ca=1;
	while(1)
	{
		cin >> n >> m;
		if(!n && !m)
			break;
				
		for(i = 0;i<m;i++)
		{
			cin >> a >> b >> c;
			if(c == 1)
			{
				adj[a].push_back(b);
				rev[b].push_back(a);
			}
			else
			{
				adj[a].push_back(b);
				adj[b].push_back(a);
				rev[b].push_back(a);
				rev[a].push_back(b);

			}
		}

		N = n;
		
		ch = scc();
		if(ch==true)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		


		for(i = 1;i<=N;i++)
		{
			adj[i].clear();
			rev[i].clear();
		}
	}
	
	return 0;
}