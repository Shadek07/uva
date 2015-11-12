#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<sstream>
#include<fstream>

using namespace std;
int n;
int sz1;
char out[1030][1030];
int letter[30];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int gx,gy;


int get_block(int size,int hy,int hx,int starty,int startx)
{
    int half = size/2;
    if(hy >= starty && hy < (starty+half) && hx >= startx && hx < (startx+half))
    return 1;
    else if(hy >= (starty+half) && hy < (starty+size) && hx >= startx && hx < (startx+half))
    return 2;
    else if(hy >= starty && hy < (starty+half) && hx >=(startx+half) && hx <(startx+size))
    return 3;
    else
    return 4;    
}
int p,q;

void fillup(int y,int x)
{
     int i,a,b;
     for(i = 0;i<8;i++)
     {
           a = x+dx[i];
           b = y+dy[i];
           if(out[a][b] >= 'a' && out[a][b] <= 'z')
           letter[out[a][b]-'a'] = 1;
     }
     
}
void recur(int size,int hy,int hx,int starty,int startx)
{
     int sz,i,j;
     int block;
     char c;
     int a,b;
     
     if(size == 2)
     {
         memset(letter,0,sizeof(letter));
         a = startx;
         b = starty;
         if(!(a == hx && b == hy))
         {
             fillup(b,a); 
         }
         a = startx;
         b = starty+1;
         if(!(a == hx && b == hy))
         {
             fillup(b,a); 
         }
         a = startx+1;
         b = starty;
         if(!(a == hx && b == hy))
         {
             fillup(b,a); 
         }
         a = startx+1;
         b = starty+1;
         if(!(a == hx && b == hy))
         {
             fillup(b,a); 
         }
         
          for(i = 0; i < 26;i++)
          {
               if(letter[i] == 0)
               {
                     c = 'a' + i;
                     
                     a = startx;
                     b = starty;
                     if( !(a == hx && b == hy))
                     {
                         //if(out[a][b] == '#')
                         out[a][b] = c; 
                     }
                     a = startx;
                     b = starty+1;
                     if(!(a == hx && b == hy))
                     {
                         //if(out[a][b] == '#')
                         out[a][b] = c; 
                     }
                     a = startx+1;
                     b = starty;
                     if(!(a == hx && b == hy))
                     {
                         //if(out[a][b] == '#')
                         out[a][b] = c; 
                     }
                     a = startx+1;
                     b = starty+1;
                     if( !(a == hx && b == hy))
                     {
                         //if(out[a][b] == '#')
                         out[a][b] = c; 
                     }
                     //cout <<sz<<endl;
                     /*for(p = 1;p<=sz1;p++)
                        {
                              for(q = 1;q<=sz1;q++)
                              {
                                    cout << out[p][q];
                              }
                              cout << endl;
                        }
                        cout << endl;*/
                     return;
               }
          }    
     }
     
     int arr[6]= {0,1,1,1,1};
     block = get_block(size,hy,hx,starty,startx);
     arr[block] = 0;
     memset(letter,0,sizeof(letter));
     if(arr[1] == 1)
     {
         fillup(starty+(size/2)-1,startx+(size/2)-1);      
     }
     if(arr[2] == 1)
     {
         fillup(starty+(size/2),startx+(size/2)-1);      
     }
     if(arr[3] == 1)
     {
         fillup(starty+(size/2)-1,startx+(size/2));      
     }
     if(arr[4] == 1)
     {
         fillup(starty+(size/2),startx+(size/2));      
     }
     
     for(i = 0; i < 26;i++)
     {
           if(letter[i] == 0)
           {
                 c = 'a' + i;
                 if(arr[1] == 1)
                 {
                     //if(out[startx+(size/2)-1][starty+(size/2)-1] == '#')
                     out[startx+(size/2)-1][starty+(size/2)-1] = c;      
                 }
                 if(arr[2] == 1)
                 {
                     //if(out[startx+(size/2)-1][starty+(size/2)] == '#')
                     out[startx+(size/2)-1][starty+(size/2)] = c;      
                 }
                 if(arr[3] == 1)
                 {
                     //if(out[startx+(size/2)][starty+(size/2)-1] == '#')
                     out[startx+(size/2)][starty+(size/2)-1] = c;      
                 }
                 if(arr[4] == 1)
                 {
                     //if(out[startx+(size/2)][starty+(size/2)] == '#')
                     out[startx+(size/2)][starty+(size/2)] = c;      
                 }
                 break;       
           }
     }
     
    
     if(block != 1)
     recur(size/2, starty+(size/2)-1,startx+(size/2)-1, starty,startx);
     else
     recur(size/2, hy,hx, starty,startx);
     if(block != 2)
     recur(size/2,starty+(size/2),startx+(size/2)-1,starty+(size/2),startx);
     else
     recur(size/2,hy,hx,starty+(size/2),startx);
     if(block != 3)
     recur(size/2,starty+(size/2)-1,startx+(size/2),starty,startx+(size/2));
     else
     recur(size/2,hy,hx,starty,startx+(size/2));
     if(block != 4)
     recur(size/2,starty+(size/2),startx+(size/2),starty+(size/2),startx+(size/2));
     else
     recur(size/2,hy,hx,starty+(size/2),startx+(size/2));
     
}
int main(void)
{
    int y,x;
    //int sz;
    int i,j;
    
    while(cin >> n >> y >> x)
    {
        memset(out,'#',sizeof(out));
        out[x][y]  ='*';
        gx = x;
        gy = y;
        sz1 = pow(2.0,n);
        //cout <<sz<<endl;
        recur(sz1,y,x,1,1);
        
        for(i = 1;i<=sz1;i++)
        {
              for(j = 1;j<=sz1;j++)
              {
                    cout  << out[i][j];
              }
              cout << endl;
        }
        cout << endl;      
    }
}
