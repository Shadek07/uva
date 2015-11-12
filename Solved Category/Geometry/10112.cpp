
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

struct point
{
	int x,y;
}pnt[16];
int n;
struct point tri[3];

int find_area(point p,point q, point r)
{
	int pq[2],pr[2];
	pq[0] = q.x-p.x;
	pq[1] = q.y-p.y;
	pr[0] = r.x-p.x;
	pr[1] = r.y-p.y;

	return abs(pq[0]*pr[1]*1.0-pq[1]*pr[0]*1.0);
}

int signed_area(point p,point q, point r)
{
	int pq[2],pr[2];
	pq[0] = q.x-p.x;
	pq[1] = q.y-p.y;
	pr[0] = r.x-p.x;
	pr[1] = r.y-p.y;

	int x =  pq[0]*pr[1]*1.0-pq[1]*pr[0]*1.0;
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else return 0;
}

bool inside_triangle(point p)
{
	bool pos = false;
	bool neg = false;
	int a;
    a = signed_area(tri[0], tri[1], p);
	if(a==1)
		pos = true;
	else if(a==-1)
		neg = true;
	//else return true;   //do not need to consider zero area

	a = signed_area(tri[1], tri[2], p);
	if(a==1)
		pos = true;
	else if(a==-1)
		neg = true;
	//else return true;

	a = signed_area(tri[2], tri[0], p);
	if(a==1)
		pos = true;
	else if(a==-1)
		neg = true;
	//else return true;

	if(pos && !neg)
		return true;
	if(!pos && neg)
		return true;
	return false;

}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,x;
	char c;
	double area;
	int ind[3];
	while(cin >> n && n)
	{
		getchar();
		for(i = 0;i<n;i++)
		{
			cin >> c >> pnt[i].x >> pnt[i].y;
		}

		area = 0;

		for(i = 0;i<n;i++)
		{
			for(j = i+1;j<n;j++)
			{
				for(k = j+1;k<n;k++)
				{
					int x1 = find_area(pnt[i],pnt[j], pnt[k]);
					if(x1 != 0 && x1>area)
					{
						bool in=false;
						tri[0] = pnt[i];
						tri[1] = pnt[j];
						tri[2] = pnt[k];
						for(x = 0;x<n;x++)
						{
							if(x!=i&&x!=j&&x!=k && inside_triangle(pnt[x]))
							{
								in = true;
								break;
							}
						}
						if(in ==false)
						{
							area = x1;
							ind[0]=i;
							ind[1]=j;
							ind[2]=k;
						}

					}


				}
			}
		}

		cout << char(ind[0]+'A') << char(ind[1]+'A') << char(ind[2]+'A') << endl;
	}
     return 0;
}