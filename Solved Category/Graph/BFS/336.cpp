#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

bool conn[500][500];

map<int,int> mp;
int level[500];
queue<int> q;
vector<int> v[500];
int main(void)
{
	int pair,a,b,c,d,total,cnt,size;
	int index,i,j,k;
	int ca = 1;
	while(1)
	{
		cin >> pair;
		if(pair == 0)
			break;
		index = 1;

		memset(conn,false,sizeof(conn));

		for(i = 0; i < pair; i++)
		{
			cin >> a >> b;

			if(!mp[a])
			{
				mp[a] = index++;
			}

			if(!mp[b])
			{
				mp[b] = index++;
			}
		

			c = mp[a];
			d = mp[b];
			conn[c][d] = true;
			conn[d][c] = true;
			v[c].push_back(d);
			v[d].push_back(c);

		}

		total = mp.size();

		while(1)
		{
			cin >> a >> b;

			if(!a && !b)
				break;

			memset(level,-1,sizeof(level));
			cout << "Case " << ca++ << ": ";
			/*if(b == 0)
			{
				cout << total << " nodes not reachable from node " << a << " with TTL = " << 0 << "." << endl;
				continue;
			}*/
			c = mp[a];
			q.push(c);
			cnt = 1;
			level[c] = 0;
			while(!q.empty())
			{
				c  = q.front();
				q.pop();

				int l;
				l = level[c];

				size = v[c].size();

				for(i = 0; i < size; i++)
				{
					d = v[c][i];
					
					if(conn[c][d] && level[d] == -1)
					{
						
							
							level[d] = level[c] + 1;
							
							q.push(d);
						
					}
					

				   
				}

			}

			cnt = 0;

			for(i = 1; i < index;i++)
			{
				if(level[i] == -1 || level[i] > b)
					cnt++;
			}

			cout  <<cnt << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;
			
		}

		mp.clear();
		for(i = 0; i < 500; i++)
		{
			if(!v[i].empty())
				v[i].clear();
		}

	}

	return 0;
}