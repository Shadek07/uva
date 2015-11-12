#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    int c;

	if( a < b)
	{
		c = a;
		a = b;
		b = c;
	}

    while(1)
    {
  		c = a%b;
  		if(c==0)
  		  return b;
  		a = b;
  		b = c;
    }
}

int main(void)
{

	int step,mod;
	int check = 1;

	while(cin >> step >> mod)
	{
		
             int a = gcd(step,mod);

			 if(a == 1)

             printf("%10d%10d    Good Choice\n\n",step,mod);
			
			 else
             printf("%10d%10d    Bad Choice\n\n",step,mod);
		
	}


	return 0;
}