#include<iostream>
using namespace std;

int main()
{
	long int num1,limit = 0;

	long int t;

	

	int count = 0;

	int pha = 1;

	int check = 1;

	
   cin >> num1 >> limit;

   

   t = num1;
	

	while( (num1 > 0 )  )
	{

		
	
	
	

		while( !((t ==1 ) || ( check == 0 )) )
		{

			if( t%2 == 0)
			{
				t /=2;

				count++;
			}

			else
			{


				count++;

				if(  t  > ( limit - 1) /3 )
				{
					check = 0;

				}

				else


				t = 3*t + 1;



			

	

			}

			if( t == 1)

				count++;

		}

		cout << "Case " << pha << ": A = " << num1 << ", limit = "<< limit << ", number of terms = " ;  

				
		cout << count << "\n";

		
		

		

		count = 0;

		check = 1;

		pha++;
		
	

		
	



	scanf("%ld %ld", &num1,&limit );

	t = num1;

	



	}

	

	return 0;
}
