#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{

	int t;

	unsigned char c;
	char in[100000];

	unsigned long int cents;

	bool check[300];
	int val[300];

	int kar,i,j,k,l,v;

	cin >> t;

	while(t--)
	{
		memset(check,false,sizeof(check));
		memset(val,0,sizeof(val));

		cin >> kar;

		getchar();

		for(i = 0; i < kar; i++)
		{
             c = getchar();
			 cin >> v;
			 getchar();
			 
			 check[int(c)] = true;
			 val[int(c)] = v;
		}
		int line;
		cin >> line;

		getchar();

		cents = 0;

		for( i = 0 ; i < line; i++)
		{
              gets(in);

			  int len = strlen(in);

			  for( j = 0; j < len; j++)
			  {
				  if( check[int(in[j])] == true)

					  cents += val[int(in[j])];

			  }
		}

		cout << cents/100 << "." ;
		printf("%02ld$\n",cents%100);

	}




	return 0;
}