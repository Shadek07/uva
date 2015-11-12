#include<iostream>
#include<list>
#include<cmath>

using namespace std;


bool check[3001];

int main( void )
{
	

	int n,n1,i;

	int c = 1;

	

	int first,second;



	memset(check,false,sizeof(check));


	while(cin >> n)
	{
	    cin >> first;
		
		for( n1 = 2; n1 <= n ; n1++)
		{
			cin >> second;

			check[abs(first-second)] = true;
			first = second;
		}

		for( i = 1; i < n;i++)
		{
             if( check[i] == false)
			 {
				 c = 0;
				 break;
			 }
		}

	
		
		

		if( c == 1)

			cout << "Jolly\n";

		else

			cout <<"Not jolly\n";


        memset(check,false,sizeof(check));

		c = 1;


	}



	return 0;
}

