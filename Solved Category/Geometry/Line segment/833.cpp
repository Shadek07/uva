
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

int n,m;
bool sp[500];

struct point
{
	int x,y;
};

struct segment
{
	point a,b;

}seg[500];

int area(int i, point k)   //three index of vertex structure
{
        int AB[2];
        int AC[2];
        AB[0] = seg[i].b.x-seg[i].a.x;
        AB[1] = seg[i].b.y-seg[i].a.y;
        AC[0] = k.x-seg[i].a.x;
        AC[1] = k.y-seg[i].a.y;
        int cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(cross < 0)
        return -1;
        else if(cross == 0)
        return 0;
        else
        return 1;       
}

void determine_slope()
{
	double sl;
	int i;
	for(i = 0;i<n;i++)
	{
		sl = (seg[i].a.y-seg[i].b.y)*1.0;
		sl /= (seg[i].a.x-seg[i].b.x)*1.0;
		if(sl > 0)
			sp[i] = true; //positive slope
		else
			sp[i] = false;

	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,k;
	cin >> t;
	int ca=1;
	point f;
	double slope;
	point pi,pj;
	while(t--)
	{
		cin >> n;
		for(i = 0;i<n;i++)
		{
			cin >> seg[i].a.x >> seg[i].a.y >> seg[i].b.x >> seg[i].b.y;
			//swap a line segment's point according to x coordinate
			if(seg[i].a.x > seg[i].b.x)
			{
				pi = seg[i].a;
				seg[i].a = seg[i].b;
				seg[i].b = pi;
			}
		}

		determine_slope();

		cin >> m;
		if(ca==1)
			ca=0;
		else
			cout << endl;
		for(i = 0;i<m;i++)
		{
			cin >> f.x >> f.y;
			pi.x = f.x;
			pi.y = f.y;
			int my;
			double y1;
			int ind;
			while(true)//until fall in x axis
			{
				my = -1;
				ind = -1;
				for(j = 0;j<n;j++)
				{
					if(area(j,pi)>0) //anticlockwise
					{
						y1 = seg[j].a.x*(seg[j].a.y-seg[j].b.y) + seg[j].a.y*(-seg[j].a.x+seg[j].b.x)-pi.x*(seg[j].a.y-seg[j].b.y);
						y1 /= (-seg[j].a.x+seg[j].b.x);
						if(pi.x >= seg[j].a.x && pi.x <= seg[j].b.x && y1 > my && y1 < pi.y)
						{
							my = y1;
							ind = j;
						}
					}
				}
				if(ind != -1)
				{
					if(sp[ind] == true)
					{
						pi.x = seg[ind].a.x;
						pi.y = seg[ind].a.y;
					}
					else
					{
						pi.x = seg[ind].b.x;
						pi.y = seg[ind].b.y;

					}
				}
				else
					break;
			}

			cout << pi.x << endl;


		}

	}
     return 0;
}
