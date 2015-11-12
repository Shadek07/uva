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

using namespace std;

typedef pair<int,int> pa;


int pred[1005];
int ans;
int cost[1005][1005];
bool found;
int dist[1005];
vector<pa> v;
int t,m,n;
void bellman_ford()
{
	
	int i,j,k,a,b,c;
	for(i = 1;i<=n;i++)
	{
		pred[i] = -1;
		dist[i] = 999999;
	}
	pred[n] = -1;
	dist[n] = 0;

	k = v.size();
	pa p;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<k;j++)
		{
			p = v[j];
			a = p.first;
			b = p.second;
			c = cost[a][b];
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
				pred[b] = a;
			}

		}
	}

	for(j = 0;j<k;j++)
	{
		p = v[j];
		a = p.first;
		b = p.second;
		c = cost[a][b];
		if(dist[a]+c < dist[b])
		{
			found = true;
			break;
		}

	}



}
int main(void)
{
	
	int i,j,k,a,b,c;
	cin >> t;
	pa p;
	while(t--)
	{
		cin >> n >> m;
		for(i = 0;i<m;i++)
		{
			cin >> a >> b >> c;
			cost[a][b] = c;
			p.first = a;
			p.second = b;
			v.push_back(p);
		}

		for(i = 0;i<n;i++)
			cost[n][i] = 0;
		found = false;
		bellman_ford();
		if(found)
			cout << "possible\n";
		else
			cout << "not possible\n";
		v.clear();
	}
	return 0;
}

