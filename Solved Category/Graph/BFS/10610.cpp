
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
#define eps 1e-8

vector<int> adj[1009];

double cor[1009][2];
double v,m;
bool visit[1009];
int n;
struct state
{
	int a;
	int step;
	int prev;
};

queue<state> pq;

bool check(int i,int j)
{
	double t;
	double d;
	d = (cor[i][0]-cor[j][0])*(cor[i][0]-cor[j][0]) + (cor[i][1]-cor[j][1])*(cor[i][1]-cor[j][1]);
	d = sqrt(d);
	t = d/v;
	if(m<t-eps)//not possible
		return true;
	else
		return false;

}
int main(void)
{
	int i,j,a,b;
	char in[1001];
	int len;
	string s;
	bool found;
	while(cin >> v >> m)
	{
		if(v == 0.0 && m == 0.0)
			break;
		i = 0;
		m *= 60.0;
		getchar();
		while(gets(in))
		{
			len = strlen(in);
			if(len == 0)
				break;
			s = in;
			istringstream is(s);
			is >> cor[i][0];
			is >> cor[i][1];
			i++;
		}

		n = i;
		for(i =0;i<n;i++)
		{
			for(j = i+1;j<n;j++)
			{
				if( !check(i,j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		found = false;
		struct state s1,s2;
		s1.a = 0;
		s1.step = 0;
		s1.prev = 0;
		pq.push(s1);
		memset(visit,false,sizeof(visit));
		visit[0] = true;
		while(!pq.empty())
		{
			s1 = pq.front();
			pq.pop();
			if(s1.a == 1)
			{
				found = true;
				b = s1.step;
			}
			a = s1.a;
			len = adj[a].size();
			for(i = 0;i<len;i++)
			{
				if(visit[adj[a][i]] == false)
				{
					s2.a = adj[a][i];
					s2.prev = a;
					s2.step = s1.step+1;
					visit[adj[a][i]] = true;
					pq.push(s2);
				}
			}

		}

		if(found==true)
		{
			cout << "Yes, visiting " << b-1 << " other holes.\n";
		}
		else
			cout << "No.\n";

		for(i = 0;i<n;i++)
			adj[i].clear();
		while(!pq.empty())
			pq.pop();
	}
    return 0;
}