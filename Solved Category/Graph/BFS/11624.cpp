
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
#include <bitset>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>a?a:b))
#define min(a,b) ((a>b?b:a))
#define INF_MAX 2147483647

int jon[1005][1005];
int fire[1005][1005];
int r,c;
char in[1005][1005];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

struct state
{
       int x,y,step;
};

void reset ()
{
     int i,j;
     for ( i = 0; i < r; i++ ) 
     {
           for (  j = 0; j < c; j++ )
              jon [i][j] = fire [i][j] = INF_MAX;
    }
}

int jon_search(int x,int y,int step)
{
    int i,j,k;
    int a,b;
    queue<state> pq;
    struct state s1,s2;
    s1.x = x;
    s1.y = y;
    s1.step = 0;
    pq.push(s1);
    while(!pq.empty())
    {
        s1 = pq.front();
        pq.pop();
        for(k = 0;k<4;k++)
        {
              a = s1.x+dx[k];
              b = s1.y+dy[k];
              if(a>= 0 && a <r && b>= 0 && b < c && in[a][b] != '#' && jon[a][b] == INF_MAX)
              {
                     s2.x = a;
                     s2.y = b;
                     s2.step = s1.step + 1;                    
                     jon[a][b] = s1.step+1;
                     pq.push(s2);                        
              }
        }
    }
    
}

int fire_search()
{
    int i,j,k;
    int a,b;
    queue<state> pq;
    struct state s1,s2;
    
    for(i = 0;i<r;i++)
    {
          for(j = 0;j<c;j++)
          {
                if(in[i][j] == 'F')
                {
                      fire[i][j] = 0;   
                      s1.x = i;
                      s1.y = j;
                      s1.step = 0;
                      pq.push(s1);   
                }
          }
    }
    while(!pq.empty())
    {
        s1 = pq.front();
        pq.pop();
        for(k = 0;k<4;k++)
        {
              a = s1.x+dx[k];
              b = s1.y+dy[k];
              if(a>= 0 && a <r && b>= 0 && b < c && in[a][b] != '#' && s1.step+1 < fire[a][b])
              {
                     s2.x = a;
                     s2.y = b;
                     s2.step = s1.step + 1;                 
                     fire[a][b] = s1.step+1;                        
                     pq.push(s2);                         
              }
        }
    }
    
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int t,i,j,k;
    cin >> t;
    getchar();
    while(t--)
    {
        cin >>  r >> c;
        getchar();
        for(i = 0;i<r;i++)
              gets(in[i]); 
              
        //memset(fire,-1,sizeof(fire));
        //memset(jon,-1,sizeof(jon));   
        reset ();
        for(i = 0;i<r;i++)
        {
              for(j = 0;j<c;j++)
              {
                    if(in[i][j] == 'J')
                    {
                        jon[i][j] = 0;
                        jon_search(i,j,0);
                    }                   
                    
              }
        }
        
        fire_search();
        bool escape = false;
        long int mn = 999999999;
        
        //now check 4 edges of the grid whether it is possible for Jon to come in a boundary
        //square earlier than any fire source
        for(i = 0;i<c;i++) //first row,last row
        {
            if(jon[0][i] < fire[0][i])
            {
                if(jon[0][i] < mn)
                {
                             mn= jon[0][i];
                             escape = true;
                }        
            } 
            if(jon[r-1][i] < fire[r-1][i])
            {
                if(jon[r-1][i] < mn)
                {
                             mn= jon[r-1][i];
                             escape = true;
                }        
            }
            
        }
        
        for(i = 0;i<r;i++) //first col,last column
        {   
            if( jon[i][0] < fire[i][0])
            {
                if(jon[i][0] < mn)
                {
                             mn= jon[i][0];
                             escape = true;
                }        
            } 
            if( jon[i][c-1] < fire[i][c-1])
            {
                if(jon[i][c-1] < mn)
                {
                             mn= jon[i][c-1];
                             escape = true;
                }        
            }
        }
        
        if(escape == false)
        {
                  cout << "IMPOSSIBLE\n";
        }
        else
            cout << mn+1 << endl;
    }
    
    return 0;
}
