#include<iostream>

using namespace std;

int main(void)
{
    
    long long int i,j,k,l;

	

     while( cin >> i)
	 {

			k = (i-2)/2 + 1;

		//	l = k*k ;  // 1 + 3 + 5 + .....+ n = n^2


			l = 2*k*k - 1;  //last number of the previous line

			l = l + (i*2); //last number of the input line

		//	l = l + (l-2) + (l - 4);
		
		    l = 3*l - 6;

			cout << l << "\n";

			
	 }





	return 0;

}
