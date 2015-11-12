#include<iostream>
using namespace std;
#define max 9999.9

int main(void)
{
	double x1[10],x2[10],y1[10],y2[10];
	double x,y;
	int i,j,k = 1;
	int check;
	
	i = 0;
	while(1)
	{
		char c = getchar();
		if(c == '*')
			break;
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		i++;
		getchar();
	}

	while(1)
	{
		cin >> x >> y;
		if( x == max && y == max)
			break;
		check = 0;
		for( j = 0; j < i; j++)
		{
              if((x > x1[j] && x < x2[j]) && (y < y1[j] && y > y2[j]))
			  {
				  cout << "Point " << k << " is contained in figure " << j+1 << endl;
				  check = 1;
			  }
		}

		if( check == 0)
		{
              cout << "Point " << k << " is not contained in any figure\n";
		}

		k++;
	}

	return 0;
}