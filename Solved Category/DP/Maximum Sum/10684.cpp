#include<iostream>

using namespace std;
int N;


int arr[10005];

int find_max()
{
	int max, suffix,i;

	max = suffix =  0;

	for( i = 0; i < N; i++)
	{
		if(suffix + arr[i] > max)
		{
			max = suffix + arr[i];
			suffix = max;
		}
		else if(suffix + arr[i] > 0)
		{
			suffix += arr[i];
		}
		else
		{
			suffix = 0;
		}
	}

	return max;

}

int main(void)
{
	int i;

	int max;

	while(1)
	{

	
	    cin >> N;

		if(!N)
			break;

		for( i = 0; i < N; i++)
		{
		
			
			cin >> arr[i];
			
		}

		max = find_max();

		if(max > 0)
		{
		   cout << "The maximum winning streak is " << max << "." <<  endl;
		}
		else
		{
			cout << "Losing streak."<< endl;

		}
	}

	






	return 0;
}