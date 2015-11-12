#include<iostream>
using namespace std;
#define max 9999.9

int main(void)
{
	double x1[10],x2[10],y1[10],y2[10];
	bool r_c[10];
	double x,y,a,b,c;
	int i,j,k = 1;
	int check;
	
	i = 0;
	while(1)
	{
		char c = getchar();
		if(c == '*')
			break;
		if(c == 'r')
		{
			r_c[i] = true;
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		}
		else
		{
			r_c[i] = false;
			cin >> x1[i] >> y1[i] >> x2[i];
		}
		
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
			if( r_c[j] == true)
			{
              if((x > x1[j] && x < x2[j]) && (y < y1[j] && y > y2[j]))
			  {
				  cout << "Point " << k << " is contained in figure " << j+1 << endl;
				  check = 1;
			  }
			}
			else
			{
				a  = (x-x1[j])*(x-x1[j]);
				b = (y-y1[j])*(y-y1[j]);
				c = x2[j]*x2[j];
				if( a + b < c)
				{
					cout << "Point " << k << " is contained in figure " << j+1 << endl;
				    check = 1;
				}

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