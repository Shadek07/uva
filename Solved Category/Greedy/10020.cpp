
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

int m;
typedef pair<int,int> pa;
vector<pa> v,ans;

int comp(pa p,pa q)
{
	if(p.first < q.first)
		return 1;
	else if(p.first == q.first && p.second < q.second)
		return 1;
	return 0;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t;
	int ca=1;
	cin >> t;
	int l,r;
	int i,j,k;
	while(t--)
	{
		cin >> m;
		i = 0;
		while(cin >> l >> r && !(l == 0 && r == 0))
		{
			v.push_back(make_pair(l,r));
			i++;
		}
		if(ca==1)
			ca=2;
		else
			cout << endl;

		sort(v.begin(),v.end(),comp); //sort by left, then by right
		int tmp = 0; //cover from 0
		bool cover = false;
		for(j=0;j<i && tmp<m;j++)
		{
			int mx = -1;
			for(k = j;k<i;k++)
			{
				if(v[k].first<=tmp)
				{
					if(v[k].second > tmp && v[k].second > mx)
					{
						mx = v[k].second;
						l = v[k].first;
						r = v[k].second;
					}
				}
				else
					break;
			}
			if(mx == -1)
				break;
			tmp = mx;
			ans.push_back(make_pair(l,r));
			if(tmp >= m)//covered the whole segment
			{
				cover = true;
				break;
			}
			j = k-1;
		}

		if(cover == 0)
			cout << 0 << endl;
		else
		{
			j = ans.size();
			cout << j << endl;
			for(i = 0;i<j;i++)
				cout << ans[i].first << " " << ans[i].second << endl;
		}
		v.clear();
		ans.clear();

	}
     return 0;
}