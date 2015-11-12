#include<iostream>

using namespace std;

int sum_of_digit(long int num);


int main()
{
	long int num;

     long int val;


	cin >> num;

	while(num)

	{
		
       val = sum_of_digit(num);

	   if(val>9)
	   {
		   while(val >9)
		   {
			   val = sum_of_digit(val);
		   }

		   cout << val << endl;
	   }

	   else

		   cout << val << endl;

	   cin >> num;


	}

	return 0;

}


int sum_of_digit(long int num)
{
	int sum = 0;

	int d;

	d = num % 10;

	num = num/10;

	sum = sum + d;

	while(num>0)
	{
		d = num % 10;

		sum = sum + d;

		num = num/10;
	}

	return sum;
}


