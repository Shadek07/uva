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
#define min(a,b) a<b?a:b
int main(void)
{
	int ca=1;
	int t,n,p,q,i,j;
	int w[35];
	cin >> t;
	while(t--)
	{
		cin >> n >> p >> q;
		for(i=0;i<n;i++)
			cin >> w[i];
		int cnt=0;
		j = min(p,n);
		for(i=0;i<j;i++)
		{
			q -= w[i];
			if(q>=0)
				cnt++;
		}
		cout << "Case " << ca++<<": " << cnt << endl;

	}
	return 0;
}