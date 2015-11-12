#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cstdio>

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

struct data {
    int city, dist;
	int pred;
    bool operator < ( const data& p ) const {
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
        u = q.top(); 
		q.pop();
        int ucost = d[ u.city ];
		if(u.city == destination)
			break;

        for( i=0; i<edge[u.city].size(); i++)
		{
			//if(check[u.city][edge[u.city][i]])
			//{
				v.city = edge[u.city][i], v.dist = cost[u.city][v.city] + ucost;
				// relaxing :)
				if( d[v.city] > v.dist ) 
				{
					d[v.city] = v.dist;
					pre[v.city] = u.city;
				//	next[u.city] = v.city;
					//check[u.city][v.city] = true;
					q.push( v );
				}
			//}
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
	int S,T,t;
	int ca = 1;

	cin >> t;


	while(t--)
	{
		cin >> n >> edg >> S >> T;

		//memset(check,false,sizeof(check));
	

		for(i = 0; i < edg; i++)
		{
			cin >> j >> k >> ct;
			edge[j].push_back(k);
			edge[k].push_back(j);
			cost[j][k] = ct;
			cost[k][j] = ct;
			//check[j-1][k-1] = true;
			//check[k-1][j-1] = true;

		}

		jail = 0;

		total = n;

		fir = dijkstra(S,T);

		if(jail == 1)
		{
			cout << "Case #" << ca++ << ": ";
			cout << "unreachable\n";
			
		}
		else
		{
			cout << "Case #" << ca++ << ": ";
			cout << fir << endl;
			
		}

		for(i = 0; i <= n;i++)
		{
			if(!edge[i].empty())
				edge[i].clear();
		}


	}

	return 0;
}