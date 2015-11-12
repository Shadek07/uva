#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int n;
int straws[13][4];

bool conn[14][14];

typedef pair<int,int> point;

typedef pair<point,point> segment;

bool on_segment(point pi,point pj,point pk)
{
     int mnf,mxf,mns,mxs;
     mnf = min(pi.first,pj.first);
     mxf = max(pi.first,pj.first);
     mns = min(pi.second,pj.second);
     mxs = max(pi.second,pj.second); 
     //cout << mns << "- " << mxs << endl;
     if(mnf <= pk.first && pk.first <= mxf && mns <= pk.second && pk.second <= mxs)
     return true;
     else
     return false;
     
}

int cross_product(point a,point b,point c)
{
        double * AB = new double[2];
        double * AC = new double[2];
        
        AB[0] = b.first-a.first;
        AB[1] = b.second-a.second;
        AC[0] = c.first-a.first;
        AC[1] = c.second-a.second;
        double cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(cross < 0.0)
        return -1;
        else if(cross > 0.0)
        return 1;
        else
        return 0;
}

bool segment_intersect(point p1,point p2,point p3,point p4)
{
     int d1,d2,d3,d4;
     
     d1 = cross_product(p3,p4,p1);
     d2 = cross_product(p3,p4,p2);
     d3 = cross_product(p1,p2,p3);
     d4 = cross_product(p1,p2,p4);
     
     if(((d1 > 0 && d2 < 0)||(d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0)||(d3 < 0 && d4 > 0)))
     return true;
     else if( d1 == 0 && on_segment(p3,p4,p1))
     return true; 
     else if( d2 == 0 && on_segment(p3,p4,p2))
     return true;
     else if( d3 == 0 && on_segment(p1,p2,p3))
     return true;
     else if( d4 == 0 && on_segment(p1,p2,p4))
     return true;
     else
     return false;
     
}

int main(void)
{
    int i,j,k,t;
    int a,b;
    cin >> t;
    bool ch = false;
    while(t--)
    {
         cin >> n;
         
         for(i =0;i < n;i++)
         {
               cin >> straws[i][0] >> straws[i][1] >> straws[i][2]>> straws[i][3];
         }
         
         memset(conn,false,sizeof(conn));
         
         for(i = 0; i < n;i++)
         conn[i][i] = true;
         point p1,p2,p3,p4;
         
         for( i= 0; i < n-1;i++)
         {
             for(j = i+1; j <n;j++)
             {
                  p1 = point(straws[i][0],straws[i][1]);
                  p2 = point(straws[i][2],straws[i][3]);
                  p3 = point(straws[j][0],straws[j][1]);
                  p4 = point(straws[j][2],straws[j][3]);
                  conn[i][j] |= segment_intersect(p1,p2,p3,p4);
                  conn[j][i] |= conn[i][j];
             } 
         }
         
         if(ch == false)
         ch = true;
         else
         cout << endl;
         
         for(k = 0; k < n;k++)
         {
               for(i = 0; i < n;i++)
               {
                     for(j = 0; j<n;j++)
                     {                           
                           conn[i][j] |= conn[i][k] && conn[k][j];                           
                     }
               }
         }
         
         //cout << conn[0][3] << " " << conn[3][4] << " " << conn[2][4] << " " << conn[0][4]<< endl;
         while(cin >> a >> b)
         {
                   if(!a && !b)
                   break;
                   //cout << conn[a-1][b-1] << endl;
                   if(conn[a-1][b-1])
                   cout << "CONNECTED\n";
                   else
                   cout << "NOT CONNECTED\n";
         }
    }
    
    return 0;
}
