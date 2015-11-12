#include<iostream>

using namespace std;

int main( void)
{
	int num,t;

	cin >> t;

	while( t )
	{
		cin >> num ;

		num *= 567 ; 

		num /= 9 ;

		num += 7492 ;

		num *= 235 ;

		num /= 47 ;

		num -= 498 ;

		num /= 10 ;

		cout << abs (num % 10 ) << "\n" ;

		


		t--;
	}


	return 0;
}