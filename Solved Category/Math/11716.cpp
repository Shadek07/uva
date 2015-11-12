#include<iostream>
#include<cmath>

using namespace std;

int main( void)
{

	int t ,j,len,k,m,n ;

	float r ;

	char in[10000] ,c ;

	cin >> t ;

    c = getchar() ;

    while( t )
	{

         gets(in) ;

		 len = strlen(in) ;


          r = sqrt(len) ;

		  m = (int) r ;

          if( ((int)r - (float)r ) != 0 )
		  {
			  cout << "INVALID\n" ;
		  }

		  else
		  {

			  for( j = 0 ; j < r ; j++ )
			  {

				  n = j ;

				  for( k = 0 ; k < r ; k++ )
				  {
                        
					  cout << in[n] ;

					  n += m ;

				  }

			  }

			  cout << "\n" ;
		  }
		 t-- ;
	}

	return 0;
}
