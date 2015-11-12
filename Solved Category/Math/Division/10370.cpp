#include<iostream>

using namespace std;

int main(void)
{
	int t,t1;
	
	double c = 0;
    
	int i,k,m = 0,n = 0;

	double num;

	double p[1000];

	double per;

	double av  = 0;

	cin >> t;

   

	while( t)
	{
		cin >> num;

		//scanf("%ld", &num);

		for( i = 0 ; i < num; i++)
		{
			cin >> t1;

			//scanf("%ld",&t1);

			p[m] = t1;

			av += t1;

		//	if( (n+1) == 100 )

				m++ ;

		//	n = (n+1) % 100;

		}

		av /= num ;

		for( k = 0; k < num ; k++)
		{
			if( p[k] > av )

				c++;


		}

		per = (c/num)*100 ;

	//	cout << per << "%\n";

		printf("%.3lf",per);

		cout << "%";

		printf("\n");
			

		m = 0;
		n = 0;

		av = 0;

		c = 0;

		t--;
	}

        


	return 0;
}
