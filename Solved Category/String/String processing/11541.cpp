#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

int main()
{

	int testcases;

	char arr[202];

	char ch,ch1;

	int i = 0;
	int tru = 1;

    long	int val = 0;
    
    int k;
	int take2 = 0;

	int take = 1;
	

	int count = 1;
	
	cin >> testcases;
	
	getchar();

	while(testcases--)
	{
                      
                      
         gets(arr); 
         
         //getchar();

		 
         cout << "Case " << count++ <<":"<< " ";

		for( int j = 0; j < strlen(arr) ; j++)
		{
			if( (arr[j] >= 'A') && (arr[j] <= 'Z'))
			{
				ch1 = arr[j];

				cout << arr[j];

				j++;

				while( isdigit(arr[j]))
				{
					val = 10* val + (arr[j] - '0');

					j++;
				}
				for(   k = 0 ; k< val -1;k++)
				{
					cout << ch1;
				}

				val  = 0;

			    j--;	
			}
			
		}

		cout << "\n"; 

		
		
		i = 0;

		val = 0;
	
	}

	return 0;
}



