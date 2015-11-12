#include<iostream>

using namespace std;

void take( int num) ;

void MSB( int num);

int count[5] = {0};

int main( void)
{
    int digit,i,j,k,l,a;

	char c[5] ={'i','v','x','l','c'};

	 // i = v = x = l = c = 0

	scanf("%d", & digit) ;

	while( digit )
	{

		for( i = 1; i <= digit ; i++ )
		{
			j = i ;

			if( j <= 9 )
			{
				take( j ) ;
			}

			if( j > 9 && j < 100 )
			{
				a = j / 10;

				if( (j%10) == 0 )
				{
					MSB( a );
				}

				else
				{
					

					take( j % 10 );

					MSB( a);
				}
			}

			if( j == 100 )
			{
				count[4]++;
			}
		}

		cout << digit << ": " ;

		for( k = 0; k < 5; k++)
		{
			cout << count[k] << " " << c[k];

			if( k == 4)
				cout << "\n";

			else

				cout << ", " ;

		}

		for( l = 0; l< 5; l++)
		{
			count[l] = 0;
		}

			



			

		


        scanf("%d", & digit);
	}

	return 0;
}

// i = v = x = l = c = 0

void take( int num)
{
	switch( num)
	{
				case 1:

					   count[0]++;

					   break;

				case 2:

					   count[0] += 2;

					   break;

				case 3:

						count[0] += 3;

						break;

				case 4:
				case 6:

						count[0]++;

						count[1]++;

						break;


				case 5:

						count[1]++;

						break;

				case 7:

					   count[0] += 2;

					   count[1]++;
					   
					   break;



				case 8:
             

					  count[0] += 3;

					  count[1]++;
					  
					  break;

				case 9:

					   count[0]++;

					   count[2]++;
					   
					  // break;
	}

		   

	
}

void MSB ( int num )
{
	switch(num)
	{
	case 1:

		count[2]++;

		break;

	case 2:

		count[2] += 2;

		break;

	case 3:

		count[2] += 3;

		break;

	case 4:
	case 6:

		count[2]++;
		count[3]++;

		break;

	case 5:

		count[3]++;

		break;

	case 7:

		count[3]++;
		count[2] += 2;

		break;

	case 8:

		count[3]++;
		count[2] += 3;

		break;
	case 9:

		count[4]++;
		count[2]++;

		//break;

	}


}
		   
		    

		    


	

