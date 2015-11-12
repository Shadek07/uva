#include<iostream>


using namespace std;

int main(void)
{

	char in[100];

	int i,num1,num2,res;
	int judge;

	int corr = 0;

	int opt;

	int len;

	while(gets(in))
	{

          len = strlen(in);

		  if(in[len-1] == '?')
			  continue;

		  num1 = num2 = res = 0;

		  i = 0;

		  while(!(in[i] == '+' || in[i] == '-'))
		  {
			  num1 = num1*10 + int(in[i]-48);
			  i++;
		  }

		  in[i] == '+'?opt=1:opt=2;

		  i++;

		  while(in[i] != '=' )
		  {
			  num2 = num2*10 + int(in[i]-48);
			  i++;
		  }

		  i++;

		  while(i < len)
		  {
			  res = res*10 + int(in[i]-48);
			  i++;

		  }

		  if(opt == 1)
		  {
			   judge = num1 + num2;
		  }
		  else
		  {
			  judge = num1 - num2;
		  }

		  if( judge == res)
			  corr++;

		  

	}

	cout << corr << endl;

	return 0;
}