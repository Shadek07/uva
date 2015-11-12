#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char in[205][205];
int f;

bool check(char c)
{
     if(c != ' ' && c != '-' && c != '#' && c != '|' && c != '\0')
     return true;
     else
     return false;
}

void recur(int row,int col)
{
     int a,b,i,j;
     
     cout << in[row][col];
     cout << "(";
     
     if(row + 1 <= f)
     {
           if(in[row+1][col] == '|')
           {
                a = col;
                b = col;
                j = strlen(in[row+2]);
                while(a>= 0 && in[row+2][a--] == '-');
                while(b < j && in[row+2][b++] == '-'); 
                for(i =  a+1 ; i < b;i++)
                {
                      if(check(in[row+3][i]))
                      {
                            recur(row+3,i);                 
                      }
                }          
           }
           
     }
     
     
     cout << ")";
     return;

     
}
int main(void)
{
    int t;
    cin >> t;
    getchar();
    int i,j,k;
    int len;
    while(t--)
    {
              i = 0;
              memset(in,' ',sizeof(in));
              while(1)
              {
                  gets(in[i]);
                  if(in[i][0] == '#')
                  break;   
                  i++; 
              }
              f = i-1;
              len = strlen(in[0]);
              cout << "(";
              for(i = 0; i < len;i++)
              {
                    if(check(in[0][i]))
                    {
                        recur(0,i);
                        break;            
                    }
              }
                           
              cout << ")\n";
    }
    
    return 0;
}
