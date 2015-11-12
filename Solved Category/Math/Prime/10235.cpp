#include<iostream>
#include<cmath>

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

	int num,j,a;
	int p1,p2;

	while((scanf("%d",&num)) == 1)
	{
		a = num;
		j = 0;
		p1 = prime(a);

		while(a)
		{
			j = j*10 + (a%10);
			a /= 10;
		}

		p2 = prime(j);

		if(!p1)
		{
			cout << num << " is not prime.\n";

		}
		else
		{
			if(p2 && (j != num))
			{
			  cout << num << " is emirp.\n";
			}
			else
			{
				cout << num << " is prime.\n";

			}

		}

		
		

	}

	return 0;

}

