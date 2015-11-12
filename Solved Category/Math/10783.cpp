#include<iostream>

using namespace std;

int main(void)
{
	int i,j,k,t, m = 0;

	int term = 1;

	cin >> t;

	while(t)
	{
		cin >> i >> j;
		
		if( i %2 == 1 )
		{
            
            
            		for( k = i; k <= j ; k = k +1)
            		{
                         if( k%2 == 1)
                         
            			m += k;
            
            		}
        }
        else
        {
            
            
            		for( k = i; k <= j ; k = k + 1)
            		{
                         if( k%2 == 1)
            			m += k;
            
            		}
            
        }

		cout << "Case " << term << ": " << m << "\n";

        term++;
        
	    m = 0;
		t--;
	}


	return 0;
}
