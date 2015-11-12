
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

typedef pair<int,int> point;
typedef pair<point,point> segment;
int n;

struct stick
{
	point p1;
	point p2;

}st[1001];

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
        int AB[2];
        int AC[2];
        
        AB[0] = b.first-a.first;
        AB[1] = b.second-a.second;
        AC[0] = c.first-a.first;
        AC[1] = c.second-a.second;
        int cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(cross < 0)
        return -1;
        else if(cross > 0)
        return 1;
        else
        return 0;
}

bool segment_intersect(point p1,point p2,point p3,point p4)
{
     int d1,d2,d3,d4;
     
     d1 = cross_product(p3,p4,p1);
	 if( d1 == 0 && on_segment(p3,p4,p1))
     return true;
	 
     d2 = cross_product(p3,p4,p2);
	 if( d2 == 0 && on_segment(p3,p4,p2))
     return true;

	 if((d1>0 && d2>0)||(d1<0 && d2<0))
		 return false;
	 

     d3 = cross_product(p1,p2,p3);
	 if( d3 == 0 && on_segment(p1,p2,p3))
     return true;

     d4 = cross_product(p1,p2,p4);
	 if( d4 == 0 && on_segment(p1,p2,p4))
     return true;

	 if((d3>0 && d4>0)||(d3<0 && d4<0))
		 return false;
     
     if(((d1 > 0 && d2 < 0)||(d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0)||(d3 < 0 && d4 > 0)))
     return true;

     /*else if( d1 == 0 && on_segment(p3,p4,p1))
     return true; 
     else if( d2 == 0 && on_segment(p3,p4,p2))
     return true;
     else if( d3 == 0 && on_segment(p1,p2,p3))
     return true;
     else if( d4 == 0 && on_segment(p1,p2,p4))
     return true;
     else*/

     return false;    
}

int main(void)
{
	int i,j,k;
	bool ch;
	int cnt;
	bool inter[1001];
	while(scanf("%d",&n)==1 && n)
	{
		for(i = 0;i<n;i++)
		{
			scanf("%d %d %d %d", &st[i].p1.first ,&st[i].p1.second ,&st[i].p2.first ,&st[i].p2.second);
		}

		cnt = 0;
		memset(inter,false,sizeof(inter));
		for(i = 0;i<n;i++)
		{
						
			for(j = i+1;j<n;j++)
			{
				if(segment_intersect(st[i].p1,st[i].p2,st[j].p1,st[j].p2))
				{
					cnt++;
					inter[i] = inter[j] = true;
				}
			}
			
		}
		for(i = 0;i<n;i++)
			if(inter[i] == false)
				cnt += 2;
		cout << cnt << endl;
	}

    return 0;
}
