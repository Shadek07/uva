#include<iostream>

using namespace std ; 

int main(void)
{
	char c , in[100][100]  ;

	int i = 0,j = 0, k ,len ;

    while( ( c = getchar() ) != EOF )
	{

          if( c == ' ' || c == '\t')
		  {
			  in[i][j++] = c ;

			  in[i][j] = '\0' ;

			  i++ ;

			  j = 0 ;

		  }

		  else if( c != '\n' )
		  {
			  in[i][j++] = c ;

			 

		  }

		  else if( c == '\n' )
		  {
			  in[i][j] = '\0' ;

              for( k = 0 ; k <= i ; k++ )
			  {

				  if( k == i )
				  {

					  cout << in[k][strlen(in[k]) - 1] ;
				  }

				  for( len = strlen( in[k] ) - 2; len >= 0 ; len -- )
				  {

					  cout << in[k][len] ;

				  }

				  if( k <= i - 1 )

				  cout << in[k][strlen(in[k]) - 1] ;

			  }

			  cout << "\n" ; 

			  i = 0 ;

			  j = 0;


               

		  }

	}

    


	return 0;
}