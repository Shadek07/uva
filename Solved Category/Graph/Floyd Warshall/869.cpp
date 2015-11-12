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
map<char,int> mp;
vector<char> v;
set<char> st; 

bool fir[60][60];
bool sec[60][60];

int main(void)
{
	int t;
	int i,j,k,a,b,m,n;
	char in[5],c,c1;
	cin >> t;
	getchar();
	getchar();
	int ind;
	bool ch=false;
	while(t--)
	{
		cin >> m;
		getchar();
		ind = 1;
		memset(fir,false,sizeof(fir));
		for(i=0;i<m;i++)
		{
			gets(in);
			c = in[0];
			c1 = in[2];
			if(!mp[c])
				mp[c] = ind++;
			if(!mp[c1])
				mp[c1] = ind++;
			a = mp[c];
			b = mp[c1];
			fir[a][b] = true;
			fir[b][a] = true;
		}

		cin >> n;
		getchar();
		memset(sec,false,sizeof(sec));
		for(i=0;i<n;i++)
		{
			gets(in);
			c = in[0];
			c1 = in[2];
			if(!mp[c])
				mp[c] = ind++;
			if(!mp[c1])
				mp[c1] = ind++;
			a = mp[c];
			b = mp[c1];
			sec[a][b] = true;
			sec[b][a] = true;
		}

		for(k = 1;k<ind;k++)
		{
			for(i = 1;i<ind-1;i++)
			{
				for(j = i+1;j<ind;j++)
				{
					if(k != i && k != j)
					{
						fir[i][j] |=(fir[i][k]&&fir[k][j]);
					}
				}
			}
		}
		for(k = 1;k<ind;k++)
		{
			for(i = 1;i<ind-1;i++)
			{
				for(j = i+1;j<ind;j++)
				{
					if(k != i && k != j)
					{
						sec[i][j] |=(sec[i][k]&&sec[k][j]);
					}
				}
			}
		}

		if(ch==false)
			ch = true;
		else
			cout << endl;
		bool t1 = true;
		for(i = 1;i<ind-1;i++)
		{
			for(j = i+1;j<ind;j++)
			{
				if(fir[i][j] != sec[i][j])
				{
					t1 = false;
					i=ind;
					break;
				}
			}
		}
		if(t1)
			cout << "YES\n";
		else
			cout << "NO\n";
		mp.clear();


	}
	return 0;
}