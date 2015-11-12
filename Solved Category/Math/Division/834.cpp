#include<iostream>

using namespace std;

int main()
{
	int numerator,denomerator;

	 while( cin >> numerator >> denomerator) 
	 {


		if(numerator == 1)

		{
			cout << "[" ;

			cout << 0<< ";" << "" << denomerator << "]";

			cout << endl;
		}

		else
		{

		
			cout << "[";
			cout << numerator / denomerator << ";"<< "" ;

			int d = numerator % denomerator;

			while( d  != 1)

			{
				
				
				numerator = denomerator;

				denomerator = d;
				
				cout << numerator / denomerator << "" << ",";
				
				
				d = numerator % denomerator;
			}

			cout << denomerator;

			cout << "]" << endl;
		}
	 }


	return 0;
}


		
		




