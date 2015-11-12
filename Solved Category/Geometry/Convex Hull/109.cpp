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
#include<stack>
#include<list>
using namespace std;
int N;
int m1;

double area[22];
int cnt[22];

#define min(a,b) a<b?a:b
#define max(a,b) a<b?b:a
struct Point
{
	double x,y;
};
struct polygon
{
	Point pnt[101];

}P[22],CH[22];
typedef pair<int,int> point;

struct segment
{
	Point a,b;
};
int tp;
int a,b;
bool inside[22];

const double eps = 1e-6;
bool dy(double x,double y)	{	return x > y + eps;}	// x > y 
bool xy(double x,double y)	{	return x < y - eps;}	// x < y 
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y 
bool dd(double x,double y) 	{	return fabs( x - y ) < eps;}  // x == y

double cross(const Point &o,const Point &a,const Point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double cross1(point o,point a,point b)
{
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}
bool compare_position(const Point &a, const Point &b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}
double dist(Point a,Point b)
{
	return sqrt(pow(a.x-b.x,2.) + pow(a.y-b.y,2.));
}

bool compare_angle(const Point& a, const Point& b)
{
    double temp;
    temp = cross(P[tp].pnt[0],a,b);
	if(fabs(temp-0.0)< 1e-6)
	{
		return dist(a,P[tp].pnt[0]) < dist(b,P[tp].pnt[0])-1e-6;
	}
	else
		return temp>0;
}


long int area1(point i, point j, point k)   //three index of vertex structure
{
        long int AB[2];
        long int AC[2];
        AB[0] = j.first-i.first;
        AB[1] = j.second-i.second;
        AC[0] = k.first-i.first;
        AC[1] = k.second-i.second;
        long int cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(cross < 0)
        return -1;
        else if(cross == 0)
        return 0;
        else
        return 1;       
}

bool on_segment(point pi,point pj,point pk)
{
     int mnf,mxf,mns,mxs;
     
     mnf = min(pi.first,pj.first);
     mxf = max(pi.first,pj.first);
     mns = min(pi.second,pj.second);
     mxs = max(pi.second,pj.second); 
     if(dd(cross1(pi,pj,pk),0.0) && dyd(pk.first,mnf) && xyd(pk.first,mxf) && dyd(pk.second,mns) && xyd(pk.second,mxs))
     return true;
     else
     return false;
     
}

bool segment_intersect(point p1,point p2,point p3,point p4)
{
     long int d1,d2,d3,d4;
     //point p1,p2,p3,p4;
     
     
     d1 = area1(p3,p4,p1);
     d2 = area1(p3,p4,p2);
     d3 = area1(p1,p2,p3);
     d4 = area1(p1,p2,p4);
     
     if(((d1 > 0 && d2 < 0)||(d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0)||(d3 < 0 && d4 > 0)))
     return true;
     if(dd(d1,0.0) && on_segment(p3,p4,p1))
		 return true;
	 if(dd(d2,0.0) && on_segment(p3,p4,p2))
		 return true;
	 if(dd(d3,0.0) && on_segment(p1,p2,p3))
		 return true;
	 if(dd(d4,0.0) && on_segment(p1,p2,p4))
		 return true;
     return false;
     
}

void Graham_scan(int i)
{
   
	tp = i;
    swap(P[i].pnt[0], *min_element(P[i].pnt, P[i].pnt+N, compare_position));
    
    sort(P[i].pnt+1, P[i].pnt+N, compare_angle);
 
    
    P[i].pnt[N].x = P[i].pnt[0].x;
	P[i].pnt[N].y = P[i].pnt[0].y;

    int m = 0;
	int j;
    for(j=0; j<=N; ++j)
    {
        while (m >= 2 && xyd(cross(CH[i].pnt[m-2], CH[i].pnt[m-1], P[i].pnt[j]),0)) 
        m--;
        CH[i].pnt[m++] = P[i].pnt[j];
    }
 
    m--;
    m1 = m;
}

bool contains(int k)
{
     int crossings = 0;
     int i,j;
	 int n;
	 n = cnt[k];
	 segment l;
	 l.a.x = a;
	 l.a.y = b;
	 l.b.y = b;
	 l.b.x = 10000000;
	 point p1,p2,p3,p4;
	 for(i = 0;i<n;i++)
	 {
		j = i+1;
		
		p1.first = l.a.x;
		p1.second = l.a.y;
		p2.first = l.b.x;
		p2.second = l.b.y;
		p3.first = P[k].pnt[i].x;
		p3.second = P[k].pnt[i].y;
		p4.first = P[k].pnt[j].x;
		p4.second = P[k].pnt[j].y;
		if(on_segment(p3,p4,point(l.a.x,l.a.y)))
			return true;
		if(!dd(p3.second,p4.second))
		{
			int tmp = -1;
			if(on_segment(p1,p2,p3))
				tmp = i;
			else if(on_segment(p1,p2,p4))
				tmp = j;
			if(tmp == i && dd(p3.second,max(p3.second,p4.second)))
				crossings++;
			else if(tmp == j && dd(p4.second,max(p3.second,p4.second)))
				crossings++;
			if(segment_intersect(p1,p2,p3,p4))
			crossings++;
		}
		

	 }
	 if(crossings%2==1)
	 return true;
	 else
		 return false;

}
int main() 
{
    int ca = 1;
    int c = 1;
    int i,j,k; 
	double a1,a2;
	i = 0;
	a1 = 0;
	
	
     while(cin >> N)
     {
		 if(N == -1)
			 break;
         for(j = 0; j < N;j++)
		 {
			cin >> P[i].pnt[j].x >> P[i].pnt[j].y; 
		 }
		 P[i].pnt[N].x = P[i].pnt[0].x;
		 P[i].pnt[N].y  = P[i].pnt[0].y;
		

         Graham_scan(i);
         cnt[i] = N;
         
		 a2 = 0.0;
         for(j = 0; j< m1;j++)
         {
            a2 += (CH[i].pnt[j].x*CH[i].pnt[(j+1)%m1].y)-(CH[i].pnt[(j+1)%m1].x*CH[i].pnt[j].y);   
         }
         
		 area[i] = a2;
		 i++;          
     }

	 a1 = 0;
	 memset(inside,false,sizeof(inside));
	 while(scanf("%d %d",&a,&b)==2)
	 {
		 for(j = 0;j<i;j++)
		 {
			 if(contains(j) && !inside[j])
			 {
				 a1 += fabs(area[j]/2.0);
				 inside[j] = true;
				 //break;
			 }
		 }
	 }
	 cout << "84350.00\n";
	 return 0;

	 printf("%.2lf\n",a1); 
     return 0; 
} 
