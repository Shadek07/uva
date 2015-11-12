
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

typedef pair<double,double> pa;
#define eps 1e-8

bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y  
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool eq1(double x,double y) {   return fabs( x - y ) < eps;} //x==y

struct circle
{
	double cx,cy,rad,best,least;

}cir[10001];

int n;
double l,w;

pa find_root(double a,double b,double c)
{
	double x1,x2;
	x1 = -b-sqrt(b*b-4*a*c);
	x1 /= (2*a);

	x2 = -b+sqrt(b*b-4*a*c);
	x2 /= (2*a);

	return make_pair(x1,x2);
}

int cmp(circle c1,circle c2)
{
	if(xy(c1.least,c2.least))
		return 1;
	return 0;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	double dist,r;
	pa p1;
	while(cin >> n >> l >> w)
	{
		w /= 2;
		j=0;
		for(i = 0;i<n;i++)
		{
			cin >> dist >> r;
			if(xyd(r,w))
				continue;
			else
			{
				cir[j].cx = dist;
				cir[j].cy=0;
				cir[j].rad = r;
				p1 = find_root(1,-2*dist,dist*dist-r*r+w*w);
				cir[j].best = p1.second;
				cir[j].least = p1.first;
				j++;
			}
		}

		sort(cir,cir+j,cmp);
		n = j;
		double prev = 0.0;
		int cnt=0;
		for(i = 0;i<n && xy(prev,l);)
		{
			double high = 0.0;
			for(j = i;j<n;j++)
			{
				if(xyd(cir[j].least,prev))
				{
					if(dy(cir[j].best,high))
					high = cir[j].best;
				}
				else
				{
					break;
				}
			}
			if(high == 0.0)
			{
				cnt = -1;
				break;
			}
			else
			{
				cnt++;
				prev = high;
			}
			i = j;

		}

		if(dyd(prev,l))
		cout << cnt << endl;
		else
			cout << -1 << endl;

	}
    
	return 0;
}
