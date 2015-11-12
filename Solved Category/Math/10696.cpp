#include<iostream>

using namespace std;


int main(void)
{
	int num,a ;
    
	cin >> num ;

	while( num )
	{

        if( num <= 101 )

			a = 91 ;

		else

			a = num - 10 ;

		cout << "f91(" << num << ") = " << a << "\n";

		cin >> num ;

	}

	return 0 ;
}


