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
	int a,b;
	unsigned long int ans;
	
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		ans = ceil(a/3)*ceil(b/3);
		cout << ans << endl;
	}
	return 0;
}