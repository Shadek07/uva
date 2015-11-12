#include<iostream>
#include<list>
#include<cmath>
#include<set>

using namespace std;


bool check[3001];

set<int> st;

int main( void )
{
	

	int n,n1,i;

	int c = 1;

	

	int first,second;




	while(cin >> n)
	{
	    cin >> first;
		
		for( n1 = 2; n1 <= n ; n1++)
		{
			cin >> second;

			int ab = abs(first-second);			

			if(ab>=1 && ab <= n-1)
			{
			  st.insert(abs(first-second));
			}

			first = second;
		}

	

		int cnt = st.size();

	
		
		

		if( cnt == n-1)

			cout << "Jolly\n";

		else

			cout <<"Not jolly\n";


        st.erase(st.begin(),st.end());

		c = 1;


	}



	return 0;
}

