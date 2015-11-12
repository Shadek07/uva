
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
#define max(a,b) a>a?a:b
#define min(a,b) a>b?b:a

char in[101][101];
int n,m,s;
char go[50001];
int dir;
bool vis[101][101];

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int x,y,b,a,len;
	int cnt;
	while(scanf("%d %d %d",&n,&m,&s)== 3 && n && m && s)
	{
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(in[i]);
		}

		gets(go);
		memset(vis,false,sizeof(vis));
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<m;j++)
			{
				if(in[i][j] == 'N')
				{
					dir = 0;
					x = i;
					y = j;
					i = n;
					break;
				}
				else if(in[i][j] == 'S')
				{
					dir = 2;
					x = i;
					y = j;
					i = n;
					break;
				}
				else if(in[i][j] == 'L')
				{
					dir = 3;
					x = i;
					y = j;
					i = n;
					break;
				}
				else if(in[i][j] == 'O')
				{
					dir = 1;
					x = i;
					y = j;
					i = n;
					break;
				}
			}
		}
		cnt = 0;
		len = s;
		for(i = 0;i<len;i++)
		{
			if(go[i] == 'F')
			{
				if(dir == 0)
				{
					a = x-1;
					b = y;
				}
				else if(dir == 1)
				{
					a = x;
					b = y-1;
				}
				else if(dir == 2)
				{
					a = x+1;
					b = y;
				}
				else
				{
					a = x;
					b = y+1;
				}
				if(a>= 0 && a<n && b >= 0 && b < m)
				{
					if(in[a][b] == '.')
					{
						x = a;
						y = b;
					}
					else if(in[a][b] == 'N'||in[a][b] == 'S'||in[a][b] == 'L'||in[a][b]== 'O')
					{
						x = a;
						y = b;
					}
					else if(in[a][b] == '*')
					{
						x = a;
						y = b;
						if(vis[a][b] == false)
						{
							cnt++;
							vis[a][b] = true;
						}
					}
				}
			}
			else if(go[i] == 'D')
			{
				  if(dir == 0)
					  dir = 3;
				  else if(dir == 1)
					  dir = 0;
				  else if(dir == 2)
					  dir = 1;
				  else if(dir == 3)
					  dir = 2;
			}
			else
			{
				  if(dir == 0)
					  dir = 1;
				  else if(dir == 1)
					  dir = 2;
				  else if(dir == 2)
					  dir = 3;
				  else if(dir == 3)
					  dir = 0;

			}
		}

		cout << cnt << endl;



	}
     return 0;
}
