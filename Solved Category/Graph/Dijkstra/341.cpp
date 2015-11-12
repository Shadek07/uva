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
void dijkstra(int source, int destination)
{
   
    int d[20005],i,j;
    for( i=0; i<=total; i++) 
		d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
	u.pred = -1;
	pre[source] = -1;
    q.push(u);
    d[source] = 0;
	vector<int> pa;
    while(!q.empty()) 
	{
        u = q.top(); 
		q.pop();
        int ucost = d[ u.city ];
		if(u.city == destination)
		{
			i = u.city;
			while(pre[i] != -1)
			{
				pa.push_back(i);
				i = pre[i];
			}
			pa.push_back(i);
			j = pa.size();
			for(i = j-1;i>=0;i--)
			{
				cout << " " << pa[i];
			}
			cout << "; " << d[destination] << " second delay\n";
			break;
		}

        for( i=0; i<edge[u.city].size(); i++)
		{
			
			v.city = edge[u.city][i], v.dist = cost[u.city][v.city] + ucost;
			if( d[v.city] > v.dist ) 
			{
				d[v.city] = v.dist;
				pre[v.city] = u.city;
				q.push(v);
			}			
        }
    } 
    
}

int n,edg;


int main(void)
{

	
	int i,j,k,ct;
	int fir,sec;
	int S,T,t;
	int ca = 1;	

	while(cin >> n && n)
	{	
		for(j = 1;j<=n;j++)
		{
			cin >> edg;
			for(i = 0; i < edg; i++)
			{
				cin >> k >> ct;
				edge[j].push_back(k);
				cost[j][k] = ct;
			}
		}

		cin  >>  S >> T;
		jail = 0;

		total = n;

		cout << "Case " << ca++ << ": Path ="; 

		dijkstra(S,T);		

		for(i = 0; i <= n;i++)
		{
			if(!edge[i].empty())
				edge[i].clear();
		}

	}

	return 0;
}

