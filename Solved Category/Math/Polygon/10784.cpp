#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(void)
{
	long double e;
	long int d,h;
	int ca = 1;
	while(1)
	{
		cin >> d;
		if(d == 0)
			break;
		
		e = 8.0*d + 9;
		e = sqrt(e);
		e += 3.0;
		e /= 2.0;
		h = ceil(e);
		cout << "Case " << ca++ << ": " << h << endl;


	}
	return 0;
}