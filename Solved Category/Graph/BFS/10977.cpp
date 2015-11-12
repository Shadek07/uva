
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)

typedef pair<int,int> grid;
map<grid,int> mp;
map<grid,int> visit;
#define eps 1e-8
int R,C;
int n;
int sr,sc,dr,dc;
bool mine[1001][1001];
bool vis[1001][1001];
struct state
{
	int r;
	int c;
	int step;
};

queue<state> pq;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int main(void)
{
	 int i,j,k,a,b,l;
	 grid g1,g2;
     int ind;
	 struct state s1,s2;
	 while(scanf("%d %d",&R,&C) == 2 && R && C)
	 {
		scanf("%d",&n);
		ind = 1;
		memset(mine,false,sizeof(mine));
		for(i = 0;i<n;i++)
		{
		   scanf("%d %d",&a,&b);			 
		   
		   mine[a-1][b-1] = true;				 			 
		 }

		 scanf("%d",&n);

		 for(i=0;i<n;i++)
		 {
			 scanf("%d %d %d",&a,&b,&l);
			 a--;
			 b--;
			 mine[a][b] = true;
			 for(j = a-l;j<=a+l;j++)
			 {
				 for(k = b-l;k<=b+l;k++)
				 {
					 if(j>= 0 && j<R && k>= 0 && k<C)
					 {
						 double dis;
						 dis = sqrt((j-a)*(j-a) + (k-b)*(k-b));
						 if(!(l*1.0<dis-eps))
							 mine[j][k] = true;
					 }
					 if(j<0 || j>R || k<0 || k>C)
						 continue;
				 }
			 }
		 }

		 s1.r = 0;
		 s1.c = 0;
		 s1.step = 0;
		 pq.push(s1);
		 
		 memset(vis,false,sizeof(vis));
		 vis[0][0] = true;
		 bool found = false;
		 while(!pq.empty())
		 {
			 s1 = pq.front();
			 pq.pop();
             if(s1.r == R-1 && s1.c == C-1)
			 {
				 cout << s1.step << endl;
				 while(!pq.empty())
					 pq.pop();
				 found = true;
				 break;
			 }
			 for(i = 0;i<4;i++)
			 {
				 a = s1.r+dx[i];
				 b = s1.c+dy[i];
				
				 if(a>=0 && a<R && b>=0 && b< C && !mine[a][b] && !vis[a][b] )
				 {
					 s2.r = a;
					 s2.c = b;
					 s2.step = s1.step+1;
					 vis[a][b] = true;
					 pq.push(s2);
				 }
			 }

		 }

		 if(found == false)
		 {
			 cout << "Impossible." << endl; 
		 }

		 

	 }
     return 0;
}