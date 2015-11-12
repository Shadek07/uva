#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{

	int x,y,a,b;
	//int i,j,k;

	while(1)
	{
		cin >> x >> y >> a >> b;

		if(!x && !y && !a && !b)
			break;

		if(x == a && y == b)
			cout << 0 << endl;
		else if( ( abs(a-x) == abs(b-y) ) || (x == a) || (y == b))
		{
			cout << 1 << endl;
			
		}
		else
			cout << 2 << endl;
	}


	return 0;
}