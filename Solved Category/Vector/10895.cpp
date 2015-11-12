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
#include<stack>

using namespace std;
int row[1001];
int value[1001];
vector<int> v[10001];
vector<int> col[10001];
int main(void)
{
	int i,j,k,a,b,c,m,n;
	while(cin >> m >> n)
	{
		for(i = 0; i< m;i++)
		{
			cin >> a;
			for(j = 0;j<a;j++)
				scanf("%d",&row[j]);
			for(j = 0;j<a;j++)
				scanf("%d",&value[j]);
			for(j = 0;j<a;j++)
			{
				b = row[j];
				c = value[j];
				v[b-1].push_back(c);
				col[b-1].push_back(i);
			}

		}
		cout << n << " " << m << endl;
		for(i = 0;i<n;i++)
		{
			a = v[i].size();
			if(a == 0)
			{
				cout << 0 << endl;
				cout << endl;
			}
			else
			{
				cout << a;
				for(j = 0; j<a;j++)
					cout << " " << col[i][j]+1;
				cout << endl;
				cout << v[i][0];
				for(j = 1;j<a;j++)
					cout << " " << v[i][j];
				cout << endl;
			}
		}

		for(i = 0;i<n;i++)
		{
			v[i].clear();
			col[i].clear();
		}
	}
	return 0;
}
