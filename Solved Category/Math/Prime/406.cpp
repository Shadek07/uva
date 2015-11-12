#include<iostream>
#include<cmath>
using namespace std;

bool p[1000];
int save[1000];

int prime(int n)
{
    
    
    if( n %2 == 0) return 0;
    int r = sqrt(n);
    for(int i = 3; i <= r; i+= 2)
    if( n%i == 0 ) return 0;
    
    return 1;    
}

int main(void)
{

	int n,c,i,j,k,l;
	int ind = 0;

	memset(p,false,sizeof(p));

	p[1] = true;
	p[2] = true;

	ind  = 2;
	save[0] = 1;
	save[1] = 2;

	for( i = 3; i <= 1000; i++)
	{
		if(prime(i))
		{
			p[i] = true;
			save[ind++] = i;
		}
	}

	while(cin >> n >> c)
	{
		l = 0;
		
		for( i = n; i > 0; i--)
		{
             if(p[i])
				 l++;
		}

		

		if( l %2 == 0)
		{
			j = 2*c;
			k = (l - j)/2;

			cout << n << " " << c << ":" ;
			if( j < l )
			{
				for( i = k; i < k + j; i++)
				{
					 if( i < k-1 +j)
						 cout << " " << save[i] ;
					 else
						 cout << " " << save[i] << endl;
				}
			}
			else
			{
				for( i = 0; i < l; i++)
				{
					if( i < l-1)
						cout << " " << save[i] ;
					else
						cout << " " << save[i] << endl;

				}
			}
		}
		else
		{
			j = 2*c - 1;
			k = (l - j)/2;

			cout << n << " " << c << ":" ; 
			if( j < l )
			{
				for( i = k; i < k + j; i++)
				{
					 if( i < k-1 +j)
						 cout << " " << save[i] ;
					 else
						 cout << " " << save[i] << endl;
				}
			}
			else
			{
				for( i = 0; i < l; i++)
				{
					if( i < l-1)
						cout << " " << save[i] ;
					else
						cout << " " << save[i] << endl;

				}
			}

		}


        cout << endl;

	}

    

	return 0;
}