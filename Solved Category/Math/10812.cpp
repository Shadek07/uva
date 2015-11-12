#include<iostream>

using namespace std ;

int main(void)

{
	int total , diff ;

	int c ,a,b;

	cin >> c ;

	while(c)
	{
		cin >> total >> diff ;

		int d = (total + diff)%2 ;

		int e = (total - diff)%2 ;

		if( (diff > total ) || e || d)
		{
			cout << "impossible\n" ;

		}

		else
		{
			a = (total+diff)/2 ;

			b = (total - diff)/2 ;


			a > b ? cout << a << " " << b :cout << b << " " << a ;

			cout << "\n" ;


		}

		c-- ;


	}



	return 0;
}