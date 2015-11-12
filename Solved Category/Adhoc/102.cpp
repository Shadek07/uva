#include<iostream>

using namespace std;

int main(void)
{
	int b1[3],b2[3],b3[3] ;

	char t[6][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"} ;

	int min = -1 ;

	int index = 0 ; 

	int result = 0 ; //BGC

	while( (scanf("%d %d %d %d %d %d %d %d %d", &b1[0],&b1[1] ,&b1[2],&b2[0],&b2[1],&b2[2],&b3[0],&b3[1],&b3[2])) == 9)
	{
          //B = 0 , G = 1, C = 2 ;
		  result += b2[0] + b3[0] + b1[2] + b3[2] + b1[1] + b2[1] ; //BCG

          min = result  ;

		  result = 0 ;

		  result += b2[0] + b3[0] + b1[1] + b3[1] + b1[2] + b2[2] ; //BGC

		  if( result < min )
		  {
			  min = result ;

			  index = 1;
		  }

		  //B = 0 , G = 1, C = 2 ;
		   result = 0 ;

		  result += b2[2] + b3[2] + b1[0] + b3[0] + b1[1] + b2[1] ; //CBG

		  if( result < min )
		  {
			  min = result ;

			  index = 2;
		  }

		  result = 0 ;

		  result +=b2[2] + b3[2] + b1[1] + b3[1] + b1[0] + b2[0] ; //CGB

		  if( result < min )
		  {
			  min = result ;  //B = 0 , G = 1, C = 2 ;

			  index = 3;
		  }

		  result = 0 ;

		  result += b2[1] + b3[1] + b1[0] + b3[0] + b1[2] + b2[2] ; //GBC

		  if( result < min )
		  {
			  min = result ;

			  index = 4;
		  }

		  result = 0 ;

		  result += b2[1] + b3[1] + b1[2] + b3[2] + b1[0] + b2[0] ; //GCB

		  if( result < min )  //B = 0 , G = 1, C = 2 ;
		  {
			  min = result ;

			  index = 5 ;
		  }

		  result = 0 ;

		  

		  cout << t[index] << " " << min << "\n" ;

		  index = 0 ;


	}


	return 0 ;
}