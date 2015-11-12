#include<iostream>

using namespace std;

int main(void)
{

	int n,m,i,j;

	int one,two,three;

	int max;

	int check2,check3;

	while(cin >> n)
	{
		check2 = 0;
		check3 = 0;
		one = 0;
		two = 0;
		three = 0;
		one = n;
		m = n;
		while(m>=3)
		{
			i=m%3;	
			one+=m/3;
			j=m/3;			
			m=i+j;
		}

		

		two = n;

		m = n+1;

		while(m>=3)
		{
			i=m%3;		
			two+=m/3;
			j=m/3;			
			m=i+j;
		}

		

		if(m == 1)
		{
			check2 = 1;
		}

		three = n;

		m = n+2;

		while(m>=3)
		{
			i=m%3;		
			three+=m/3;
			j=m/3;			
			m=i+j;
		}

		

		if(m == 2)
		{
			check3 = 1;
		}

		max = one;

		if( check2)
		{
			if(two > max)
				max  =two;
		}

		if( check3)
		{
			if( three > max)
				max = three;
		}

		cout << max << endl;

	}


	return 0;
}