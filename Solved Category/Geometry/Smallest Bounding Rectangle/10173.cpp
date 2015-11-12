
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
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define eps 1e-9
#define PI 2*acos(0)

struct point
{
	double x,y;

}P[1001],CH[1001];
int n,n1;

bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y  
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool eq(double x,double y) {   return fabs( x - y ) < eps;} //x==y

double dist(point a, point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); 
}

double cross_product(point o, point a, point b)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

bool compare_position(point a, point b)
{
	return xy(a.y,b.y)||(eq(a.y,b.y) && xy(a.x,b.x));
}

bool compare_angle(point a, point b)
{
	double temp = cross_product(P[0],a,b);
	if(eq(temp,0))
	{
		return xy(dist(a,P[0]),dist(b,P[0]));
	}
	else
		return dy(temp,0);  //temp>0
}

double perpdist(double slope,int i,int j)
{
	double c1,c2,deno;
	c1 = -slope*CH[i].x+CH[i].y;
	c2 = -slope*CH[j].x+CH[j].y;
	deno=sqrt(pow(slope,2)+pow(1.0,2));
	return fabs(c1-c2)/deno;
}

double angle(int i)
{
	double x1,y1,x2,y2,costheta;
	int j;
	if(i == 0)
		j = n-1;
	else
		j = i-1;

	x1 = CH[i].x - CH[j].x;
	y1 = CH[i].y - CH[j].y;

	x2 = CH[(i+1)%n].x - CH[i].x;
	y2 = CH[(i+1)%n].y - CH[i].y;
	costheta = (x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
	double x = acos(costheta);
	x *= 180;
	x /= PI;
	//cout << i << ": " << x << endl;
	return x;

}

void Graham_scan()
{
	swap(P[0],*min_element(P,P+n,compare_position));
	sort(P+1,P+n,compare_angle);
	P[n] = P[0];
	int m=0,i;
	for(i = 0;i<=n;i++)
	{
		while(m>=2 && xyd(cross_product(CH[m-2],CH[m-1],P[i]),0))
			m--;
		CH[m++] = P[i];
	}
	m--;
	n = m;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,m;
	double alpha,beta,gama,delta;
	double ar;
	double d1,d2,slope;
	//cout << acos(0.0) << endl;
	while(cin >> n && n)
	{
		for(i = 0;i<n;i++)
			cin >> P[i].x >> P[i].y;
		Graham_scan();
		//cout << n << endl;
		if(n<3)
		{
			printf("%.4f\n",0.0);
		}
		else
		{
			alpha = 0.0;
			beta = angle(1);
			//cout << beta << endl;
			j = k = m = 1;
			gama = delta = beta;
			for(i = 0;i<n;i++)
			{
				if(i>0)
					alpha += angle(i);
				while(xy(beta,alpha+90))
				{
					j = (j+1)%n;
					beta += angle(j);
				}
				while(xy(gama,alpha+180))
				{
					k = (k+1)%n;
					gama += angle(k);
				}
				while(xy(delta,alpha+270))
				{
					m = (m+1)%n;
					delta += angle(m);
				}
				int i1 = (i+1)%n;
				if(eq(CH[i1].x,CH[i].x))
				{
					d1 = fabs(CH[k].x-CH[i].x);
					d2 = fabs(CH[m].y-CH[j].y);
				}
				else if(eq(CH[i1].y,CH[i].y))
				{
					d1 = fabs(CH[k].y-CH[i].y);
					d2 = fabs(CH[m].x-CH[j].x);
				}
				else
				{
					slope = (CH[i1].y-CH[i].y)/(CH[i1].x-CH[i].x);
					d1 = perpdist(slope,i,k);
					d2 = perpdist(-1.0/slope,j,m);
				}
				double tmp = d1*d2;
				if(i==0 || tmp < ar)
					ar = tmp;

			}

			printf("%.4f\n",ar);
		}
	}
    
	return 0;
}