#include<iostream>
#include<cmath>

using namespace std;


int main()
{
    
	int arr[500];

	int min[500];

	int testcases;

	int Min_Sum = 0;

     int num;
	 cin >>testcases;

	while(testcases--)
	{
                      
                      
    	cin >> num;
    
    	
    
    	for(int i = 0;i < num;i++)
    
    	{
    		
    
    		cin >> arr[i];
    
    	}


		for(int k = 0;k < num;k++)
		{
			int sum =0;

			for(int j = 0;j<num;j++)
			{
                    
				if(j!= k)
				{

	
                    sum = sum +abs(arr[k] - arr[j]);
					
					
					
				}
				
				
		     }

			min[k] = sum;
		}

			    Min_Sum = min[0];


				for(int m = 0;m<num;m++)
				{
					if(Min_Sum > min[m])
					{
						Min_Sum = min[m];
					}
				}

		cout << Min_Sum <<endl;

		

		
		Min_Sum  = 0;

	}

	return 0;
}


