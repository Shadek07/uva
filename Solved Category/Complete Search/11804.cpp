
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


typedef pair<int,int> pa;

struct player
{
	string name;
	int a,b;
}p[10];

int cmp(player p, player q)
{
	if(p.name.compare(q.name) < 0)
		return 1;
	else
		return 0;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t;
	int i,j,k,l,m;
	cin >> t;
	string s;
	int ca=1;
	while(t--)
	{
		for(i = 0;i<10;i++)
		{
			cin >> p[i].name >> p[i].a >> p[i].b;
		}

		sort(p,p+10,cmp);
		string ans,ans1;
		int attack,def,i1;
		attack = def = -1;
		//int a;
		//cout << p[1].b << endl;
		
		int a,b,c,d,e;
		for(i = 0;i<6;i++)
		{
			for(j = i+1;j<7;j++)
			{
				for(k = j+1;k<8;k++)
				{
					for(l = k+1;l<9;l++)
					{
						for(m = l+1;m<10;m++)
						{
							 int tmp=0;
							 for(i1 = 0;i1<10;i1++)
								 if(i1!=i&&i1!=j&&i1!=k&&i1!=l&&i1!=m)
									 tmp += p[i1].b;
							 if(p[i].a+p[j].a+p[k].a+p[l].a+p[m].a>attack)
							 {
								 attack = p[i].a+p[j].a+p[k].a+p[l].a+p[m].a;
								 def = tmp;
								 
								 a = i;
								 b = j;
								 c = k;
								 d = l;
								 e = m;								 
								 
							 }
							 else if((p[i].a+p[j].a+p[k].a+p[l].a+p[m].a) == attack && tmp > def)
							 {
								 attack = p[i].a+p[j].a+p[k].a+p[l].a+p[m].a;
								 def = tmp;
								 a = i;
								 b = j;
								 c = k;
								 d = l;
								 e = m;
								 //cout << attack << " " << def << endl;
								 
								 
							 }
						}
					}
				}
			}
		}

		cout << "Case " <<ca++ << ":" << endl;
		ans = "";
		ans1 = "";
		for(i = 0;i<10;i++)
		{
			if(i==a||i==b||i==c||i==d||i==e)
				ans +=", " + p[i].name;
			else
				ans1 += ", " + p[i].name;
		}
		ans = ans.substr(2,ans.length()-2);
		ans1 = ans1.substr(2,ans1.length()-2);
		ans = "(" + ans + ")";
		ans1 = "(" + ans1 + ")";
		cout << ans << endl << ans1 <<endl;

	}
    
	return 0;
}
