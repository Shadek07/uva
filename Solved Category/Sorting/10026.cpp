#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char in[1000][100],c;

struct DNA
{
	int day;
	int fine;

	int ind;
};

bool comp(DNA a, DNA b)
{
	if(a.day*b.fine < b.day*a.fine)
		return true;
	else
		return false;
	
}

struct DNA D[1000000];

int main(void)
{

	int dataset;

	int total,i,j,k;
	

	int bla = 0;

	cin >> dataset;

	getchar();
	getchar();

	while(dataset--)
	{
		cin >>  total;

		getchar();

		for( i = 0; i < total; i++)
		{
			cin >> j >> k;
			D[i].day = j;
			D[i].fine = k;
			D[i].ind = i + 1;
		}

		
         getchar();
		
		sort(D,D + total,comp);

		if(bla == 1)
			cout << "\n";
		else
			bla = 1;



		cout << D[0].ind;

		for( i = 1 ; i < total; i++)
		{
			cout << " " << D[i].ind;
		}


		cout << "\n";

        //if(dataset > 0)
		//getchar();
	}


	return 0;
}