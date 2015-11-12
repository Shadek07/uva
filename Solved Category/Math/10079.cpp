#include<iostream>
using namespace std;
int main()
{
	int x;
	for(;scanf("%d", &x)==1;)
	{
		long i,a=0;
		if(x<0)
		break;

		else
		for(i=x;i>0;--i)
		{
			a= i + a;
		}
		printf("%ld\n",a+1);
	}
}


  