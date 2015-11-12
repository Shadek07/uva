#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double m,n;

int bin_search(void);

int power[100];

int cnt;

int main(void)
{

	int i;

	while(cin >> m >> n)
	{
		
		if( m < 2.0 || n < 2.0 || m < n)
		{
			cout << "Boring!\n";
			continue;

		}
		int boring = false;

		int m1 = m;
		int n1 = n;
		 while ( m1 > 1 ) {
            if ( m1 % n1 == 0 ) ;
            else boring = true;
            m1 /= n1;
        }

		 if(boring == true)
		 {
			 
			cout << "Boring!\n";
			continue;

		 }


		/*if(!bin_search())
		{
			cout << "Boring!\n";
		}*/
		else
		{
			int t1 = m;
			cout << t1 ;

			while(t1 >= n)
			{
				t1 /= n;
				cout << " " << t1;
			}
			cout << endl;

		}

	}

	return 0;
}

int bin_search(void)
{
	int low,high,mid;
	double res;
	low = 0;
	high = 31;

	while(low <= high)
	{
		mid = (low+high)/2;

		res = pow(n,mid*1.0);

		power[(int)mid] = res;

		if( res > m)
		{
			high = mid-1;
		}
		else if( res < m)
		{
			low = mid+1;
		}
		else
		{
			  cnt =  mid;
              return 1;
		}
		
	}

	return 0;

}