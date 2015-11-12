#include<iostream>

using namespace std;

int palindrome(long int num);

long int reverse_num(long int num);



long int power(int k);

int palind_check[10];

int main()
{
	int cases;

	int c;

	int occurence = 0;

    long	int num;

	cin >> cases;
	

	

	while(cases)

	{
		
		cin >> num ;

		c = palindrome(num);

		if( c == 1)
		{
			cout << occurence << " ";

			cout << num;
		}

		else
		{
			
			num += reverse_num(num);

			occurence++;

			c = palindrome(num);

			while(c == 0)
			{
				num += reverse_num(num);

				c = palindrome(num);
				
			//	cout << "abc";  // for nothing

				occurence++;
			}
            

			cout << occurence << " ";

			cout << num << endl;
		}

		occurence = 0;

		cases--;

		
	}



return 0;

	

	
}

int palindrome(long int num)
{

	int b;

	
	int i = 0;

	long int c = num;

	c += reverse_num(num);

	if( c != (2*num) )
	{
		b = 0;
		return b;
	}

   
    else
	{
		b = 1;

	    return b ;
	}

}

long int reverse_num(long int num)
{
	int k = 0;

	long int q = num;

    long	int get_val;

    long	int sum = 0;

	int d;

	while(q)
	{
		q /= 10;

		k++;
	}


  
	while(k >= 2 ) //num
	{
		d = num % 10;

		get_val = power(k-1);

		sum +=  (d * get_val);

		num /= 10;

		k--;
	}

	d = num % 10;

	sum += d; 



	return sum;
}

long int power(int k)
{
    long int b = 10;

	for(int i = 0; i < k - 1;i++)
	{
		b *= 10;
	}

	return  b;
}












