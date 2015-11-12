#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define min(a,b) ((a)>(b))?(b):(a)
#define max(a,b) ((a)>(b))?(a):(b)
struct pnt
{
	int x;
	int y;
}pt[4];
typedef pair<double,double> point;

typedef pair<point,point> segment;

bool on_segment(point pi,point pj,point pk)
{
	 int a,b,c,d;
	 a = min(pi.first,pj.first);
	 b = max(pi.first,pj.first);
	 c = min(pi.second,pj.second);
	 d = max(pi.second,pj.second);
     if((a <= pk.first) && (pk.first <= b) && ( c<= pk.second) && (pk.second <= d))
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
bool comp(pnt p,pnt q)
{
	if(p.x < q.x)
		return true;
	else if(p.x == q.x && p.y < q.y)
		return true;
	else
		return false;
}
int main(void)
{
	int t,i,j;
	cin >> t;
	int xstart,ystart,xend,yend;
	struct pnt p1;
	point a,b,c,d,e,f;
	segment given_line;
	bool ans;
	//freopen("2.txt","w",stdout);
	while(t--)
	{
		cin >> xstart>>ystart>>xend>>yend>>pt[0].x>>pt[0].y>>pt[1].x>> pt[1].y;
		pt[2].x = pt[1].x;
		pt[2].y = pt[0].y;
		pt[3].x = pt[0].x;
		pt[3].y = pt[1].y;

		sort(pt,pt+4,comp);

		p1 = pt[1];
		pt[1] = pt[2];
		pt[2] = p1;

		p1 = pt[3];
		pt[3] = pt[2];
		pt[2] = p1;

		e = point(xstart,ystart);
        f = point(xend,yend);

		a = point(pt[0].x,pt[0].y);
        b = point(pt[1].x,pt[1].y);
        c = point(pt[2].x,pt[2].y);
        d = point(pt[3].x,pt[3].y);

	    ans = false;
        ans |=   segment_intersect(e,f,a,b);
        ans |=   segment_intersect(e,f,b,c);
        ans |=   segment_intersect(e,f,c,d);
        ans |=   segment_intersect(e,f,d,a);
		ans |=   xstart>= pt[0].x && xstart<=pt[1].x && ystart>= pt[0].y && ystart<=pt[3].y && xend>= pt[0].x && xend<=pt[1].x && yend>= pt[0].y && yend<=pt[3].y;
        ans == true?cout << "T\n":cout << "F\n";

		//for(i = 0;i<4;i++)
		//{
			//cout << pt[i].x << " " << pt[i].y << endl;
		//}
	}
	return 0;
}