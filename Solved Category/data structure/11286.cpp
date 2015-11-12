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

vector<int> v;
set<string> sec;
multiset<string> mp;
set<string>::iterator it;
int main(void)
{
	int n,i,j,k,a,b;

	char in[100],in1[100];
	string s;
	while(cin >> n && n)
	{
		for(j = 0; j < n;j++)
		{
			v.clear();
			for(i = 0; i < 5;i++)
			{
				cin >> a;
				v.push_back(a);
			}
			sort(v.begin(),v.end());
			//itoa(v[0],in,10);
			sprintf(in, "%d", v[0]);
			for(i = 1;i<5;i++)
			{
				//itoa(v[i],in1,10);
				sprintf(in1, "%d", v[i]);
				strcat(in,in1);
			}

			s = in;
			sec.insert(s);
			mp.insert(s);
		}

		int mx = 0;
		int cnt;
		int sum = 0;
		for(it = sec.begin(); it != sec.end();it++)
		{
		    s = *it;
            cnt = mp.count(s);
            if(cnt > mx)
            mx = cnt;
		}
		for(it = sec.begin(); it != sec.end();it++)
		{
		    s = *it;
            cnt = mp.count(s);
            if(cnt == mx)
            sum += cnt;
		}

		cout << sum << endl;
		v.clear();
		sec.clear();
        mp.clear();

	}
	return 0;
}
