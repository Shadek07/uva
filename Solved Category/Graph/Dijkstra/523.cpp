
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
vector<int> edge[20005];

const int infinity = 1000000000;

//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge

int pre[20005];
//int next[20005];
//bool check[20005][20005];
int jail;
int cost[20005][20005];
int thro[20005];

struct data {
    int city, dist;
	int pred;
    bool operator < ( const data& p ) const 
	{
        return dist > p.dist;
    }
};
int total;
int dijkstra(int source, int destination)
{
   
    int d[20005],i;
    for( i=0; i<=total; i++) 
		d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
	u.pred = -1;
	pre[source] = -1;
    q.push(u);
    d[source] = 0;

    while( !q.empty() ) 
	{
        u = q.top(); q.pop();
        int ucost = d[u.city];
		if(u.city == destination)
		{
			while(!q.empty())
				q.pop();
			break;
		}

        for( i=0; i<edge[u.city].size(); i++)
		{			
				v.city = edge[u.city][i];
				if(v.city == u.city)
					continue;
				v.dist = cost[u.city][v.city] + ucost + thro[u.city];
				if( d[v.city] > v.dist ) 
				{
					d[v.city] = v.dist;
					pre[v.city] = u.city;
					q.push(v);
				}
        }
    }

	if(d[destination] == infinity)
		jail = 1;
   
    return d[destination];
}

int n,edg;
int get,sr,ds;

void path(int n)
{
	if(pre[n] != -1)
	{
		path(pre[n]);
		cout << "-->" << n;		
	}
	else
	{
		cout << n;
	}		
}


int main(void)
{

	
	int i,j,k;
	int fir;
	int S,T,t;
	int ca = 1;
	char in[20005];
	int cnt;
	char *p;
	int ch = 0;
	string s1;

	cin >> t;

	getchar();
	getchar();


	while(t--)
	{
		cnt = 0;
		gets(in);
		i =0;

		p = strtok(in," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");

		while( p != NULL)
		{
			
			int a11 = atoi(p);

			if(a11 != -1)
			{

				cost[1][i+1] = a11;
				edge[1].push_back(i+1);
			}

			i++;				
			p = strtok(NULL," !\"#$%&\'()*+,./:;<=>?@[\\]^_`{|}~");
		}

		for(j = 1; j < i; j++)
		{
			for(k = 0; k < i;k++)
			{
				int a12;
				cin >> a12;
				if(a12 != -1)
				{
					cost[j+1][k+1] = a12;
					edge[j+1].push_back(k+1);
				}
			}
		}

		for(j = 1; j <= i; j++)
		{
			cin >> thro[j];
		}

		getchar();

		while(gets(in))
		{             
				if(strlen(in) == 0)
					break;

				sscanf(in,"%d %d",&S,&T);
				//cin >> S >> T;
				if( S == T)
				{
					if(ch == 0)
					ch = 1;
					else
						cout << endl;

					cout << "From " << S << " to " << T << " :\n";
					cout << "Path: " << S << endl;
					cout << "Total cost : " << 0 << endl;
					continue;
				}

				jail = 0;
				total = i;

				if(ch == 0)
					ch = 1;
				else
					cout << endl;

				cout << "From " << S << " to " << T << " :\n";

				fir = dijkstra(S,T);

				get = fir;
				sr = S;
				ds = T;
				cout << "Path: ";

				path(T);

				cout << endl;

				get -= thro[sr];
				
				cout << "Total cost : " << get << endl;					
				
		}

		//if(t >0)
			//getchar();

		for(j = 1; j<= i;j++)
		{
			if(!edge[j].empty())
				edge[j].clear();
		}

	}

	return 0;
}