
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
#include <bitset>
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); } 
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

int grid[101][101];
int target_i,target_j;
int cost[101][101];
int vis[101][101];
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
  return a.get_value() < b.get_value();  //bigger value first
}

int main(void)
{
	int t,n,m,i,j,r,c,val,k;
	int inf = 1 << 30;
	priority_queue<cell> pq;
	int ca=1;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				cin >> grid[i][j];
				cost[i][j] = -inf;
			}
		}

		//push the source cell

		cell cl;
		cl.insert_value(grid[0][0]);
		cl.insert_row(0);
		cl.insert_col(0);
		pq.push(cl);

		int mx=-1;

		while(!pq.empty())
		{
			r = pq.top().get_row();
			c = pq.top().get_col();
			val = pq.top().get_value();
			pq.pop();

			if(val > mx)
				mx = val;

			for(i = 1;i<=k;i++)
			{
				if(r+i < n)
				{
					cell c1;
					c1.insert_row(r+i);
					c1.insert_col(c);
					if(grid[r][c] < grid[r+i][c] && val + grid[r+i][c] > cost[r+i][c])
					{
						c1.insert_value(val+grid[r+i][c]);
						cost[r+i][c] = val + grid[r+i][c];
						pq.push(c1);
					}

				}
				if(r-i >= 0)
				{
					cell c1;
					c1.insert_row(r-i);
					c1.insert_col(c);
					if(grid[r][c] < grid[r-i][c] && val+grid[r-i][c] > cost[r-i][c])
					{
						c1.insert_value(val+grid[r-i][c]);
						cost[r-i][c] = val+grid[r-i][c];
						pq.push(c1);
					}

				}

				if(c+i < n)
				{
					cell c1;
					c1.insert_row(r);
					c1.insert_col(c+i);
					if(grid[r][c] < grid[r][c+i] && val+grid[r][c+i] > cost[r][c+i])
					{
						c1.insert_value(val+grid[r][c+i]);
						cost[r][c+i] = val+grid[r][c+i];
						pq.push(c1);
					}

				}

				if(c-i >= 0)
				{
					cell c1;
					c1.insert_row(r);
					c1.insert_col(c-i);
					if(grid[r][c] < grid[r][c-i] && val+grid[r][c-i] > cost[r][c-i])
					{
						c1.insert_value(val+grid[r][c-i]);
						cost[r][c-i] = val+grid[r][c-i];
						pq.push(c1);
					}

				}
			}
		}

		while(!pq.empty())
		{
			pq.pop();
		}

		if(ca==1)
			ca=2;
		else
			cout << endl;
		cout << mx << endl;

	}
	return 0;
}