
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
int  order[100001],top_place; 
bool v[100001];
int  comp[100001];  //   component  id 
int  curr_comp; 
map<string,int> mp;
vector<int> adj[100001];
vector<int> rev[100001];

int cnt;
set<int> st;
int rep[100001]; //rep[i] is a representative vertex for i'th Strongly Connected Component(SCC)
int indeg[100001]; //indeg[i] is num of indegree of i'th SCC
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
	 rep[curr_comp] = a;
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

void visit_all(int a,int cmp)
{
	v[a] = true;
	int i,j,len;
	len = adj[a].size();
	for(i = 0;i<len;i++)
	{
		if(v[adj[a][i]] == false)
		{
			if(comp[adj[a][i]] != cmp)
			{
				indeg[comp[adj[a][i]]]++;
			}
			else
			{
				visit_all(adj[a][i],cmp);
			}
		}
	}

}
void  scc()  
{ 
     int  i,j,a,b; 
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
		 indeg[i] = 0;
	 }
	for(i = 0;i<cnt;i++)
	{
		a = rep[i];
		visit_all(a,i);
	}
	j = 0;
	for(i = 0;i<cnt;i++)
	{
		if(indeg[i] == 0)
			j++;
	}
	fall = j;

   //return cnt;//num of SCCs
} 

int main(void)
{
	
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[100];
	string s1;
	int i,m,n,a,b;
	bool ch = true;
	int ind;
	int t;
	cin >> t;
    //int ca=1;
	while(t--)
	{
		cin >> n >> m;
				
		for(i = 0;i<m;i++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			rev[b].push_back(a);
		}

		N = n;
		
		scc();
		//cout << "Case " << ca++ << ": ";
		cout << fall << endl;


		for(i = 1;i<=N;i++)
		{
			adj[i].clear();
			rev[i].clear();
		}
	}	
	return 0;
}