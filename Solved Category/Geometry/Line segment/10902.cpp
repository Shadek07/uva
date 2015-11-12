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

using namespace std;


typedef pair<double,double> point;

typedef pair<point,point> segment;
struct stick
{
	int num;
	segment seg;
};

vector<stick> tops;
vector<stick>::iterator it;

#define min(a,b) a<b?a:b
#define max(a,b) a<b?b:a



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

int n;

int main(void)
{
   segment s,s1;
   point p1,p2,p3,p4;
   int i,j,k;
   double a,b,c,d;
   struct stick st,nt;
	while(cin >> n && n)
	{
		    tops.clear();
        for(i = 0;i < n;i++)
		    {
           cin >> a >> b >> c >> d;
    		   p1 = point(a,b);
    		   p2 = point(c,d);
    		   s1 = segment(p1,p2);
    		   for(it = tops.begin(),j=0; it != tops.end();it++,j++)
    		   {
                 st = *it;
        			   s = st.seg;
        			   if(segment_intersect(p1,p2,s.first,s.second))
        			   {
                          tops.erase(tops.begin()+j);
                          j--;
                          it--;
        			   }
    		   }
           nt.num = i+1;
    		   nt.seg = s1;
    		   tops.push_back(nt);
		    }
		    
		    cout << "Top sticks: " << tops[0].num;
		    int len = tops.size();
		    for(j = 1; j < len;j++)
		    {
              cout << ", " << tops[j].num;
        }
        cout << ".\n";
        tops.clear();		    

	}

}
