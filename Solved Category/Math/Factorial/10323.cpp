#include<iostream>
#include<cstring>

using namespace std;





int main(void)
{

    int n,i;

	long res;

	while(cin >> n)
	{
		if( n >= 0 && n < 8)
		{
			//cout << "Overflow!\n";
			cout << "Underflow!\n";
		}
		else if( n > 13)
		{
           cout << "Overflow!\n";
		}
		else if( n >= 8 && n <= 13)
		{
			if( n < 13)
			{
				res = 1;

				for( i = 2; i <= n; i++)
					res *= i;
				cout << res << endl;
			}
			if( n == 13)
			{
				cout << "6227020800\n";
			}
              
		}
		else if ( n < 0)
		{
			n *= -1;
			if(n%2 == 0)
			{
				cout << "Underflow!\n";
			}
			else
			{
				cout << "Overflow!\n";
			}
		}
	}
     

	
	


	return 0;
}

