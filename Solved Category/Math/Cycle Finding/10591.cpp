#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

set<int> s1;

int digit_square_sum(int n)
{
	int d,c;

	d =0;
	while(n > 0)
	{
		c = n%10;
		d += c*c;
		n /= 10;
	}

	return d;
}

int main(void)
{

	long int n,a,cn= 1,ini,last;

	
	
	int check;
	int t;

	cin >> t;

	while(t--)
	{
		cin >> n;
        check = 1;
		a = n;
		if(a == 1)
		{
				cout << "Case #" << cn++ << ": "<< n << " is a Happy number.\n";
				 continue;

		}

		s1.insert(a);

        while(1)
		{

			    ini = s1.size();
			    a = digit_square_sum(a);
				if(a == 1)
				{
					cout << "Case #" << cn++ << ": "<< n << " is a Happy number.\n";
						break;

				}
				s1.insert(a);
				last = s1.size();
				if(ini == last)
				{
					cout << "Case #" << cn++ << ": "<< n << " is an Unhappy number.\n";
				 break;

				}
			
		}

		s1.clear();

	}


	return 0;
}