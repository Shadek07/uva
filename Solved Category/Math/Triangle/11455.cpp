#include<iostream>

using namespace std;

int main(void)
{

	int t;
	int a,b,c,d;
	int i,j,k,l;

	cin >> t;

	while(t--)
	{
		cin >> a >> b >> c >> d;

		if( (a == b)&&(b == c)&&(c == d))
		{
			cout << "square\n";
			continue;
		}
		if( (a == b &&  c == d)||(a == c &&  b == d)||(a == d &&  b == c))
		{
			cout << "rectangle\n";
				continue;

		}
		i = a+b+c;
		j = a+c+d;
		k = b+c+d;
		l = a+b+d;
		if(!((i < d)||(j<b) ||(k < a) ||(l < c)))
		{
			cout << "quadrangle\n";
			continue;

		}
		else
		{
			cout << "banana\n";
		}
	}


	return 0;
}