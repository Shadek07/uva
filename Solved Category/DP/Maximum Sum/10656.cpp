#include <iostream>
#include<cstdio>
using namespace std;
int *p,size;
int main()
{

	int t;
	int r = 1;

	int check = 0;

	int start;
	

	while(cin>>size)
	{

		if(size == 0)
			break;

		check = 1;

		start = 1;
		
		
		int i;
		p=new int[size];
		for(i=0;i<size;i++)
		{
			cin>>p[i];
		}

		for(i = 0; i < size; i++)
		{
			if(p[i] > 0 && start)
			{
				cout << p[i];
				check = 0;
				start = 0;

			}
			else if(p[i] > 0 && start == 0)
			{
				cout << " " << p[i];
				check = 0;
			}
		}
		if(check == 1)
		{
			cout << 0;
		}

		cout << endl;
	
	

		delete p;
	}

	return 0;
}




