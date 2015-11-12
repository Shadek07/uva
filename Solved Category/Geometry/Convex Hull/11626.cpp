
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
#include<sstream>
using namespace std;
#define eps 1e-11
int N;
int m1;
struct Point
{
     long long int x, y;

}P[100000+1], CH[100000+1];

double cross(const Point &o,const Point &a,const Point &b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare_position(const Point &a, const Point &b)//find rightmost bottom point
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
	double zero = 0.0;
    temp = cross(P[0],a,b);
	if(temp == 0.0)
	{
		return dist(a,P[0]) < dist(b,P[0])-eps;
	}
	else
		return zero<temp-eps;
}

void Graham_scan()
{

    swap(P[0], *min_element(P, P+N, compare_position));//find rightmost bottom point

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

int main()
{
    int ca = 1;
    int c = 1;
    int i,j,k;
	int t;
	cin >> t;
	long long int a,b;
	char in[1000];
	char c1;
	istringstream st;
	string s;
	//freopen("2.txt","w",stdout);
     while(t--)
     {
		 cin >> N;
		 getchar();
		 j = 0;
         for(i = 0; i < N;i++)
		 {
			gets(in);
			s = in;
			st.str(s);
			st >> a;
			st >> b;
			st >> c1;
			if(c1 == 'Y')
			{
				P[j].x = a;
				P[j].y = b;
				j++;
			}

		 }

		 N = j;
         Graham_scan();
		 cout << N << endl;
         j = 0;
         a = CH[0].x;
         b = CH[0].y;
         //find leftmost-bottom point for output
         for(i = 1;i<N;i++)
         {
               if(a> CH[i].x || (a == CH[i].x && b > CH[i].y))
               {
                     j = i;
                     a = CH[i].x;
                     b = CH[i].y;
               }
         }
         
         for(i = j; i <N;i++)
         {
			 cout << CH[i].x << " " << CH[i].y << endl;
         }
         for(i = 0;i<j;i++)
         {
               cout << CH[i].x << " " << CH[i].y << endl;
         }
         //printf("%.0f %.0f\n",CH[0].x,CH[0].y);
     }
     return 0;
}
