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

using namespace std;

typedef pair<int,int> pa;
multimap<int,pa> mp1;
multimap<pa,int> mp2;
multimap<pa,int>::iterator it;

int n;
int main(void)
{
	int i,j,k,a,b;
    int ind;
	pa p1,p2;
	while(cin >> n && n)
	{
		ind = 1;
		for(i = 0; i < n;i++)
		{
			cin >> a >> b;
			p1 = pa(a,b);
			p2 = pa(b,a);
			if(mp2.count(p2) == 0)
			{
				mp2.insert(pair<pa,int>(p1,ind));
				ind++;
			}
			else
			{
				it = mp2.find(p2);
				mp2.erase(it);
			}		

		}

		
		
		if( mp2.size() != 0)
		{
			cout << "NO\n";
		}
		else
			cout << "YES\n";

		
		
		mp2.clear();
	}

	return 0;
}