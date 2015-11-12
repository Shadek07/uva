
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


int  N=1000,  M=1000;  
int  r[100][100];  //adjacency  matrix 
int  order[100],v[100],top_place; 
int  comp[100];  //   component  id 
int  curr_comp; 
int cnt;
vector<int> adj[10001];

void  dfs(int  a)   
{ 
   if (v[a])  return; 
   v[a]   = 1; 
   int i;
   for (i =  0 ; i <=N;i++) 
     if(a != i && r[a][i])  
		 dfs(i); 
   top_place--; 
   order[top_place]  =  a; 
} 

//dfs  on  the  reversed  graph 
void  dfs_rev(int  a)    
{ 
	 int i;
     if(v[a])  
		 return; 
     v[a]  =  1; 
     comp[a]  =   curr_comp; 
     for(i=0;i<=N;i++)  
		 if(a != i && r[i][a])
			 dfs_rev(i); 
} 

void  top()  
{ 
     int  i; 
     top_place  =   N+1; 
     for(i=0;  i<=N;i++)  
		 v[i]=0; 
     for(i=0;  i<=N;i++)  
		 if(!v[i])  
			 dfs(i); 
} 

void  scc()  
{ 
     int  i; 
     top(); 
     for(i=0;  i<=N;i++)  v[i]=0; 
	 cnt = 1;
     for(i=0;i<=N;i++) 
     { 
          int  j  = order[i]; 
          if(!v[j])  
		  { 
			  curr_comp  = cnt++; 
			  dfs_rev(j); 
		  } 
   } 
} 
int main(void)
{
	memset(r,0,sizeof(r));
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[100];
	string s1;
	int i,j,m,n,a,b;
	char c1,c2,c3,c4,c5,c6;
	bool present[30];
	bool take[30];
	bool ch = true;
	while(cin >> n && n)
	{
		getchar();
		memset(r,0,sizeof(r));
		memset(present,false,sizeof(present));
		for(i = 0;i<n;i++)
		{
			gets(in);
			s1 = in;
			istringstream is(s1);
			is >> in;
			c1 = in[0];
			is >> in;
			c2 = in[0];
			is >> in;
			c3 = in[0];
			is >> in;
			c4 = in[0];
			is >> in;
			c5 = in[0];
			is >> in;
			c6 = in[0];
			present[c1-'A'] = present[c2-'A']=present[c3-'A']=present[c4-'A']=present[c5-'A']=present[c6-'A']=true;
			if(c1 != c6)
			r[c1-'A'][c6-'A'] = 1;
			if(c2 != c6)
			r[c2-'A'][c6-'A'] = 1;
			if(c3 != c6)
			r[c3-'A'][c6-'A'] = 1;
			if(c4 != c6)
			r[c4-'A'][c6-'A'] = 1;
			if(c5 != c6)
			r[c5-'A'][c6-'A'] = 1;
			if(c6 != c6)
			r[c6-'A'][c6-'A'] = 1;
		}

		N = 25;
		scc();
		memset(take,false,sizeof(take));
		if(ch==true)
			ch = false;
		else
			cout << endl;
		for(i = 0;i<=N;i++)
		{
			if(present[i] && take[i] == false)
			{
				cout << char(i+'A');
				a = comp[i];
				take[i] = true;
				for(j = i+1;j<=N;j++)
				{
					if(i != j && present[j] && comp[j] == a && take[j] == false)
					{
						cout << " " << char(j+'A');
						take[j] = true;
					}
				}
				cout << endl;
			}
		}

	}

	
	return 0;
}