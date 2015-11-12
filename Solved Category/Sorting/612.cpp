#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char in[1000][100],c;

struct DNA
{
	int sort_measure;
	int index;
};

int comp(DNA a, DNA b)
{
	if(a.sort_measure == b.sort_measure)
		return a.index < b.index;
	else
	    return a.sort_measure < b.sort_measure;
}

struct DNA D[1000];

int main(void)
{

	int dataset;

	int length,total,i,j,k,l;

	int bla = 0;

	cin >> dataset;

	getchar();
	getchar();

	while(dataset--)
	{
		cin >> length >> total;

		getchar();

		for( i = 0; i < total; i++)
		{
			gets(in[i]);
		}

		int count;

		for( i =0; i < total; i++)
		{
			count = 0;

			for( j =0; j < length - 1; j++)
			{
			      for( k = j+1; k < length; k++)
				  {
					  if( in[i][j] > in[i][k])
						  count++;
				  }
                 
			}

			D[i].index = i;
			D[i].sort_measure = count;
		}

		sort(D,D + total,comp);

		if(bla == 1)
			cout << "\n";
		else
			bla = 1;

		for( i =0 ; i < total; i++)
		{
			cout << in[D[i].index]<< endl;
		}

        if(dataset > 0)
		getchar();
	}


	return 0;
}