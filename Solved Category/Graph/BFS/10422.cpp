#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<string>
struct board
{
       char state[5][6];
       int level;
       int bx;//empty x
       int by;//empty y
};

using namespace std;
char in[5][6];
char tar[5][6] = {"11111","01111","00 11","00001","00000"};
queue<board> pq;
int dx[] ={-2,-2,2,2,-1,1,-1,1};
int dy[] ={1,-1,1,-1,2,2,-2,-2};
string s1,s2;
map<string,int> mp;
int ind;
int check(char in[5][6])
{
    int i;
    for(i = 0; i<5;i++)
    {
          if(strcmp(in[i],tar[i]) != 0)
               return 0;
    }
    return 1;
}

int in_grid(int a,int b)
{
    if(a >= 0 && a <5 && b >= 0 && b<5)
         return 1;
    else
        return 0;
}

int main(void)
{
    int t;
    int i,j,a,b,nx,ny,tx,ty;
    char temp[5][6],c;
    struct board bd,tmp;
    cin >> t;
    getchar();
    int res;
    while(t--)
    {
         ind = 1;
         for(i = 0; i <5;i++)
         {
               gets(in[i]);
               strcpy(bd.state[i],in[i]);
               for(j = 0;j<5;j++)
               {
                     if(in[i][j] == ' ')
                     {
                        a = i;
                        b=j;
                     }                
               }
         }
         //cout << a << " " << b<<endl;
         bd.level = 0;
         bd.bx = a;
         bd.by = b;
         pq.push(bd);
         res = -1;
         while(!pq.empty())
         {
               tmp = pq.front();
               pq.pop();
               a = tmp.bx;
               b = tmp.by;
               int a1 = check(tmp.state);
               
               if(a1 == 1)
               {
                    res = tmp.level;
                    break;
               }
               
               if(tmp.level == 10)
                   continue;
               for(i = 0; i <8;i++)
               {
                     nx = a+dx[i];
                     ny = b+dy[i];
                     if(in_grid(nx,ny))
                     {
                          for(j = 0;j<5;j++)
                             strcpy(bd.state[j],tmp.state[j]);
                          
                           //swap between empty cell and black/white horse
                           c =  bd.state[nx][ny];
                           bd.state[nx][ny]=bd.state[a][b];
                           bd.state[a][b] = c;
                           s1 = "";
                           for(j = 0;j<5;j++)
                               s1 += bd.state[j];
                           if(!mp[s1])
                           {
                               bd.bx = nx;
                               bd.by = ny;
                               bd.level = tmp.level + 1;
                               mp[s1] = ind++;
                               pq.push(bd);
                           }
                     }
               }
         }
         
         while(!pq.empty())
              pq.pop();
         mp.clear();
         if(res == -1)
            cout << "Unsolvable in less than 11 move(s).\n";
         else
             cout << "Solvable in " << res <<" move(s).\n";
    }
    
}
