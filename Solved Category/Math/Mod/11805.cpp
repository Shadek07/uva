#include<iostream>

using namespace std;

int main(void)
{

	int t;
	int a,b,c,d = 1,e;

	cin >> t;

	while(t--)
	{
		cin >> a >> b >> c;

		e = b+c;

		e = (b+c)%a;

		if( e != 0)

		cout << "Case " << d++ << ": " << (b+c)%a << endl;

		else
		{
			cout << "Case " << d++ << ": " << a << endl;
			
		}
	}


	return 0;
}