
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
#include <bitset>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

#define eps 1e-9
struct pnt
{
	double x;
	double y;
};

struct pnt tri[3];
bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y  
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool eq1(double x,double y) {   return fabs( x - y ) < eps;} //x==y

int area(pnt p, pnt q, pnt r)
{
	double pq[2], pr[2];
	pq[0] = q.x-p.x;
	pq[1] = q.y-p.y;
	pr[0] = r.x-p.x;
	pr[1] = r.y-p.y;
	double val;
	val = pq[0]*pr[1] - pq[1]*pr[0];
	if(dy(val,0)) //val>0
		return 1;
	else if(xy(val,0)) //val<0
		return -1;
	else
		return 0;
}

bool inside_triangle(pnt p)
{
	bool pos = false;
	bool neg = false;
	int i,a;
    a = area(tri[0], tri[1], p);
	if(a==1)
		pos = true;
	if(a==-1)
		neg = true;

	a = area(tri[1], tri[2], p);
	if(a==1)
		pos = true;
	if(a==-1)
		neg = true;
	a = area(tri[2], tri[0], p);
	if(a==1)
		pos = true;
	if(a==-1)
		neg = true;

	if(pos && !neg)
		return true;
	if(!pos && neg)
		return true;
	//if(!pos && !neg)
	//return true;

	double a1,b1,c1;
	double x1,y1,x2,y2;
	double mnx,mxx,mny,mxy;
	for(i = 0;i<3;i++)
	{
		x1=tri[i].x;
		y1=tri[i].y;
		x2=tri[(i+1)%3].x;
		y2=tri[(i+1)%3].y;
		a1 = (y1-y2);
		b1=x2-x1;
		c1=-x1*(y1-y2)-y1*(x2-x1);
		double t1 = a1*p.x+b1*p.y+c1;
		mnx=min(x1,x2);
		mxx=max(x1,x2);
		mny=min(y1,y2);
		mxy=max(y1,y2);

		if(eq1(t1,0) && dyd(p.x,mnx) && xyd(p.x,mxx)&& dyd(p.y,mny) && xyd(p.y,mxy))
			return true;

	}

	return false;

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,a,b;
	struct pnt p,q;
	while(cin >> tri[0].x >> tri[0].y >>tri[1].x >> tri[1].y >> tri[2].x >> tri[2].y )
	{
		if(tri[0].x==0&& tri[0].y ==0&&tri[1].x==0&& tri[1].y==0&& tri[2].x==0&& tri[2].y==0)
			break;

		int cnt = 0;
		double mx,my;
		mx = max(tri[0].x,tri[1].x);
		mx = max(mx,tri[2].x);
		my = max(tri[0].y,tri[1].y);
		my = max(my,tri[2].y);
		//a=mx+5;
		//b=my+5;
		//a = min(a,99);
		//b = min(a,99);
		for(i = 1;i<=99;i++)
		{
			for(j = 1;j<=99;j++)
			{
				p.x = i;
				p.y = j;
				if(inside_triangle(p))
					cnt++;
			}
		}

		printf("%4d\n",cnt);
	}
     return 0;
}