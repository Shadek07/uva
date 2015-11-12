#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int r,c,n;

char mp[101][101];
char temp[101][101];

map<char,char> hit;  //hit[i] = j, j hits i

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool attacker(int i,int j,char c2)
{
     int k,a,b;
     for(k = 0; k <4;k++)
     {
           a = i+dx[k];
           b = j+dy[k];
           if(a >= 0 && a < r && b >= 0 && b < c)
           {
               if(mp[a][b] == c2)
               return true; 
           }
     }
     
     return false;
}
int main(void)
{
    int t;
    int a,b,i,j,k;
    int ch=0;
    cin >> t;
    
    hit['S']='R';
    hit['P']='S';
    hit['R']='P';
    char c2,c1;
    bool t1;
    while(t--)
    {
              cin >> r >> c >> n;
              getchar();
              for(i = 0; i < r;i++)
              gets(mp[i]);
              
              for(i = 0; i < n;i++)
              {
                    for(j = 0; j < r;j++)
                    {
                          for(k = 0; k < c;k++)
                          {
                              c2 = hit[mp[j][k]]; 
                              t1 = attacker(j,k,c2);
                              if(t1)
                              temp[j][k] = c2; 
                              else
                              temp[j][k] = mp[j][k];
                          }
                    }
                    
                    for(j = 0; j < r;j++)
                    {
                          for(k = 0; k < c;k++)
                          {
                              mp[j][k] = temp[j][k]; 
                          }
                    }
              }
              
              if(ch==false)
              ch = true;
              else
              cout << endl;
              for(i = 0; i < r;i++)
              {
                    for(j = 0; j < c;j++)
                    cout << mp[i][j];
                    cout << endl;
              }
              
    }
    return 0;
}
