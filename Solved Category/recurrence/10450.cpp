#include<iostream>

using namespace std;

int main(void)
{

	long int arr[51];

	int t,n,ca=1,i;

	cin >> t;

	while(t--)
	{
		cin >> n;
		arr[0] = 1;
		arr[1] = 2;

		cout << "Scenario #" << ca++ <<":\n";

		if( n < 2)
		{
			cout << arr[n] << endl<< endl;

		}
		else
		{
			for(i = 2; i <= n; i++)
			{
				arr[i] = arr[i-1]+ arr[i-2];
			}

			cout << arr[n] << endl << endl;
		}

	}

	return 0;
}