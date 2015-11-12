
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
int  order[1001],v[1001],top_place; 
int  comp[1001];  //   component  id 
int  curr_comp; 
map<string,int> mp;
vector<int> adj[1001];
vector<int> rev[1001];

int cnt;
set<int> st;
void  dfs(int  a)   
{ 
   if (v[a])  
	   return; 
   v[a]   = 1; 
   int i;
   int len = adj[a].size();
   for (i =  0 ; i <len;i++)   
		 dfs(adj[a][i]); 
   top_place--; 
   order[top_place] = a; 
} 

//dfs  on  the  reversed  graph 
void  dfs_rev(int  a)    
{ 
	 int i,len;
     if(v[a])  
		 return; 
     v[a]  =  1; 
     comp[a]  =   curr_comp; 
	 len = rev[a].size();
     for(i=0;i<len;i++)  
			 dfs_rev(rev[a][i]); 
} 

void  top()  
{ 
     int  i; 
     top_place  =   N+1; 
    // for(i=1;  i<=N;i++)  
		 //v[i]=0; 
	 memset(v,0,sizeof(v));
     for(i=1;  i<=N;i++)  
		 if(!v[i])  
			 dfs(i); 
} 

int  scc()  
{ 
     int  i; 
     top(); 
     //for(i=1;  i<=N;i++)  v[i]=0; 
	 memset(v,0,sizeof(v));
	 cnt = 0;
     for(i=1;i<=N;i++) 
     { 
          int  j  = order[i]; 
          if(!v[j])  
		  { 
			  curr_comp  = cnt++; 
			  dfs_rev(j); 
		  } 
   } 

	 return cnt;
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
	while(cin >> n >> m)
	{
		if(!n && !m)
			break;
		getchar();		
		ind = 1;
		for(i = 0;i<n;i++)
		{
			gets(in);
			mp[in] =ind++;
		}

		N = ind-1;
		for(i = 0;i<m;i++)
		{
			gets(in);
			a = mp[in];
			gets(in);
			b = mp[in];
			adj[a].push_back(b);
			rev[b].push_back(a);
		}

		cout << scc()<<endl;


		for(i = 1;i<=N;i++)
		{
			adj[i].clear();
			rev[i].clear();
		}

	}

	
	return 0;
}