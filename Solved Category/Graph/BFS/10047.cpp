
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

char in[30][30];

int col[5] = {0,1,2,3,4};
int dx,dy;
struct state
{
	int x;
	int y;
	int sec;
	int color;//0 for Green,1 for black,2 for red,3 for blue,4 for white
	int dir;//0 for N,1 for W,2 for S, 3 for E
	//int prevx,prevy;
};
queue<state> pq;

int main(void)
{
	int m,n;
	int ca=1;
	int i,j,k,a,b;
	struct state p,q;
	bool vis[30][30][4][5]; //vis[x][y][dir][color]
	while(cin >> m >> n)
	{
		if(!m && !n)
			break;
		getchar();
		for(i = 0;i<m;i++)
			gets(in[i]);
		if(ca != 1)
			cout << endl;
		cout << "Case #" << ca++ << endl;
		memset(vis,false,sizeof(vis));
		for(i = 0;i<m;i++)
		{
			for(j = 0;j<n;j++)
			{
				if(in[i][j] == 'S')
				{
					p.x = i;
					p.y = j;
					p.sec = 0;
					p.color = 0;
					p.dir = 0;
					pq.push(p);
				}
				if(in[i][j] == 'T')
				{
					dx = i;
					dy = j;
				}
			}
		}

		bool ch = false;
		int ans;
		int cnt=0;
		while(!pq.empty())
		{
			p = pq.front();
			pq.pop();
			if(p.x == dx && p.y == dy && p.color == 0)
			{
				ch = true;
				ans = p.sec;
				break;
			}
			
			if(vis[p.x][p.y][p.dir][p.color] || in[p.x][p.y] == '#')
				continue;
			vis[p.x][p.y][p.dir][p.color] = true;
			if(p.dir == 0)
			{
				if(p.x - 1 >= 0)
				{
					q.x = p.x - 1;
					q.y = p.y;
					q.dir = p.dir;
					q.color = (p.color+1)%5;
					q.sec = p.sec+1;
					pq.push(q);
				}
				
    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 1;
    				q.color = p.color;
    				q.sec = p.sec+1;

    				pq.push(q);
                
				
				
    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 3;
    				q.color = p.color;
    				q.sec = p.sec+1;

    				pq.push(q);
			}
			else if(p.dir == 1)
			{
				if(p.y - 1 >= 0)
				{
					q.x = p.x;
					q.y = p.y-1;
					q.dir = p.dir;
					q.color = (p.color+1)%5;
					q.sec = p.sec+1;
					pq.push(q);
				}

    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 0;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);

					q.x = p.x;
    				q.y = p.y;
    				q.dir = 2;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);
			}
			else if(p.dir == 2)
			{
				if(p.x + 1 < m)
				{
					q.x = p.x + 1;
					q.y = p.y;
					q.dir = p.dir;
					q.color = (p.color+1)%5;
					q.sec = p.sec+1;
					pq.push(q);
				}


    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 1;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);
				

    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 3;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);
			}
			else if(p.dir == 3)
			{
				if(p.y + 1 < n)
				{
					q.x = p.x;
					q.y = p.y+1;
					q.dir = p.dir;
					q.color = (p.color+1)%5;
					q.sec = p.sec+1;
					pq.push(q);
				}
    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 0;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);
				
    				q.x = p.x;
    				q.y = p.y;
    				q.dir = 2;
    				q.color = p.color;
    				q.sec = p.sec+1;
    				pq.push(q);
			}

		}

		if(ch == false)
		{
			cout << "destination not reachable\n";
		}
		else
		{
			cout << "minimum time = " << ans << " sec\n";
		}
		while(!pq.empty())
			pq.pop();


	}

	return 0;
}
