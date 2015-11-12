#include<iostream>

using namespace std;

int main(void)
{

	int n,i,sum,j,k,s = 1;
	int in[50];

	while(1)
	{
		cin >> n;
		if(!n)
			break;
         
		sum = 0;
		for(i = 0; i < n; i++)
		{
			cin >> k;
			sum += k;
			in[i] = k;
		}

		j = sum/n;
        
		k = 0;

		for(i = 0; i < n;i++)
		{
			if(in[i] > j)
				k += (in[i] - j);

		}

		cout << "Set #" << s++ << endl;
		cout << "The minimum number of moves is " << k << ".\n\n";
	}



	return 0;
}