
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

//#define pi acos(-1.0)
int N,m1;
struct Point 
{
       double x, y;
       
} P[1000+1],CH[1000+1];
typedef pair<double,double> pa;

map<pa,int> mp;

double cross(const Point &o,const Point &a,const Point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare_position(const Point &a, const Point &b)
{
    return (a.x > b.x) || (a.x == b.x && a.y < b.y);
}
double dist(Point a,Point b)
{
	return sqrt(pow(a.x-b.x,2.) + pow(a.y-b.y,2.));
}

bool compare_angle(const Point& a, const Point& b)
{
    double temp;
    temp = cross(P[0],a,b);
	if(fabs(temp-0.0)< 1e-6)//when coolinear
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
        while (m >= 2 && cross(CH[m-2], CH[m-1], P[i]) < 0) 
        m--;
        CH[m++] = P[i];
    }
 
    m--;
    m1 = m;
}

int main(void)
{
	char name[100];
	char name1[100];
	int i,k,j;
	int a,b;
	char c;
	Point p1;
	int s;
	int ind=1;
	c = getchar();
	gets(name);
	if(c == 'E')
      return 0;
	strcpy(name,name+1);
	s = 0;
		while(1)
		{
			c = getchar();
			if(c == 'S')
			{
				strcpy(name1,name);
				gets(name);
				strcpy(name,name+1);
				cout << name1 << " " << "convex hull:\n";
				// using default comparison:
				//it = unique (vec.begin(), vec.end());                                                
			    
				N = s;
				
				Graham_scan();
				k = m1;
				if(CH[m1].y == CH[m1-1].y)
				{
					int a,b;
					a = CH[m1-1].x;
					b = CH[m1].x;
					k = j = m1;
					for(i = N-1;i>=0;i--)
					{
						if(P[i].y == CH[j].y && P[i].x > a && P[i].x < b)
						{
							CH[k] = P[i];
							k++;
						}
					}
				}
				for(i = 0;i<k;i++)
				{
					cout << " (" << CH[i].x << "," << CH[i].y << ")";
				}
				cout << endl;
				ind=1;
				s = 0;
				mp.clear();
			}
			else if(c == 'P')
			{
				cin >> k;
				
				for(i = 0;i<k;i++)
				{
					cin >> a >> b; 
					pa p3;
					p3.first = a;
					p3.second = b;
					if(!mp[p3])
					{
						p1.x = a;
						p1.y = b;
						P[s++] = p1;
						mp[p3] = ind++;
					}
				}
			}
			else if(c == 'E')
			{
				cout << name << " " << "convex hull:\n";
				 
				N = s;
				
				
				Graham_scan();
				k = m1;
				if(CH[m1].y == CH[m1-1].y)
				{
					int a,b;
					a = CH[m1-1].x;
					b = CH[m1].x;
					k = j = m1;
					for(i = N-1;i>=0;i--)
					{
						if(P[i].y == CH[j].y && P[i].x > a && P[i].x < b)
						{
							CH[k] = P[i];
							k++;
						}

					}
				}
				for(i = 0;i<k;i++)
				{
					cout << " (" << CH[i].x << "," << CH[i].y << ")";
				}
				cout << endl;
				s = 0;
				ind=1;
				mp.clear();
				break;
			}
		}

   return 0;
}
