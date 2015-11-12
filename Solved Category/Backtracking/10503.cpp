
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
#define max(a,b) ((a>a?a:b))
#define min(a,b) ((a>b?b:a))

int n,m;
bool taken[15];
int value[15][2];
int a,b,c,d;
bool found;

void solve(int last_size,int cnt)
{
	if(found)
		return;
	int i;
	if(cnt == n && last_size == c)
	{
		found = true;
		return;
	}

	for(i= 0;i<m && !found && cnt<n;i++)
	{
		if(taken[i] == false && (value[i][0] == last_size||value[i][1]==last_size))
		{
			taken[i] = true;

			if(value[i][0] == last_size)
			{
				solve(value[i][1],cnt+1);
			}
			else
				solve(value[i][0],cnt+1);
			taken[i] = false;
		}
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	while(cin >> n && n)
	{
		scanf("%d",&m);
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for(i = 0;i<m;i++)
		{
			scanf("%d %d",&value[i][0],&value[i][1]);
		}

		if(m<n)
		{
			cout << "NO\n";
			continue;
		}

		found = false;
		memset(taken,false,sizeof(taken));
		solve(b,0);
		if(found)
			cout << "YES\n";
		else
			cout << "NO\n";


	}
     return 0;
}