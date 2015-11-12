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
#define max1(a,b) a>b?a:b
#define min1(a,b) a>b?b:a


vector<int> adj[101];
vector<double> cost[101];
vector<double> tmp[101];
vector<int> path;
set<double> st;
set<double>::iterator it;
int n,m;
double ans1,ans2;
int pre[10001];
double ans;
struct data {
     double dist;
	 int city;
	int pred;
    bool operator < ( const data& p ) const 
	{
        return dist > p.dist;
    }
};

void go(int i)
{
	if(pre[i] == -1)
	{
		path.push_back(i);
		return;
	}
	else
	{
		path.push_back(i);
		//if(tmp[i][pre[i]]> ans2)
			//ans2 = tmp[i][pre[i]];
		go(pre[i]);
	}
}
int dijkstra(int source, int destination,double temp)
{
   
    double d[10001];
	int i,j;
    for( i=1; i<=n; i++) 
	{
		d[i] = 9999999.0;
	}

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
	u.pred = -1;
	pre[source] = -1;
    q.push(u);
    d[source] = 0;

    while(!q.empty()) 
	{
        u = q.top(); 
		q.pop();
        double ucost = d[u.city];
		if(u.city == destination)
			break;

		int len = adj[u.city].size();
        for( i=0; i<len; i++)
		{			
			v.city = adj[u.city][i];
			if(tmp[u.city][i] <= temp)
			{
				v.dist = cost[u.city][i] + ucost;
				
				if( d[v.city] > v.dist ) 
				{
					d[v.city] = v.dist;
					pre[v.city] = u.city;
					q.push(v);
				}
			}
        }
    }
	ans = d[destination];
    return d[destination];
}

int main(void)
{
	
	int s,d,i,j,k;
	int a,b;
	double r,c;
	
	while(cin >> n >> m)
	{
		cin >> s >> d;
		

		int ind=0;
		
		for(i = 1;i<=m;i++)
		{
			cin >> a >> b >> r >> c;
			st.insert(r);
			adj[a].push_back(b);
			adj[b].push_back(a);
			cost[a].push_back(c);
			cost[b].push_back(c);
			tmp[a].push_back(r);
			tmp[b].push_back(r);
		}

	    for(it = st.begin();it != st.end();it++)
		{
			ans1 = dijkstra(s,d,*it);
			if(ans1 != 9999999.0)
			{
				ans2 = *it;
				break;
			}

		}

		
		path.clear();
		go(d);
		reverse(path.begin(),path.end());
		cout << path[0];
		k = path.size();
		for(j = 1;j<k;j++)
		{
			cout << " " << path[j];
		}
		cout << endl;
		printf("%.1lf %.1lf\n",ans,ans2);
		for(i = 1;i<= n;i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
			if(!cost[i].empty())
				cost[i].clear();
			if(!tmp[i].empty())
				tmp[i].clear();
		}

	}
	return 0;
}