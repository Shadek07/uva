#include<iostream>

using namespace std;

int main()
{
    long	int B,P,M;

	long int x = 1;

	cin >> B >> P >> M;


	int power = B % M;


	int arr[35];

	int k = 0;
	int c,i,j;


	while(P>0)
	{
		arr[k] = P%2;

		P = P/2;

		k++;
	}

	for(i = 0,j = k -1;i<j;i++,j--)
	{
		c = arr[i];

		arr[i] = arr[j];

		arr[j] = c;
	}

	for(int l = 0;l< k ;l++)
	{

		if(arr[l] == 1)
			x = (x*power) % M;
		power = (power * power)% M;
	}

	cout << x<< endl;

	return 0;
}



	