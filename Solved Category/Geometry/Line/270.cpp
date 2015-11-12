
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

typedef pair<int,int> point;
vector<point> points;
vector<point> next;
point ref;
bool first_comp(point p,point q)
{
	if(p.first<q.first)
		return true;
	else if(p.first == q.first && p.second < q.second)
		return true;
	else
		return false;
}

double cross( point &o,point &a,point &b)
{
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

double dist(point a,point b)
{
	return sqrt(pow(a.first-b.first,2.) + pow(a.second-b.second,2.));
}

bool comp(point p,point q)
{
	double temp;
    temp = cross(ref,p,q);
	if(fabs(temp-0.0)< 1e-6)
	{
		return dist(p,ref) < dist(q,ref)-1e-6;
	}
	else
		return temp>0;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	point p1,p2;
	int t,i,j,k,a,b;
	char in[100];
	int len;
	cin >> t;
	getchar();
	getchar();
	int mx;
	int ch = 0;
	while(t--)
	{
		while(gets(in))
		{
			len = strlen(in);
			if(len==0)
				break;
			sscanf(in,"%d %d",&a,&b);
			p1.first = a;
			p1.second = b;
			points.push_back(p1);
		}

		mx = 2;
		sort(points.begin(),points.end(),first_comp);
		len = points.size();
		for(i = 0;i<len-1;i++)
		{
			for(j = i;j<len;j++)
				next.push_back(points[j]);
			ref = next[0];

			sort(next.begin(),next.end(),comp);
			k = next.size();
			point prev = next[1];
			a = 2;
			for(j = 2;j<k;j++)
			{
				if(ref.first == prev.first) //parallel to y axis
				{
					if(next[j].first == ref.first)
						a++;
					else
					{
						prev = next[j];
						if(a>mx)
							mx = a;
						a = 2;
					}
				}
				else if(ref.second == prev.second) //parallel to x axis
				{
					if(next[j].second == ref.second)
						a++;
					else
					{
						prev = next[j];
						if(a>mx)
							mx = a;
						a = 2;
					}
				}
				else
				{
					double m1,m2;
					m1 = (prev.second-ref.second)*1.0/(prev.first-ref.first);
					m2 = (next[j].second-prev.second)*1.0/(next[j].first-prev.first);
					if(fabs(m1-m2)<1e-6)  //same slope
					{
						a++;
					}
					else
					{
						prev = next[j];
						if(a>mx)
							mx = a;
						a = 2;

					}
				}

				prev = next[j];

			}
			if(a>mx)
				mx = a;
			next.clear();
		}

		if(ch==0)
			ch = 1;
		else
			cout << endl;
		cout << mx << endl;
		points.clear();



	}

     return 0;
}

