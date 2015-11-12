#include<iostream>

using namespace std;

int main( void )

{
	long int t;

	long int a,b;

	 

	 
	cin >> t;

	

	while( t > 0 )
	{

		cin >> a >> b;
        
		if( a > b)

			cout << ">\n";

		if( a == b)

			cout << "=\n";

		if( a < b)

			cout << "<\n";

		

		t--;

	}



	return 0;
}