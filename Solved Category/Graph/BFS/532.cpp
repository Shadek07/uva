#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>

using namespace std;



#define  un 0
#define  dis 1
#define comp 2;


vector<int>adj[27001];
struct place
{
	int level;
	int row;
	int column;
	int value;
	int visit;
	char ch;
}in[35][35][35];

queue<place> q;

int corr;
int L,R,C;
//map<string,int> mp;

void BFS()
{
 	 
 			 int u,i;
 			 
 			 int l,r,c,v;
			 int l1,r1,c1;
			 struct place p2,p3;

     
     
          p2 = q.front();
		  l = p2.level;
		  r = p2.row;
		  c = p2.column;
		  
		  in[l][r][c].visit = 2;

		  if(l+1 < L && in[l+1][r][c].ch != '#' && in[l+1][r][c].visit == 0)
		  {
			  p3.level = l+1;
			  p3.row = r;
			  p3.column = c;
			  p3.ch = in[l+1][r][c].ch;
			  p3.value = p2.value + 1;
			  in[l+1][r][c].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  if(l-1 >= 0 && in[l-1][r][c].ch != '#' && in[l-1][r][c].visit == 0)
		  {
			  p3.level = l-1;
			  p3.row = r;
			  p3.column = c;
			  p3.ch = in[l-1][r][c].ch;
			  p3.value = p2.value + 1;
			  in[l-1][r][c].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  if(r+1 < R && in[l][r+1][c].ch != '#' && in[l][r+1][c].visit == 0)
		  {
			  p3.level = l;
			  p3.row = r+1;
			  p3.column = c;
			  p3.ch = in[l][r+1][c].ch;
			  p3.value = p2.value + 1;
			  in[l][r+1][c].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  if(r-1 >= 0 && in[l][r-1][c].ch != '#' && in[l][r-1][c].visit == 0)
		  {
			  p3.level = l;
			  p3.row = r-1;
			  p3.column = c;
			  p3.ch = in[l][r-1][c].ch;
			  p3.value = p2.value + 1;
			  in[l][r-1][c].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  if(c+1 < C && in[l][r][c+1].ch != '#' && in[l][r][c+1].visit == 0)
		  {
			  p3.level = l;
			  p3.row = r;
			  p3.column = c+1;
			  p3.ch = in[l][r][c+1].ch;
			  p3.value = p2.value + 1;
			  in[l][r][c+1].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  if(c-1 >= 0 && in[l][r][c-1].ch != '#' && in[l][r][c-1].visit == 0)
		  {
			  p3.level = l;
			  p3.row = r;
			  p3.column = c-1;
			  p3.ch = in[l][r][c-1].ch;
			  p3.value = p2.value + 1;
			  in[l][r][c-1].visit=p3.visit = 1;
			  q.push(p3);
		  }

		  

          q.pop();

        
 	 
}


int main(void)
{
	int i,j,k,value,a,b;
	while(1)
	{
		cin >> L >> R >> C;
		getchar();
		if(!L && !R && !C)
			break;
		for(i = 0; i < L;i++)
		{
			for(j = 0; j < R;j++)
			{
				for(k = 0; k < C; k++)
				{
					cin >> in[i][j][k].ch;
					in[i][j][k].level = i;
					in[i][j][k].row = j;
					in[i][j][k].column = k;
					in[i][j][k].visit = 0;
					in[i][j][k].level = 5555555;
					
				}
			}
			getchar();
			getchar();
		}

		for(i = 0; i < L;i++)
		{
			for(j = 0; j < R;j++)
			{
				for(k = 0; k < C;k++)
				{
					if(in[i][j][k].ch == 'S')
					{
						struct place p1;
						p1.level = i;
						p1.row = j;
						p1.column = k;
						p1.ch = 'S';
						p1.visit=in[i][j][k].visit = 0;
						q.push(p1);
						break;
					    
					}
				}
			}

			
		}

		while(!q.empty())
		{
			if ( in[q.front().level] [q.front().row] [q.front().column].visit != 1)
			BFS();
		}
	
		corr = 0;
				
		for(i = 0; i < L;i++)
		{
			for(j = 0; j < R;j++)
			{
				for(k = 0; k < C;k++)
				{	
					if(in[i][j][k].ch == 'E' && in[i][j][k].value < 5555555)
					{
						cout << "Escaped in " << in[i][j][k].value << " minute(s).\n";
						corr = 1;
					}
				}
			}
		}

		if(corr == 0)
		{
			cout << "Trapped!\n";
		}

	

		

	}
	return 0;
}