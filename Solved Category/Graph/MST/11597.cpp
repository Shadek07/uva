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
	int ca = 1;
	while(1)
	{
		int n;
		cin >> n;
		if(!n)
			break;
		cout << "Case " << ca++ << ": " << (n>>1) << endl;
	}
}