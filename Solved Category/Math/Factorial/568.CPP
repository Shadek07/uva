#include<iostream>
using namespace std;
int main()
{
	long int tmp=1; //temporary tens and units digit data
	long int i;
	long int input,result;


	while(scanf("%d",&input)==1)
	{
		tmp = 1;

		for(i=2;i<=input;i++)
		{
			tmp*=i;
			while(tmp%10==0)
			tmp/=10;
			tmp%=100000;
		}

		result=tmp%10;

		printf("%5d -> %d\n",input,result);
	}

	return 0;
}