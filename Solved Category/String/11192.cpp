#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char arr[102];

	int group;

	int sav[11];

	int i = 0,j, k = 0;

	int c,d;

	int a;
	

	while(1)
	{
        
        cin >> a;
        if( a == 0)
        break;
        getchar();
        gets(arr);
		group = strlen(arr)/a;

		int p = strlen(arr);

            //div = arr[0] - 48;

			for( j = 0; j <= p  ; j = j + group )
			{
				sav[k++] = j;
			}
            
			k = k-1;

			for( int b = 0; b < k ; b++)
			{
				c= sav[b];

				d = sav[b+1] - 1;

				for( ; c <  d; c++ ,d--)
				{
					char t = arr[c];

					arr[c] = arr[d];

					arr[d] = t;
				}
			}

			for( int e = 0; e < p; e++)
			{
				cout << arr[e];
			}

			cout << "\n";

			i = 0;

			for( int d = 0; d < k;d++)
			{
				sav[d] = 0;
			}

			k = 0;


			
		
		  
		}

	return 0;
}


