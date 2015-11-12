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

using namespace std;

bool visit[41][101];
char grid[41][101];
int r,c;
char in[101];

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool check(int a,int b)
{
     if(a >= 0 && a < r && b >= 0 && b < c)
     return true;
     else
     return false;
}

void dfs(int i,int j,char c)
{
     grid[i][j] = c;
     visit[i][j] = true;
     int a,b,k;
     for(k = 0; k < 4;k++)
    {
        a = i+dx[k];
        b = j+dy[k]; 
        if(check(a,b) && visit[a][b] == false  && (grid[a][b] == ' '))
        {
             dfs(a,b,c);        
        } 
    }
}

int main(void)
{
    int t,i,j,k;
    
    
    while(gets(in))
    {
              r = c = 1;
			  memset(grid,'\0',sizeof(grid));
			  strcpy(grid[0],in);
              while(gets(in))
              {
                   if(in[0] == '_')
                   {
                       strcpy(grid[r],in);
                       break;
                   }
                   r++;
                   int l = strlen(in);
                   if(l > c)
                   c = l; 
                   strcpy(grid[r-1],in);         
              }
              
              memset(visit,false,sizeof(visit));
              
              for(i = 0; grid[i][0] != '_';i++)
              {
                    for(j = 0; grid[i][j];j++)
                    {
                          if(grid[i][j] != ' ' && grid[i][j] != 'X')
                          {
                                        dfs(i,j,grid[i][j]);
                          }
                    }
              }
              
              for(i = 0; i <= r;i++)
              {
                    cout << grid[i] << endl;
              }
              
               memset(grid,'\0',sizeof(grid));
    }
    
}
