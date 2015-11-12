
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

using namespace std;

#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

int ages[10];
int n;
long int digits;
bool vis[1<<10][101];
struct state
{
	bool digit[10];
	vector<int> v;
	long int digits;
	int sz;
}m[1024];

void init()
{
	int mx = 1<<10;
	int i,j,k,y;

	for(y = 1;y<mx;y++)
	{
		memset(m[y].digit,false,sizeof(m[y].digit));
		int mask = y;
		for(i = 0;i<10;i++)
		{
			if(mask &(1<<i))
				m[y].digit[i] = true;
		}

		long int digits = 0;
		for(i = 9;i>=0;i--)
		{
			if(m[y].digit[i] == true)
			{
				m[y].v.push_back(i);
				digits = digits*10 + i;
			}
		}
		m[y].digits = digits;
		m[y].sz = m[y].v.size();

	}
}
bool check(int mask,int a)
{
	//bool digit[10];
	int i,j,k,x,l;
	

	bool ok = true;
	int b,c;
	int sz = m[mask].sz;
	
		if(a<10 && m[mask].digit[a] == true)
			return true;
		for(i = 0;i<sz ;i++)
		{
			for(j = i+1;j<sz  ;j++)
			{
				b = m[mask].v[i];
				c = m[mask].v[j];
				if((b*10+c == a)||(c*10+b == a) ||(b+c == a))
					return true;
				
				for(k = 0;k<sz ;k++)
				{
					if(k != i && k != j)
					{
						if((b*10+c+m[mask].v[k] == a)||(c*10+b+m[mask].v[k] == a))
							return true;
						for(l = 0;l<sz;l++)
						{
							if(l != i && l != j && l != k)
							{
								int p,q;
								p = m[mask].v[k];
								q = m[mask].v[l];
								if((p*10+q + b*10+c==a)||(p*10+q + c*10+b == a)||(q*10+p + b*10+c==a)||(q*10+p +c*10+b==a))
									return true;
							}
						}
					}
				}
			}
		}
		
	return false;
}

void age_check()
{
	int mx = 1<<10;
	int i,j;
	for(i = 1;i<mx;i++)
	{
		for(j = 1;j<101;j++)
		{
				if(check(i,j))
					vis[i][j] = true;
				else
					vis[i][j] = false;
		}
	}

}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int ca=1;
	int mx = 1<<10;
	//cout << mx << endl;
	long int T;
	init();
	age_check();
	while(scanf("%d",&n) && n != 0)
	{
			for(i = 0;i<n;i++)
				scanf("%d", &ages[i]);

			T = 9876543210;
			for(i = 1;i<mx;i++)
			{
					bool ok = true;
				   for(j = 0;j<n && ok;j++)
				   {
					   if(vis[i][ages[j]] == false)
						   ok = false;

				   }
				  if(ok && m[i].digits < T)
				  {
					  T = m[i].digits;
				  }
			}

			cout << "Case " << ca++ << ": " << T << endl;
	}
    
	return 0;
}