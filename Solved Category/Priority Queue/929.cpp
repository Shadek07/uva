#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int grid[1000][1000];
int target_i,target_j;
int cost[1000][1000];
int vis[1000][1000];
class cell
{
	int row;
	int col;
	int value;
public:
	cell()
	{
		value = -5;
	}
	void insert_value(int p)
	{
		value = p;
	}
	void insert_row(int r)
	{
		row = r;
	}
	void insert_col(int c)
	{
		col = c;
	}
	int get_value() const
	{
		return value;
	}
	int get_row() const
	{
		return row;
	}
	int get_col() const
	{
		return col;
	}
};


bool operator<(const cell &a, const cell &b)
{
  return a.get_value() > b.get_value();
}

int main(void)
{
	int t,n,m,i,j,r,c,val;
	int inf = 1 << 30;
	priority_queue<cell> pq;

	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				cin >> grid[i][j];
				cost[i][j] = inf;
				vis[i][j] = 0;

			}
		}
		//push the source cell

		cell cl;
		cl.insert_value(grid[0][0]);
		cl.insert_row(0);
		cl.insert_col(0);
		pq.push(cl);

		target_i = m-1;
		target_j = n-1;

		while(!pq.empty())
		{
			r = pq.top().get_row();
			c = pq.top().get_col();
			val = pq.top().get_value();
			pq.pop();

			if(r == target_i && c == target_j)
			{
				cout << val << endl;
				break;
			}
			else if(!vis[r][c])
			{
				vis[r][c] = 1;
				if(r + 1 < m)
				{
					cell c1;
					c1.insert_row(r+1);
					c1.insert_col(c);
					if(val + grid[r+1][c] < cost[r+1][c])
					{
						c1.insert_value(val+grid[r+1][c]);
						cost[r+1][c] = val + grid[r+1][c];
						pq.push(c1);
					}

				}
				if(r-1 >= 0)
				{
					cell c1;
					c1.insert_row(r-1);
					c1.insert_col(c);
					if(val+grid[r-1][c] < cost[r-1][c])
					{
						c1.insert_value(val+grid[r-1][c]);
						cost[r-1][c] = val+grid[r-1][c];
						pq.push(c1);
					}

				}

				if(c+1 < n)
				{
					cell c1;
					c1.insert_row(r);
					c1.insert_col(c+1);
					if(val+grid[r][c+1] < cost[r][c+1])
					{
						c1.insert_value(val+grid[r][c+1]);
						cost[r][c+1] = val+grid[r][c+1];
						pq.push(c1);
					}

				}

				if(c-1 >= 0)
				{
					cell c1;
					c1.insert_row(r);
					c1.insert_col(c-1);
					if(val+grid[r][c-1] < cost[r][c-1])
					{
						c1.insert_value(val+grid[r][c-1]);
						cost[r][c-1] = val+grid[r][c-1];
						pq.push(c1);
					}

				}
			}

			

		}

		while(!pq.empty())
		{
			pq.pop();
		}

	}
	return 0;
}