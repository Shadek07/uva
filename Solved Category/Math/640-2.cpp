#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
using namespace std;

int arr[1000005];
int get(int n)
{
	int sum;
	sum = 0;
	while(n)
	{
		sum += n%10;
		n /= 10;
	}

	return sum;
}

int main(void)
{

	int a,b;
	int i,j,k;

//	ifstream f1("1.txt");
//	ofstream f3("2.txt");

	for(i = 1; i <= 1000000;i++)
	{
		arr[i] = -1;

	}

	for(i = 1; i <= 1000000;i++)
	{
		a = i + get(i);
		arr[a] = 1;

	}

	int count = 0;

	for(i = 1; i <= 1000000;i++)
	{
		if(arr[i] == -1)
		{
			cout << i << endl;

		}
		


	}

	//f1 >> a >> b;

	//f3 << a+b << endl;

	
	


	return 0;
}