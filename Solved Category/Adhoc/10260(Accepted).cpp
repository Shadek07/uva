#include<iostream>

#include<cstring>

using namespace std;


int main()
{
	int arr[26] = {8,1,2,3,8,1,2,8,8,2,2,4,5,5,8,1,2,6,2,3,8,1,8,2,8,2};

	char letter[27];

	char ch;

	int i = 0;

	int k;

	int val,val1;

	while( (ch = getchar()) != EOF)
	{
		if( ch !='\n')
		{
			letter[i++] = ch;
		}

		else
		{
			letter[i] = '\0';
			

			for( k = 0; letter[k] !='\0';k++)
			{
				val = (int)letter[k] - 65;

							
				if( k == 0)
				{
					if( arr[val] != 8)
					{
						cout << arr[val];
					}
				}

				else
				{
					val1 = (int)letter[k - 1] - 65;


					
				    if( (arr[val] != arr[val1]) && (arr[val] != 8))
						
						cout << arr[val];

				}
			
							
				
			}

			k = 0;

			i = 0;
			cout << "\n";
		}

		
	}

	return 0;
}


