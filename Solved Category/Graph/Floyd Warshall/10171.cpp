
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

#define INF 999999
#define min(a,b) a<b?a:b
int n;
unsigned long int y[30][30];
unsigned long int m[30][30];

vector<int> v;

int main(void)
{
	int i,j,k,a,b;
	char c,c1,x,y1;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin >> n && n)
	{
		getchar();
		for(i = 0;i<26;i++)
		{
			for(j = 0;j<26;j++)
			{
				y[i][j] = INF;
				m[i][j] = INF;
				if(i == j)
				{
					y[i][j] = 0;
					m[i][j] = 0;
				}
			}
		}
		for(i = 0;i<n;i++)
		{
			scanf("%c %c %c %c %d",&c,&c1,&x,&y1,&a);
			getchar();
			if(c == 'Y')
			{
				if(c1 == 'U')
				{
					if(a<y[x-'A'][y1-'A'])
					y[x-'A'][y1-'A'] = a;
				}
				else
				{
					if(a < y[x-'A'][y1-'A'])
					y[x-'A'][y1-'A'] = a;
					if(a<y[y1-'A'][x-'A'])
					y[y1-'A'][x-'A'] = a;
				}
			}
			else if(c == 'M')
			{
				if(c1 == 'U')
				{
					if(a<m[x-'A'][y1-'A'])
					m[x-'A'][y1-'A'] = a;
				}
				else
				{
					if(a<m[x-'A'][y1-'A'])
					m[x-'A'][y1-'A'] = a;
					if(a<m[y1-'A'][x-'A'])
					m[y1-'A'][x-'A'] = a;
				}
			}
		}

		scanf("%c %c",&c,&c1);
		//if(c == c1)
		//{
			//cout << 0 << " " << c << endl;
		//}

		for(k = 0; k <26;k++)
        {
            for(i = 0; i <26;i++)
            {
                for(j = 0; j <26;j++)
                {
                      y[i][j] = min(y[i][j],y[i][k]+y[k][j]);
					  m[i][j] = min(m[i][j],m[i][k]+m[k][j]);

                 }
           }
        }
		unsigned long ans = INF;
		for(i = 0;i<26;i++)
		{
			if(y[c-'A'][i] + m[c1-'A'][i] < ans)
			{
				ans = y[c-'A'][i] + m[c1-'A'][i];
			}
		}
		if(ans == INF)
		{
			cout << "You will never meet.\n";
		}
		else
		{
			for(i = 0;i<26;i++)
			{
				if(y[c-'A'][i] + m[c1-'A'][i] == ans)
				{
					v.push_back(i);
				}
			}
			sort(v.begin(),v.end());
			j = v.size();
			cout << ans;
			for(i = 0;i<j;i++)
			{
				cout << " " << char(v[i]+'A');
			}
			cout << endl;
			v.clear();

		}
	}
	return 0;
}
