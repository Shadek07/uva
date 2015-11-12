#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

int n;

bool eq[101];

int x[] = {0,-1,0,1};
int y[] = {1,0,-1,0};

vector<int> v[101];
bool visit[101][101];
int value[101][101];
char in[10000];
int cnt;
int ind;
bool check(int a,int b)
{
     if(a >= 1 && a <= n && b >= 1 && b <= n)
     return true;
     else
     return false;
}
void dfs(int a,int b)
{
     int i;
     int c,d;
     visit[a][b] = true;
     cnt++;
     for(i = 0; i < 4;i++)
     {
           c = a+x[i];
           d = b+y[i];
           if(check(c,d) && !visit[c][d] && value[c][d] == ind)
           {
                 dfs(c,d);        
           }
     }
}
int main(void)
{
    int i,j,k;
    int a,b;
    char *p;
    int ch;
    while(1)
    {
           cin >> n;
           if(!n)
           break;
           getchar();
           ind = 1;
           //memset(value,n,sizeof(value));
           for(i = 1; i <= n;i++)
           {
                 for(j = 1;j<=n;j++)
                 value[i][j] = n;
           }
           memset(visit,false,sizeof(visit));
           ch = 1;
           
           for(i = 0; i < n-1;i++)
           {
                 gets(in);
                 //cout << value[1][1] << endl;
                 p = strtok(in,"         ");
                 while(p != NULL)
                 {
                         a = atoi(p);
                         p = strtok(NULL,"      ");
                         b = atoi(p);
                         if(check(a,b) && value[a][b] == n)
                         value[a][b] = ind;
                         p = strtok(NULL,"      ");
                 }
                 cnt = 0;
                 dfs(a,b);
                 if(cnt != n)
                 ch = 0;
                 ind++;
           }
           
           for(i = 1;i<=n;i++)
           {
                 for(j = 1;j<=n;j++)
                 {
                       if(value[i][j] == n)
                       {
                           cnt = 0;
                           dfs(i,j);
                           if(cnt != n)
                           ch = 0;
                           i = n+1;
                           break;
                       }
                 }
           }
           
           if(ch == 1)
           cout << "good\n";
           else
           cout << "wrong\n";
              
    }
    
    return 0;
}
