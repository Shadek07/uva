#include<iostream>

using namespace std;

int main(void)
{
 	
 	int ins;
 	int size;
 	int block;
 	int i,j,k,l;
 	
 	int r1,r2,c1,c2;
 	
 	int a1,a2,b1,b2;
 	
 	cin >> ins;
 	
 	while(ins--)
 	{
	 			int arr[101][101] = {1};
	 			
	 			cin >> size;
	 			
	 			cin >> block;
	 			
	 			for(i = 0; i < 100;i++)
	 			{
				 	  for(j = 0; j < 100;j++)
				 	  {
					   		arr[i][j] = 1;
			   		  }
	 	        }
	 			
	 			for( i = 0; i < block; i++)
	 			{
				 	 cin >> r1 >> c1 >> r2 >> c2;
				 	 
				 	 for( a1 = r1-1; a1 < r2; a1++)
				 	 {
					  	  for( a2 = c1 - 1; a2 < c2; a2++)
					  	       arr[a1][a2] = 0;
                     }
	            }
	            
            	for( i = 0; i < size; i++)
				{

					for( j = 1; j < size; j++)
					{
						if( arr[i][j] == 1)
							arr[i][j] = arr[i][j-1] + 1;
						else
							arr[i][j] = 0;
					}
				}

				int max = 0;

				int temp;

				for( i = 0; i < size; i++)
				{
					for( j = 0; j < size; j++)
					{
						if( arr[i][j] > 0)
						{
							 temp = 0;

							 temp = arr[i][j];

							 int i1 = i;

							 while(--i1 >= 0)
							 {
								 if(arr[i1][j] >= arr[i][j])
									 temp += arr[i][j];
                                 else
                                      break;
							 }

							 i1 = i;

							 while(++i1 < size)
							 {
								 if(arr[i1][j] >= arr[i][j])
									 temp += arr[i][j];
									 else
                                      break;
							 }

							 if( temp > max)
								 max = temp;

						}
					}
				}
				
				cout << max << endl;
	 			
	 			
    }
}
