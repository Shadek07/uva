#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(void)
{
	int t;
	int n,k;
	cin >> t;

	while(t--)
	{
		cin >> n >> k;

		int res = k^(k>>1);
		cout << res << endl;

	}
	return 0;
}