#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <char> v ;

vector<char>::iterator pos ;

int main(void)

{
	
     char c;
	

	int num ;

	int j,k = 0 ;

	int a ;

	cin >> num ;

	while( num)
	{
		a = num ;

         while( a)
		 {
			 j = a % 2 ;

			 //c =( char )(j );

			 c = j + 48 ;

			 v.push_back(c);

			 if( j == 1)

				 k++;

			 a >>= 1 ;

			 


		 }


		
        reverse(v.begin(),v.end());

		

		cout << "The parity of " ;

		for (pos = v.begin(); pos != v.end(); ++pos)
		{

          cout << *pos ;

		}

		cout << " is " << k << " (mod 2).\n";

        k = 0;

		v.clear();

		cin >> num ;
	}


	return 0;
}