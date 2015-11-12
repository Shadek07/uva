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
	int N,i,j;
    long int res;
	while(1)
	{
		cin >> N;
		if(!N)
			break;
		res = 0;
		for(i = 1; i <N; i++)
		{
			for( j  = i+1; j <=N; j++)
			{
				res += gcd(i,j);
			}
		}

		cout << res << endl;
	}

	return 0;
}