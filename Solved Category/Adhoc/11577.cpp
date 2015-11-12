#include<iostream>

using namespace std ;

int main( void) 
{

     int Golam_Mostafa ;

	 char t[200] , c;

	 char m[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


	 int fre[26] = {0} ;

	 int i,j = 0,l ; 

	 cin >> Golam_Mostafa ;

	 c = getchar() ;

	 while( Golam_Mostafa )
	 {
		 
		 gets(t) ;

		 for( i = 0 ; i < strlen( t ) ; i ++ )
		 {

			 if( t[i] >= 'a' && t[i] <= 'z' )
			 {
				 fre[ t[i] - 'a' ] ++ ;

			 }

			 if( t[i] >= 'A' && t[i] <= 'Z' )
			 {
                   fre[ t[i] - 'A' ] ++ ;

			 }

		 }

		 //cout << "fg" ;

		 for( i = 0 ; i < 26 ; i ++ )
		 {
			 if( fre[i] > j )
			 {
				 j = fre[i] ;

				 l = i ; 
			 }

		 }

		

		 
		 
			 for( i = l ; i < 26 ; i ++ )
			 {
				 if( fre[i] == j )
				 {
                   
					 cout << m[i] ;

				 }
			 }


		     cout << "\n" ;

           for( i = 0 ; i < 26 ; i++ )
		   {

			   fre[i] = 0 ;

		   }


		   Golam_Mostafa-- ;
	 }

	 return 0 ;
}