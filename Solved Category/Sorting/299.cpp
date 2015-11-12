#include<iostream>

using namespace std;

int main(void)
{
    
     int N;
     int t;
     int arr[100];
     int i,j,count = 0;
    cin >> t;
    
    while(t--)
    {
              cin >> N;

              for( i = 0 ; i < N ; i++)
              {
                   cin >> arr[i];
              }
              
              for( i = 0 ; i < N - 1 ; i++)
              {
                   for( j = 0 ; j < N - i-1 ; j++)
                   {
                        if( arr[j] > arr[j+1])
                        {
                            count++;
                            long int tmp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = tmp;
                        }
                   }
              }
              
              cout <<"Optimal train swapping takes "<<  count << " swaps.\n";
              count = 0;
                   
                   
                   
                   
                   
                   
                   
              
              
    }
    
    
    
    return 0;
}
