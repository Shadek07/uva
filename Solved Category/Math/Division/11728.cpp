#include<iostream>
using namespace std;

int main(void)
{

	int ca = 1,check;
	int num,i,j,k;

	while(1)
	{
		cin >> num;
		if(!num)
			break;
		k = 0;
		check = 0;
		for( j = num; j > 0 ; j--)
		{
			k = 0;
			for(i = j; i>0; i--)
			{
				if(j%i == 0)
					k += i;
			}
			if( k == num)
			{
				cout << "Case " << ca++ << ": " << j << endl;
				check = 5;
				break;
			

			}
		}

		if( check == 0)
		{
			cout << "Case " << ca++ << ": " << -1 << endl;

		}
	}

	return 0;
}