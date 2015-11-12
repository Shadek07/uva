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
#define max(a,b) a>a?a:b

int N;
int m1;
struct Point 
{
       double x, y;
       
} P[1000+1], CH[1000+1],temp[1000+1];

typedef pair<double,double> pa;

map<pa,int> mp;

double cross(const Point &o,const Point &a,const Point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
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
    temp = cross(P[0],a,b);
	if(fabs(temp-0.0)< 1e-6)
	{
		return dist(a,P[0]) < dist(b,P[0])-1e-6;
	}
	else
		return temp>0;
}

void Graham_scan()
{
   
    swap(P[0], *min_element(P, P+N, compare_position));
    
    sort(P+1, P+N, compare_angle);
 
    
    P[N] = P[0];
 
    int m = 0;
    int i;
    for(i=0; i<=N; ++i)
    {
        while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) <= 0) 
        m--;
        CH[m++] = P[i];
    }
 
    m--;
    m1 = m;
}

int second_check()
{
	int i,j;
	int ind=-1;
	for(i = 0;i<N;i++)
	{
		for(j = 0;j<m1;j++)
		{
			if(CH[j].x == temp[i].x && CH[j].y == temp[i].y)
			{
				ind = j;
				i = N;
				return ind;
				break;
			}

		}
	}

	
}

int main() 
{
    int ca = 1;
    int c = 1;
    int i,j,k; 
	int a,b;
	char in[1000];
	char k1,k2;
	string s1;
	i = 0;
	bool last=false;
	Point p1;
	int ind;
	pa p3;
     while(gets(in))
     {
		 sscanf(in,"%d%c%c%d",&a,&k1,&k2,&b);
		 i=0;
		 P[i].x = a;
		 P[i].y = b;
		 temp[i].x = a;
		 temp[i].y = b;
		 i++;
		 p3.first = a;
		 p3.second = b;
		 ind=1;
		 mp[p3] = ind++;
		 last = true;
		 while(gets(in))
		 {
			 if(strlen(in) == 0)
			 {
				 last = false;
				 break;
			 }

			 sscanf(in,"%d%c%c%d",&a,&k1,&k2,&b);			 
			 
			 p3.first = a;
			 p3.second = b;
			 if(!mp[p3])
			 {
				p1.x = a;
				p1.y = b;
				P[i++] = p1;
				temp[i-1] = p1;
				mp[p3] = ind++;
			 }

		 }

		 P[i].x = P[0].x;
		 P[i].y = P[0].y;

		 N = i;
         
		 Graham_scan();
		 if(ca==1)
			 ca=0;
		 else
			 cout << endl;

		 a = second_check();
		 for(i = a;i<=m1;i++)
		 {
			 cout << CH[i].x << ", " << CH[i].y << endl;
		 }
		 for(i = 1;i<=a;i++)
		 {
			cout << CH[i].x << ", " << CH[i].y << endl;
		 }
		  
		 mp.clear();
		 if(last==true)
			 break;
	 }

	 
	 
     return 0; 
} 
