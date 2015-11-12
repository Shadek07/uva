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

	while( num >= 0 )
	{
		a = num ;

         while( a )
		 {
			 j = a % 3 ;

			 

			 c = j + 48 ;

			 v.push_back(c);


			 a /= 3 ;

			 


		 }


		
        reverse(v.begin(),v.end());

		

		

		if( num == 0)

			cout << "0";

		for (pos = v.begin(); pos != v.end(); ++pos)
		{

          cout << *pos ;

		}

		cout << "\n";

        k = 0;

		v.clear();

		cin >> num ;
	}


	return 0;
}