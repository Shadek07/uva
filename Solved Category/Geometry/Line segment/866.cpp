#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<set>

using namespace std;

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int n;
int cut[1005][4];
int cnt[8];
typedef pair<int,int> point;
typedef pair<double,double> poin;
set<poin> st[1005];

typedef pair<point,point> segment;

bool on_segment(point pi,point pj,point pk)
{
     int mnf,mxf,mns,mxs;
     mnf = min(pi.first,pj.first);
     mxf = max(pi.first,pj.first);
     mns = min(pi.second,pj.second);
     mxs = max(pi.second,pj.second);
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
    int t;
    int i,j,k;
    int a,b;
    bool ch = false;
    bool  c;
    double x,y;
    cin >> t;
    point p1,p2,p3,p4;
    int total;
    double a1,b1,c1,a2,b2,c2;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n;i++)
        {
              cin >> cut[i][0] >> cut[i][1]>> cut[i][2]>> cut[i][3];
        }
        
        memset(cnt,0,sizeof(cnt));
        
        for(i = 0; i < n;i++)
        {
              p1 = point(cut[i][0],cut[i][1]);
              p2 = point(cut[i][2],cut[i][3]);
              for(j = 0; j < n;j++)
              {
                    if(i != j)
                    {
                        p3 =  point(cut[j][0],cut[j][1]);
                        p4 = point(cut[j][2],cut[j][3]);
                        c = segment_intersect(p1,p2, p3, p4);
                        if(c == true)
                        {
                             a1 = p1.second-p2.second;
                             b1 = -(p1.first-p2.first);
                             c1 = p1.second*(p1.first-p2.first)-p1.first*(p1.second-p2.second);
                             a2 = p3.second-p4.second;
                             b2 = -(p3.first-p4.first);
                             c2 = p3.second*(p3.first-p4.first)-p3.first*(p3.second-p4.second);
                             x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
                             y = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
                             poin p5 = poin(x,y);
                             st[i].insert(p5);
                        }
                        
                    }
              }
        }
        
        int ans = 0;
        if(ch == false)
        ch = true;
        else
        cout << endl;
        for(i = 0; i < n;i++)
        {
              ans += st[i].size()+1;
              st[i].clear();
        }
        cout << ans << endl;
             
    }
    
    return 0;
}
