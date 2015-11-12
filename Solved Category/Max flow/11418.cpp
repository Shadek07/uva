
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


int n;
int capa[55][55];
char words[26][26][101];
vector<int> adj[55];
int s,d;
int par[55];
bool ch[55][55];
bool bfs()
{
	queue<int> pq;
	pq.push(s);
	par[s]=-1;
	int i,j,a,sz;
	bool vis[55];
	memset(vis,false,sizeof(vis));
	vis[s] = true;
	bool found=false;
	while(!pq.empty())
	{
		a = pq.front();
		pq.pop();
		sz = adj[a].size();
		for(i=0;i<sz;i++)
		{
			j = adj[a][i];
			if(vis[j]==false && capa[a][j] > 0)
			{
				vis[j] = true;
				par[j] = a;
				pq.push(j);
				if(j == d)
                {
                    while(!pq.empty())
                    pq.pop();
					found=true;
                    goto nt;

                }
			}
		}

	}

nt:
		i = d;
		int mn = 9999;
		if(found==false)
			return false;
		while(true)
		{
			j = par[i];
			mn = min(mn,capa[j][i]);
			if(par[j]==-1)
				break;
			i = par[i];
		}
		if(mn==9999)
			return false;

		i = d;
		while(true)
		{
			j = par[i];
			capa[j][i] -= mn;
			capa[i][j] += mn;
			if(par[j]==-1)
				break;
			i = par[i];
		}

		return true;
}

void max_flow()
{
	while(bfs())
	{
		
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca=1;
	int t;
	int i,j,k,i1,len;
	cin >> t;
	char in[100];

	while(t--)
	{
		cin >> n;
		memset(ch,false,sizeof(ch));
		for(i = 0;i<n;i++)
		{
			cin >> k;
			for(j = 0;j<k;j++)
			{
				cin >> in;
				in[0] = toupper(in[0]);
				len = strlen(in);
				for(i1=1;i1<len;i1++)
					in[i1] = tolower(in[i1]);
				strcpy(words[i][in[0]-'A'],in);
				capa[in[0]-'A'][26+i]=1;
				//capa[26+i][in[0]-'A']=1;
				adj[in[0]-'A'].push_back(26+i);
				adj[26+i].push_back(in[0]-'A');
				ch[in[0]-'A'][26+i] = true;
				//ch[26+i][in[0]-'A'] = true;

			}
		}
		for(i=0;i<n;i++)
		{
			capa[26+i][26+n+1]=1;
			capa[26+n+1][26+i]=1;
			adj[26+i].push_back(26+n+1);
			adj[26+n+1].push_back(26+i);
		}
		for(i=0;i<n;i++)
		{
			capa[26+n][i]=1;
			capa[i][26+n]=1;
			adj[26+n].push_back(i);
			adj[i].push_back(26+n);
		}
		s = 26+n;
		d = 26+n+1;
		max_flow();
		cout << "Case #" << ca++ << ":\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(ch[i][26+j] && capa[i][26+j]==0)
				{
					cout << words[j][i]<<endl;
				}
			}
			
		}

		for(i=0;i<=26+n+1;i++)
			adj[i].clear();
		memset(capa,0,sizeof(capa));

	}
    return 0;
}