#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>

using namespace std;

vector<int> edge[100];
const int infinity = 1000000000;

//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge

int pre[105];
int next[105];
bool check[105][105];
int jail;
int cost[105][105];

struct data 
{
    int city, dist;
	int pred;
    bool operator < ( const data& p ) const
	{
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination)
{
   
    int d[100],i;
    for( i=0; i<=destination; i++)
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

        for( i=0; i<edge[u.city].size(); i++)
		{
				v.city = edge[u.city][i];
				if(cost[u.city][v.city] != infinity)
				{
					v.dist = cost[u.city][v.city] + ucost;
					
					if(d[v.city] > v.dist ) 
					{
						d[v.city] = v.dist;
						pre[v.city] = u.city;
						next[u.city] = v.city;
						q.push(v);
					}
				}
        }
    }

	if(d[destination] == infinity)
		jail = 1;
   
    return d[destination];
}

int n,edg;



int main(void)
{
	
	int i,j,k,ct;
	int fir,sec;


	while(cin >> n && n)
	{
		cin >> edg;
        jail = 0;
		memset(check,false,sizeof(check));

		for(i = 0; i < edg; i++)
		{
			cin >> j >> k >> ct;
			edge[j-1].push_back(k-1);
			edge[k-1].push_back(j-1);
			cost[j-1][k-1] = ct;
			cost[k-1][j-1] = ct;
			check[j-1][k-1] = true;
			check[k-1][j-1] = true;

		}

        long int cost1,cost2;
		cost1 = dijkstra(0,n-1);
		if(jail != 1)
		{
			ct = n-1;
			while(pre[ct] != -1)
			{
                cost[pre[ct]][ct] = infinity;
				cost[ct][pre[ct]] = -cost[ct][pre[ct]];
				ct = pre[ct];
			}

			cost2 = dijkstra(0,n-1);
			if(jail)
				cout << "Back to jail\n";
			else
				cout << cost1 + cost2 << endl;

		}
		else
		{
			cout << "Back to jail\n";
		}

		for(i = 0; i <= n;i++)
		{
			if(!edge[i].empty())
				edge[i].clear();
		}


	}

	return 0;
}