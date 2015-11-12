#include<iostream>
#include<algorithm>

#include<vector>

using namespace std;

vector <int> coll;

vector<int>::iterator pos;

int main(void)
{


	int cour,catg ;

	int num ;

	int each ;

	int min ;

	int min_count = 0;

	int check = 1 ;

	int i,j,l ;

	cin >> cour ;

    while( cour)
	{
		cin >> catg ;

		for( j = 0 ; j < cour ; j++)
		{
			cin >>  num ;

			coll.push_back(num) ;

			
		}

		for( l = 0 ; l < catg ; l++ )
		{

			cin >> each >> min ;

		

			for( j = 0 ; j < each ; j++ )
			{
				cin >> i ;

				pos =  find (coll.begin() , coll.end(),i) ;

				if( pos != coll.end() )

					min_count++ ; 


			}

			if( min_count < min )

				check = 0 ;

			

				

              
           min_count = 0 ;

		}

		if( check == 1)

			cout << "yes\n";

		else

			cout << "no\n";


        
		coll.clear();

        check = 1;

		min_count = 0 ;

		cin >> cour ;
	}

	return 0;
}