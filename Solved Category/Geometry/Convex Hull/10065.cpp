#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int m1;
struct Point 
{
   double x, y;
   
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

int main() 
{
    int ca = 1;
    int c = 1;
    int i,j,k; 
	double a1,a2;
     while(cin >> N && N)
     {
         for(i = 0; i < N;i++)
         cin >> P[i].x >> P[i].y; 
		 P[N].x = P[0].x;
		 P[N].y  = P[0].y;
		 a1 = 0.0;
		 for(i = 0;i<N;i++)
		 {
			 a1 += (P[i].x*P[(i+1)%N].y)-(P[(i+1)%N].x*P[i].y);
		 }
         
         Graham_scan();
         
         cout << "Tile #" << ca++ << "\n";
		 a2 = 0.0;
         for(i = 0; i< m1;i++)
         {
            a2 += (CH[i].x*CH[(i+1)%m1].y)-(CH[(i+1)%m1].x*CH[i].y);   
         }
         
		 a1 = fabs(a1)/2.0;
		 a2 = fabs(a2)/2.0;
         double perc = (a2-a1)/a2;
		 perc *= 100.0;
         
         printf("Wasted Space = %.2lf",perc);
		 cout << " %\n\n";
            
     }
     return 0; 
} 
