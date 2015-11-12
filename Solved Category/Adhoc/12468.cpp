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
	int a,b;
	int c,d;
	while(cin >> a >> b)
	{
		if(a == -1 && b == -1)
			break;
		int mx;
		if(a == b)
		{
			cout << 0 << endl;
			continue;
		}
		if(a < b)
		{
			c = b-a;
			d = a;
			d += 100-b;
			if( c < d)
				cout << c << endl;
			else
				cout << d << endl;
		}
		if(a > b)
		{
			c = a-b;
			d = 99-a;
			d += b+1;
			if(c < d)
				cout << c << endl;
			else
				cout << d << endl;
		}
	}
	return 0;
}