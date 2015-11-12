#include<iostream>

using namespace std;

int main(void)

{
	int num;

	int arr[200];

	int output[80];

	int head = 0;

	int total = 0;

	int tail;

	int i = 0,j ;
	

	cin >> num;


	while(num)
	{

				for( j = 1; j<= num; j++)
				{
					arr[j-1] = j;
				}

				total = num;

				tail = num - 1;


				while( total != 1)
				{
					output[i++] = arr[head] ;

					head++;

					total--;

					tail++;

					arr[tail] = arr[head];

					head++;
				}

				cout <<"Discarded cards: ";

				for(int k = 0 ; k < i ; k++)
				{
					if( k != i - 1)

					cout << output[k] << ", ";

					else

						cout << output[k];
				}

				cout << "\n";

				cout << "Remaining card: " << arr[head] << "\n";


				head = 0;

				i = 0;

				cin >> num;
				
	}



	return 0;



}