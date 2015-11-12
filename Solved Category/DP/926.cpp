
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
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

unsigned long  long int cal[35][35];

bool block[32][32][2];

int n;
int sx,sy,dx,dy;
int main(void)
{
    int t;
    cin >> t;
    int obs;
    char c;
    int a,b;
    int i,j;
    int ca=1;
    while(t--)
    {
        cin >> n;
        cin >> sx >> sy >> dx >> dy;
        cin >> obs;
        memset(block,false,sizeof(block));
        while(obs--)
        {
            scanf("%d %d %c",&a,&b,&c);
            if(c=='N')
            {
                      block[a][b][1]=true;
            }
            if(c=='W')
            {
                      block[a-1][b][0]=true;
            }
            if(c=='S')
            {
                      block[a][b-1][1]=true;
            }
            if(c=='E')
            {
                      block[a][b][0]=true;
            }
            
        }
        
        memset(cal,0,sizeof(cal));
        cal[sx][sy]  = 1;
        for(j = sy;j<=dy;j++)
        {
            for(i = sx;i<=dx;i++)
            {
                  if(j == sy && i == sx)
                  cal[sx][sy] = 1;
                  else
                  {
                      cal[i][j] = 0;
                      if(i-1>= 1 && block[i-1][j][0]==false)
                      cal[i][j] += cal[i-1][j];
                      if(j-1>= 1 && block[i][j-1][1]==false)
                      cal[i][j] += cal[i][j-1];
                  }                   
                    
            }             
        }
        
        cout << cal[dx][dy] << endl;
    }
    return 0;
}
