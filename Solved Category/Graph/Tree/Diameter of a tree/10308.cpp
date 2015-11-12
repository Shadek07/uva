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
#define max(a,b) a>b?a:b
vector<int> adj[10001];
int cost[10001][10001];

 
 int diameter = 0;
     
    int DFS(int x, int px)  
    {
        int h1 = 0, h2 = 0; 
		int y;
		int len = adj[x].size();
        for (y=0; y<len; ++y)
		{
            if (adj[x][y] != px)
            {
                int h = DFS(adj[x][y], x) + cost[x][adj[x][y]];
                if (h > h1) 
				{
					h2 = h1;
					h1 = h;
				}
                else if (h > h2) h2 = h;
            }
		}

        diameter = max(diameter, h1 + h2);
        return h1;
    }
     
    void tree_diameter()
    {
        diameter = 0;   
     
        int root = 1;

        DFS(root, root);
        cout  << diameter<<endl;
    }
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	char in[1000];
	int len,i,j,k,a,b,c;
	bool last=false;
	int mx;
	while(gets(in))
	{
		len = strlen(in);
		mx = 0;
		if(len == 0)
		{
			cout << 0 << endl;
			gets(in);
			continue;
		}
		sscanf(in,"%d %d %d",&a,&b,&c);
		adj[a].push_back(b);
		adj[b].push_back(a);
		cost[a][b] = cost[b][a] = c;
		mx = max(mx,a);
		mx = max(mx,b);
		bool c1 = true;
		while(gets(in))
		{
			len = strlen(in);
			if(len==0)
			{
				c1 = false;
				break;
			}
			sscanf(in,"%d %d %d",&a,&b,&c);
			adj[a].push_back(b);
			adj[b].push_back(a);
			cost[a][b] = cost[b][a] = c;
			mx = max(mx,a);
			mx = max(mx,b);

		}
		tree_diameter();
		for(i = 1;i<=mx;i++)
		{
			adj[i].clear();
		}
		mx = 0;

		if(c1==true)
			break;

	}
	
     return 0;
}   

