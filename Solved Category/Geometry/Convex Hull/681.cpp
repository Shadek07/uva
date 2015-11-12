
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
struct Point 
{
       int x, y;
       
} P[1000+1], CH[1000+1];

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
	int temp;
    temp = cross(P[0],a,b);
	if(temp == 0)
	{
		return dist(a,P[0]) < dist(b,P[0]);
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

int main() 
{
    int ca = 1;
    int c = 1;
    int i,j,k; 
	int t;
	cin >> t;
	cout << t<<endl;
     while(t--)
     {
		 if(c == 1)
         c = 0;
         else
		 {
			cout << -1<<endl;
			cin >> k;
		 }
		 cin >> N;
         for(i = 0; i < N;i++)
         cin >> P[i].x >> P[i].y; 
         
         Graham_scan();
         

		 cout << m1+1 << endl;
         
         for(i = 0; i <=m1;i++)
         {
               printf("%d %d\n",CH[i].x,CH[i].y);
         }
         
         //printf("%.0f %.0f\n",CH[0].x,CH[0].y);
         
     }
     return 0; 
} 
