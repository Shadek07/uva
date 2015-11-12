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

int main(void)
{
	int t;
	int a,b,c;
	int ca=1;
	int i;
	while(cin >> t && t)
	{

		b = c = 0;
		for(i =0;i<t;i++)
		{
			cin >> a;
			if(a==0)
				b++;
			else
				c++;
		}
		cout << "Case " << ca++ << ": " << c-b<<endl;
	}
	return 0;
}
