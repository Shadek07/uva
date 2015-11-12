#include<iostream>
#include<cmath>

using namespace std ;


int compute_decimal( char c[] ,int) ;

char binary[][5] = { "0000",  "0001" , "0010","0011" , "0100",

	"0101", "0110" ,"0111" , "1000" , "1001","1010" ,"1011","1100",

	"1101" , "1110" , "1111" };


int main( void )

{
	int total;

	char in[30];



	
	char c,c1;

	int i = 0;

	cin >> total ;

	c1 = getchar() ;

	while( total-- )
	{


            while( (c = getchar() ) != '\n' )
			{
				in[i++] = c;

			}

			in[i] = '\n';

			compute_decimal( in,i) ;

            i = 0;





	}


    return 0;
}




int compute_decimal( char c[] ,int a)
{

	int b = 0,e = 0, j = 0;

	char c3;

	int p;

	int get;

	int sum1 = 0,sum2 = 0;


				while( c[b++] != ' ' )
				{
					e++;
				}

				p = e - 1; // power

			//	cout << "e:" << e << "\n";

				cout << "0" ;

				if( e == 1)

					cout << "00000000";

				if( e == 2 )

					cout << "0000";

				for( j = 0; j < e ; j++ )
				{
					if( c[j] >= '0' && c[j] <= '9' )
					{
						get = (int)( c[j]) - 48;

						//cout << "\n" << get << "\n";

						if( p == 2 )

						    sum1 += (get*256);

						if( p == 1)

							sum1 += (get*16);

						if( p == 0 )

							sum1 += (get*1);

						

						cout << binary[get];

						p--;
					}

					if( c[j] >= 'A' && c[j] <= 'F' )
					{
						get = (int)( c[j] ) - 55;

						if( p == 2 )

						    sum1 += get*256;

						if( p == 1)

							sum1 += get*16;

						if( p == 0)

							sum1 += get*1;

						cout << binary[get] ;

						p--;
					}

				}

				cout << " ";

				c3 = c[b];   // + or -

				cout << c3 << " "  << "0";

				p = a - e - 4 ;

			//	cout << "P:" << p << "\n";

				if( p == 1)

					cout << "0000";

				if( p == 0 )

					cout << "00000000";

				b++; 

				while( c[b++] != '\n' )
				{

							if( c[b] >= '0' && c[b] <= '9' )
							{
								get = (int)( c[b]) - 48;

								if( p == 2 )

						             sum2 += get*256;

						        if( p == 1)

							         sum2 += get*16;

						        if( p == 0)

							         sum2 += get*1;

								     

								cout << binary[get];

								p--;
							}

							if( c[b] >= 'A' && c[b] <= 'F' )
							{
								get = (int)( c[b] ) - 55;
								
								if( p == 2 )

						           sum2 += get*256;

								if( p == 1)

									sum2 += get*16;

								if( p == 0)

									sum2 += get*1;

								

								cout << binary[get];

								p--;
							}


				}


				cout << " = " ;

				if( c3 == '+')
				{
					cout << sum1 + sum2;
				}

				else

					cout << sum1 - sum2;

				cout << "\n";

				sum1 = sum2 = 0;



				return 1;





  
}