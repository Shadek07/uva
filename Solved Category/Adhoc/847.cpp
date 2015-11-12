#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(void)
{

	long int n,num;
	int turn = 1;

	while(scanf("%ld",&n) == 1)
	{
		num = 1;
		turn = 1;
		while(num < n)
		{
			if(turn == 1)
			{
				num *= 9;
				turn = 0;
			}
			else
			{
				num = num << 1;
				turn = 1;
			}
		}

		if(turn == 1)
		{
			cout << "Ollie wins.\n";
		}
		else
		{
			cout << "Stan wins.\n";
		}
	    
	}

	return 0;
}