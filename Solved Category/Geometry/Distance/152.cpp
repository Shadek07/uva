#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct tree
{
       int x;
       int y;
       int z;
       
}P[5009];

int dist[10];

double distance(int i,int j)
{
       return sqrt(pow(P[i].x - P[j].x, 2.0) + pow(P[i].y - P[j].y, 2.0) + pow(P[i].z - P[j].z, 2.0));
}

bool comp(tree a, tree b)
{
     if(a.x < b.x)
     return true;
     else if(a.x == b.x)
     {
          if(a.y < b.y)
          return true;
          else if(a.y == b.y)
          {
              if(a.z < b.z)
              return true;
              else if(a.z == b.z)
              {
                   return true;
              }
              else
              return false;
          }
          else
          return false;
          
     }
     else
     return false;
}

int main(void)
{
    int a,b,c,i,j;
    i = 0;
    int t;
    double d1,d2;
    int a1,b1;
    while(cin >> a >> b >> c)
    {
              if(!a && !b && !c)
              break;
              P[i].x = a;
              P[i].y = b;
              P[i].z = c;
              i++;
    }
    
    t = i;
    sort(P,P+i,comp);
    
    memset(dist,0,sizeof(dist));
    
    for(i = 0; i < t;i++)
    {
        j = i-1;
        d1 = 999999.9;
        while(j >= 0 && P[i].x < P[j].x+10)
        {
                
              d2 =   sqrt(pow(P[i].x - P[j].x, 2.0) + pow(P[i].y - P[j].y, 2.0) + pow(P[i].z - P[j].z, 2.0));

              if(d2 < 10.0)
              {
                    if(d2 < d1)
                    d1 = d2;
              }
              
              
              j--;  
        }
        
        j = i+1;
        
        while(j < t && P[i].x > P[j].x-10)
        {
              
                
              d2 =  sqrt(pow(P[i].x - P[j].x, 2.0) + pow(P[i].y - P[j].y, 2.0) + pow(P[i].z - P[j].z, 2.0));
              if(d2 < 10.0)
              {
                    if(d2 < d1)
                    d1 = d2;
                    
              }
              
              j++;  
        }
        
        a1 =floor(d1);
        if(a1 < 10)
        dist[a1]++;
    }
    
    for(i = 0; i < 10;i++)
    {
          printf("%4d",dist[i]);
    }
    
    cout << endl;
    //getchar();
    //getchar();
    return 0;
}
