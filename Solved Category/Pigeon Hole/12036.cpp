#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int cal[105];
vector<int> v1;
int main(void)
{
	int ca = 1;
	int i;
	int test = 0;
	int t;
	int m,a;
	cin >> t;

	while(t--)
	{
		cin >> m;

		test = 0;

		memset(cal,0,sizeof(cal));

		for(i = 0; i < m*m; i++)
		{
			cin >> a;
			cal[a]++;
		}

		for(i = 0; i <= 100; i++)
		{
			if(cal[i] > m)
			{
				test = 1;
				break;
			}
		}

	

	

		if(test == 0)
		{
			cout << "Case " <<ca++ << ": yes" << endl;
		}
		else
		{
			cout << "Case " << ca++ << ": no" << endl;

		}

	}

	return 0;

}
