#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[8000];
char str1[8000];

int fir[35][35];
int sec[35][35];

int ind;
int term;

void fill(int x,int y,int size,int wh)
{
     int i,j;
     for(i = x;i<x+size;i++)
     {
           for(j = y;j<y+size;j++)
           {
                 if(term == 1)
                 fir[i][j] = wh;  //wh = 0 means white,wh = 1 means black
                 else
                 sec[i][j] = wh;
           }
     }
}



void func(int size,int row,int col)
{
     int x,y;
     int a,b;
     int i,j,k;
     char ch;
     
     if(size == 0)
     {
             ind++;
             if(term == 1)
             ch = str[ind];
             else
             ch = str1[ind];
             if(ch == 'e')
             {
                   if(term == 1)
                   {
                           fir[row][col] = 0;
                   }
                   else
                   sec[row][col] = 0;
             }
             else
             {
                 if(term == 1)
                 {
                       fir[row][col] = 1;
                 }
                 else
                 sec[row][col] = 1;
                 
             }
             
             
             
             return;             
     }
     
     ind++;
     if(term == 1)
     ch = str[ind];
     else
     ch = str1[ind];
     if(ch == 'e' || ch == 'f')
     {
          x = row-size;
          y = col;
          if(ch == 'e')
          {
              fill(x,y,size,0);        
          }
          else
          {
              fill(x,y,size,1);
          }                 
     }
     else
     {
         a = row - (size/2);
         b = col + (size/2);
         func(size/2,a,b);
     }
     
     ind++;
     if(term == 1)
     ch = str[ind];
     else
     ch = str1[ind];
     if(ch == 'e' || ch == 'f')
     {
          x = row-size;
          y = col-size;
          if(ch == 'e')
          {
              fill(x,y,size,0);        
          }
          else
          {
              fill(x,y,size,1);
          }                 
     }
     else
     {
         a = row - (size/2);
         b = col - (size/2);
         func(size/2,a,b);
     }
     
     ind++;
     if(term == 1)
     ch = str[ind];
     else
     ch = str1[ind];
     if(ch == 'e' || ch == 'f')
     {
          x = row;
          y = col-size;
          if(ch == 'e')
          {
              fill(x,y,size,0);        
          }
          else
          {
              fill(x,y,size,1);
          }                 
     }
     else
     {
         a = row + (size/2);
         b = col - (size/2);
         func(size/2,a,b);
     }
     
     ind++;
     if(term == 1)
     ch = str[ind];
     else
     ch = str1[ind];
     if(ch == 'e' || ch == 'f')
     {
          x = row;
          y = col;
          if(ch == 'e')
          {
              fill(x,y,size,0);        
          }
          else
          {
              fill(x,y,size,1);
          }                 
     }
     else
     {
         a = row + (size/2);
         b = col + (size/2);
         func(size/2,a,b);
     }
}

//16,16,16
//8,8,8
//2,2,2
int main(void)
{
    int t;
    cin >> t;
    getchar();
    int i,j;
    int cnt;
    while(t--)
    {
              gets(str);
              gets(str1);
              ind = 0;
              term = 1;
              if(strlen(str) == 1)
              {
                   if(str[0] == 'e')
                   {
                             fill(0,0,32,0);
                   }
                   else
                   fill(0,0,32,1);         
              }
              else
              func(16,16,16);
              
              term = 2;
              ind = 0;
              if(strlen(str1) == 1)
              {
                   if(str1[0] == 'e')
                   {
                             fill(0,0,32,0);
                   }
                   else
                   fill(0,0,32,1);         
              }
              else
              func(16,16,16);
              cnt = 0;
              for(i = 0; i <32;i++)
              {
                    for(j = 0; j <32;j++)
                    {
                          if(fir[i][j] == 1 || sec[i][j] == 1)
                          cnt++;
                    }
              }
              
              cout << "There are " << cnt << " black pixels.\n";
    }
    
    return 0;
}
