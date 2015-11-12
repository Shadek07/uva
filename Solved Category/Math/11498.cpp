#include<iostream>

using namespace std;

int main(void)
{
	int n;

	int x,y,a,b,i;

	while(cin >> n && n)
	{

		cin >> x >> y;

         for( i = 0;i<n;i++)
		 {
			 cin >> a >> b;

			 a -= x;
			 b -= y;

			 if(a == 0 || b == 0)
				 cout << "divisa\n";
			 else if( a > 0 && b > 0)
				 cout << "NE\n";
			 else if( a < 0 && b > 0)
				 cout << "NO\n";
			 else if( a > 0 && b < 0)
				 cout << "SE\n";
			 else
				 cout << "SO\n";
		 }
		

	}


	return 0;
}