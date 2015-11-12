#include<iostream>

using namespace std;

int main(void)
{

	int num,from;
	int i,j,k,a,b;

	int cigerrete;
	int total;

	while(cin >> num >> from)
	{
		total = 0;
        total=num;
		while(num>=from)
		{
		i=num%from;
		
		total+=num/from;
		j=num/from;
		
		num=i+j;

		}
		cout<<total<<endl;



	}


	return 0;
}