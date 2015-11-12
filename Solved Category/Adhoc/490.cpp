#include<iostream>

using namespace std ;

int main(void)
{
	int i = 0,j = 0,k,m,n ;

	int max = -1 ;

	char s[100][101],c ;

    int save[100] ;

     while( ( c = getchar() ) != EOF )
	 {

		 if( c != '\n' )
		 {
			 s[i][j++] = c ;
		 }

		 else
		 {
			 //s[i][j] = '\0' ;

			 i++ ;

			 save[ i - 1 ] = j - 1 ;

			 if( j - 1 >= max )

				 max = j - 1 ;

			 j = 0 ;

		 }

		

	 }

	 for( m = 0 ; m < i ; m ++ )
	 {
		 for( n = save[m] + 1  ; n <=  max ; n++ )
		 {
			 s[m][n] = ' ' ;

		 }
	 }

	 for(m = 0 ; m  <=  max  ; m++ )
	 {
		 for( n = i - 1 ; n >= 0 ; n--)
		 {
              cout << s[n][m] ;
		 }

		 cout << "\n" ;
	 }

	return 0 ;
}