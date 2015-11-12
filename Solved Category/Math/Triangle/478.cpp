#include<iostream>
using namespace std;
#define max 9999.9

int main(void)
{
	double x1[10],x2[10],y1[10],y2[10];
	int r_c[10];
	double x,y,a[10],b[10],c[10],d[10],e[10],f[10],k,l,m,n,o,p,a1,b1,c1;
	int i,j,t = 1;
	int check;
	
	i = 0;
	while(1)
	{
		char r1 = getchar();
		if(r1 == '*')
			break;
		if(r1 == 'r')
		{
			r_c[i] = 1;
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		}
		else if( r1 == 'c')
		{
			r_c[i] = 2;
			cin >> x1[i] >> y1[i] >> x2[i];
		}
		else
		{
			r_c[i] = 3;
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i];
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
			if( r_c[j] == 1)
			{
              if((x > x1[j] && x < x2[j]) && (y < y1[j] && y > y2[j]))
			  {
				  cout << "Point " << t << " is contained in figure " << j+1 << endl;
				  check = 1;
			  }
			}
			else if( r_c[j] == 2)
			{
				a1  = (x-x1[j])*(x-x1[j]);
				b1 = (y-y1[j])*(y-y1[j]);
				c1 = x2[j]*x2[j];
				if( a1 + b1 < c1)
				{
					cout << "Point " << t << " is contained in figure " << j+1 << endl;
				    check = 1;
				}

			}
			else
			{
				k = e[j]*(b[j]-d[j]) + f[j]*(c[j]-a[j]) + a[j]*d[j] - b[j]*c[j];
				l = x*(b[j]-d[j]) + y*(c[j]-a[j]) + a[j]*d[j] - b[j]*c[j];

				m = a[j]*(f[j]-d[j]) + b[j]*(c[j]-e[j]) + e[j]*d[j] - f[j]*c[j];
				n = x*(f[j]-d[j]) + y*(c[j]-e[j]) + e[j]*d[j] - f[j]*c[j];

				o = c[j]*(b[j]-f[j]) + d[j]*(e[j]-a[j]) + a[j]*f[j] - b[j]*e[j];
				p = x*(b[j]-f[j]) + y*(e[j]-a[j]) + a[j]*f[j] - b[j]*e[j];

				if ((k/l>=0) && (m/n>=0) && (o/p>=0))
				{
					cout << "Point " << t << " is contained in figure " << j+1 << endl;
				    check = 1;

				}
			}
		}

		if( check == 0)
		{
              cout << "Point " << t << " is not contained in any figure\n";
		}

		t++;
	}

	return 0;
}