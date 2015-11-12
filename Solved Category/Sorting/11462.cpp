#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v1;
vector<int> ::iterator it;

int main(void)
{
	int n,i,j;

	while(1)
	{
		cin >> n;
		if(!n)
			break;
		for(i = 0; i < n; i++)
		{
			cin >> j;
			v1.push_back(j);
		}

		sort(v1.begin(),v1.end());

		for( i = 0; i < n; i++)
		{
			if( i != n-1)
				cout << v1[i] << " ";
			else
				cout << v1[i] << endl;
		}

		v1.clear();
	}



	return 0;
}