
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

struct vertex
{
	int up,down,cnt;
	int ind;
}v[501][6];
vector<pii> adj[501][6];
pii par[501][6];
int n;
char out[6][10]={"front","back","left","right","top","bottom"};
bool take_input()
{
	cin >> n;
	if(n==0)
		return false;
	int a,b,c,d,e,f,i;
	for(i=0;i<n;i++)
	{
		cin >> a >> b >> c >> d >> e >> f;
		v[i][0].up = a;
		v[i][0].down = b;
		v[i][0].ind = 0;

		v[i][1].up = b;
		v[i][1].down = a;
		v[i][1].ind = 1;

		v[i][2].up = c;
		v[i][2].down = d;
		v[i][2].ind = 2;

		v[i][3].up = d;
		v[i][3].down = c;
		v[i][3].ind = 3;

		v[i][4].up = e;
		v[i][4].down = f;
		v[i][4].ind = 4;

		v[i][5].up = f;
		v[i][5].down = e;
		v[i][5].ind = 5;
	}

	return true;

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,k1,sz,ind;
	pii p1,p2;
	int mx;
	int ca=1;
	while(take_input())
	{
		for(i=n-1;i>0;i--)
		{
			for(j = i-1;j>=0;j--)
			{
				for(k=0;k<6;k++)
				{
					for(k1=0;k1<6;k1++)
					{
						if(v[i][k].up == v[j][k1].down)
						{
							p1.first = j;
							p1.second = k1;
							adj[i][k].push_back(p1);
						}
					}
				}

			}

		}

		v[0][0].cnt = 0;
		v[0][1].cnt = 0;
		v[0][2].cnt = 0;
		v[0][3].cnt = 0;
		v[0][4].cnt = 0;
		v[0][5].cnt = 0;

		for(i = 1;i<n;i++)
		{
			for(k=0;k<6;k++)
			{
				sz = adj[i][k].size();
				mx=-1;
				for(j=0;j<sz;j++)
				{
					p1 = adj[i][k][j];
					if(v[p1.first][p1.second].cnt>mx)
					{
						mx = v[p1.first][p1.second].cnt;
						ind = j;
					}
					//mx = max(mx,v[p1.first][p1.second].cnt
				}
				if(mx != -1)
				{
					v[i][k].cnt = mx+1;
					par[i][k] = adj[i][k][ind];
				}
				else
					v[i][k].cnt = 0;

			}
		}

		mx = -1;

		for(i=0;i<n;i++)
		{
			for(k=0;k<6;k++)
			{
				if(v[i][k].cnt>mx)
				{
					p1.first = i;
					p1.second = k;
					mx = v[i][k].cnt;
				}
			}
		}
		vector< pair<int,string> > ans1;
		typedef pair<int,string> ps;
		ps ps1;
		while(v[p1.first][p1.second].cnt != 0)
		{
			ps1.first = p1.first;
			ps1.second = out[v[p1.first][p1.second].ind];
			ans1.push_back(ps1);
			i = par[p1.first][p1.second].first;
			j = par[p1.first][p1.second].second;
			p1.first = i;
			p1.second = j;
		}
		ps1.first = p1.first;
		ps1.second = out[v[p1.first][p1.second].ind];
		ans1.push_back(ps1);
		if(ca>1)
			cout << endl;
		cout << "Case #" << ca++ << endl;
		cout << (sz=ans1.size()) << endl;
		for(i=sz-1;i>=0;i--)
		{
			cout << ans1[i].first+1 << " " << ans1[i].second << endl;
		}
		for(i=0;i<n;i++)
		{
			for(k=0;k<6;k++)
				adj[i][k].clear();
		}
		
	}
    return 0;
}