#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int prime(int n)
{
    
    if( n == 1) return 0;
    if( n %2 == 0) return 0;
    int r = sqrt(n);
    for(int i = 3; i <= r; i+= 2)
    if( n%i == 0 ) return 0;
    
    return 1;
    
    
}

int main(void)
{
	int n;
    int i,j;
	while(cin >> n)
	{
		if(  n < 8)
		{
            cout << "Impossible.\n";
			continue;
		}
		if( n == 8)
		{
			cout << "2 2 2 2\n";
			continue;
		}
		
		else
		{
		     
			if( n %2 == 1)
			{
				cout << "2 3 ";
				j = n-5;
				if( j == 8)
				{
					cout << "2 2 2 2\n";
					continue;
				}
				if( j == 4)
				{
					cout << "2 2\n";
					continue;
				}
				for( i = 3 ; i <= j/2; i += 2)
				{
					 if( prime(i) && prime(j-i))
					 {
						 cout << i << " " << j-i << endl;
						 break;
					 }
				}
			}
			else
			{
				 cout << "2 2 ";

				 j = n-4;

				 	if( j == 8)
				{
					cout << "2 2 2 2\n";
					continue;
				}
				if( j == 4)
				{
					cout << "2 2\n";
					continue;
				}
				 
				 for( i = 3 ; i <= j/2; i += 2)
				 {
					 if( prime(i) && prime(j-i))
					 {
						 cout << i << " " << j-i << endl;
						 break;
					 }
				 }
			}
		}
	}

	return 0;
}

