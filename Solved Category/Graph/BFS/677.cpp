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


struct path
{
	list<int> ls;
	bool ch[11];
	int dist;
	int fr;
};
int n,len;
vector<int> adj[11];
queue<path> pq;
list<int>::iterator it;

void operate()
{
	int i,j,k;
	int a,b=0;
	int ind;
	struct path pa,q;
	cin >> n >> len;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
		{
			cin >> k;
			if(k==1)
				adj[i].push_back(j);
		}
	}

	
	pa.dist = 0;
	pa.ls.push_back(0);
	pa.fr = 0;
	for(i = 0;i<n;i++)
		pa.ch[i] = false;
	pa.ch[0] = true;
	pq.push(pa);
	while(!pq.empty())
	{
		q = pq.front();
		pq.pop();
		if(q.dist == len)
		{
			it = q.ls.begin();
			it++;
			cout << "(1";
			for(;it != q.ls.end();it++)
				cout << "," << (*it) + 1;
			cout << ")\n";
			b=1;
		}
		else
		{
			a = q.fr;
			ind = adj[a].size();
			for(i = 0;i<ind;i++)
			{
				if(q.ch[adj[a][i]]==false)
				{
					pa=q;
					pa.ch[adj[a][i]] = true;
					pa.dist++;
					pa.fr = adj[a][i];
					pa.ls.push_back(adj[a][i]);
					pq.push(pa);
				}
			}
			
		}
	}

	if(b==0)
		cout << "no walk of length "<< len << endl;
	for(i = 0;i<n;i++)
		adj[i].clear();

}

int main(void)
{
	int ch;
	int i,j,k;
	operate();
	while(cin >> i)
	{
		if(i != -9999)
			continue;
		cout << endl;
		operate();
	}

	return 0;
}
