#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>

using namespace std;

vector<int> edge[1000];
vector<int> adj[1000];
const int infinity = 1000000001;

//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge

//int pre[105];
//int next[105];
int cost[1000][1000];
bool ch[1000][1000];
int n,edg;
int d[1000];
int cnt[1000];
bool vis[1000];
struct data 
{
    int city, dist;
	int pred;
    bool operator < ( const data& p ) const
	{
        return dist > p.dist;
    }
};

void dijkstra(int source)
{
   
    int i;
    for( i=0; i<n; i++)
		d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
	u.pred = -1;
	//pre[source] = -1;
    q.push(u);
    d[source] = 0;

    while(!q.empty()) 
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
						//pre[v.city] = u.city;
						//next[u.city] = v.city;
						q.push(v);
					}
				}
        }
    }
	
}

/*void make_dag()
{
	int a;
	int i;
	for(a=0;a<n;a++)
	{
		if(a!=1)
		{
			int mn=infinity;
			int sz=edge[a].size();
			for(i=0;i<sz;i++)
			{
				if(cost[a][edge[a][i]] + d[edge[a][i]]<mn)
					mn = cost[a][edge[a][i]] + d[edge[a][i]];
			}
			for(i=0;i<sz;i++)
			{
				if(cost[a][edge[a][i]] + d[edge[a][i]] == mn)
				{
					adj[a].push_back(edge[a][i]);
				}
			}

		}
	}
}*/

int dag(int a)
{
	int mn=infinity;
	int i;
	int ans=0;
	if(a==1)
		return 1;
	if(cnt[a]>=0)
		return cnt[a];
	
	
	for(i=0;i<n;i++)
	{
		if(ch[i][a] && cost[i][a]<infinity && d[i]<d[a])
			ans += dag(i);
	}
	cnt[a] = ans;
	return ans;
}

int main(void)
{
	
	int i,j,k,ct;

	while(cin >> n && n)
	{
		cin >> edg;
		memset(ch,false,sizeof(ch));
		for(i = 0; i < edg; i++)
		{
			cin >> j >> k >> ct;
			edge[j-1].push_back(k-1);
			edge[k-1].push_back(j-1);
			cost[j-1][k-1] = ct;
			cost[k-1][j-1] = ct;
			ch[j-1][k-1] = true;
			ch[k-1][j-1] = true;

		}

		dijkstra(1);
		memset(cnt,-1,sizeof(cnt));
		memset(vis,false,sizeof(vis));
		//make_dag();
		i = dag(0);
		cout << i << endl;
		for(i = 0; i < n;i++)
		{
			edge[i].clear();
			//adj[i].clear();
		}


	}

	return 0;
}