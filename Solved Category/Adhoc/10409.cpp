// find the value of top face of a die
 
#include<iostream>

using namespace std;

int main( void)
{
	int total,m; // total direction

	int save = 0;

	char arr[6];

	char c;

	int top = 1;

	int bottom = 6; // 1 + 6 = 7, bottom is reverse direction of top


	int west = 3;

	int east = 4; // 3 + 4 = 7, east is reverse direction of west

	int north = 2;

	int south = 5; // 2 + 5 = 7, south is reverse direction of north


    int i = 0;

	int tmp;

	cin >> total;

	
   getchar();

	while( total != 0)
	{
	

				for( m = 0 ; m < total ; m++ )
				{
					   


						while( ( c = getchar() ) != '\n')
						{
							arr[i++] = c;
						}

						if( arr[0] == 'e') // 'e' for east
						{
							tmp = bottom;

							bottom = east;

							east = top;

							top = west;

							west = tmp;
						}

						if( arr[0] == 'w' ) // 'w' for west
						{
							tmp = bottom;

							bottom = west;

							west = top;

							top = east;

							east = tmp;
						}

						if( arr[0] == 'n' ) // 'n' for north
						{
							tmp = bottom;

							bottom = north;

							north = top;

							top = south;

							south = tmp;
						}

						if( arr[0] == 's' ) // 's' for south
						{
							tmp = bottom ;

							bottom = south;

							south = top;

							top = north;

							north = tmp;
						}

						

						i = 0;

						

				} 



				cout << top << "\n";


				cin >> total;

				
                getchar() ;
				
                save = 0;
                
				top = 1;

				bottom = 6;

				west = 3;

				east = 4;

				north = 2;

				south = 5;

			    
	}




	return 0;

}
