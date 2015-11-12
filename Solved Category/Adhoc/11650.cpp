#include<iostream>
using namespace std;

int main(void)
{
	int mapp[] = {11,10,9,8,7,6,5,4,3,2,1,12};
	int t;
	int H,M,h,m;
	
	cin >> t;
	while(t--)
	{
		cin >> H ;
		getchar();
		cin >> M;
		h = mapp[H-1];
		if( M == 0)
		{
			m = 0;
		}
		else
		{

			m = M/5;
			if(M%5 != 0)
			m++;
			m *= 5;

			m = 60 - m;

			if(M%5 != 0)
			m += (5-M%5);
		}
		
	
		if( M > 0)
			h--;
		if( h == 0)
			h = 12;

		
		if( h >= 1 && h <= 9)
			cout << "0" << h << ":";
		else
            cout  << h << ":";
		if( m == 0)
		{
			cout << "00" << endl;
			goto level;
		}
		if( m >= 1 &&  m <= 9)
			cout << "0" << m << endl;
		else
			cout  << m << endl;
level:;


	}
	return 0;
}

