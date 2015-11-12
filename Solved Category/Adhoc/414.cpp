#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main( void)
{

	char in[20][36] ;

	int most[20][2] = {0} ;

	int check = 0,check1 = 0;
	int array[] = {1,2,1,2,3};
     
	int cnt[20];

	int row ;

	int i,j;

	int min;

	int sum;
	int my ;

	while(1)
	{
		cin >> row ;

		getchar();

		if(!row) break;

		memset(cnt,0,sizeof(cnt));

        for( i = 0; i < row ; i++)
		{

            gets(in[i]);
			
			

          my = (int) count (in[i],in[i]+25,' ');
			

             cnt[i] = my;
			


		}

		min = 30;

		sum = 0;

		for(i = 0; i < row; i++)
		{
			if(cnt[i] < min)
				min = cnt[i];
		}

		for(i = 0; i < row; i++)
		{
			if(cnt[i] > min)
				sum += (cnt[i] - min);
		}

	    
		cout << sum << endl;

	}


	return 0;
}
