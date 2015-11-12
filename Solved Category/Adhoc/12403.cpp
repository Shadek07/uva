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

	int t,a;
	char in[20];
	cin >> t;
	getchar();
	int k = 0;
	while(t--)
	{
		cin >> in;
		if(strcmp(in,"donate")==0)
		{
			cin >> a;
			k+=a;
		}
		else if(strcmp(in,"report")==0)
		{
			cout << k << endl;
		}

	}
	return 0;
}