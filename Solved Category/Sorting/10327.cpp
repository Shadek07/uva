#include<iostream>

using namespace std;

int main(void)
{
    
    int N;
    
    int arr[1000];
    int i,j,count = 0;

	int temp;
    
    
    while(cin >> N)
    {
              
              for( i = 0 ; i < N ; i++)
              {
                   cin >> arr[i];
              }
              
              while( 1)
              {
				  temp = 0;
                   for( j = 0 ; j < N -1 ; j++)
                   {
                        if( arr[j] > arr[j+1])
                        {
                            count++;
                            int tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
							temp++;
                        }
                   }
				   if( temp == 0)
					   break;
              }
              
              cout <<"Minimum exchange operations : "<<  count << endl;
              count = 0;
                   
            
              
    }
    
    
    
    return 0;
}
