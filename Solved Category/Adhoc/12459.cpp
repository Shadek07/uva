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
	int t,i;
	unsigned long int cal[81][2];
	cal[1][0] = 0;
	cal[1][1] = 1;

	for(i = 2;i<=80;i++)
	{
		cal[i][0] = cal[i-1][1];
		cal[i][1] = cal[i-1][1]+cal[i-1][0];
	}

	while(cin >> t && t)
	{
		cout << cal[t][0]+cal[t][1] << endl;
	}
	return 0;
}