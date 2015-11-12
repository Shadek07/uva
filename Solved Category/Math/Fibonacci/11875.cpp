#include<iostream>

using namespace std;

int input[20];
int i;

int main(void)
{

	int t,n,i;

	int ca = 1;

	int ind;

	cin >> t;

	while(t--)
	{
		cin >> n;

		ind = n/2;

		for( i = 0; i < n; i++)
		{
			cin >> input[i];
		}

		cout << "Case " << ca++ << ": ";

		cout << input[ind] << endl;

	}

	return 0;
}