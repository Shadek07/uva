#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 1000


/*10 20
11 20
9 20
20 30
21 30
19 30
1 100
^Z
3
7
4
5*/



struct ele
{
	int w;
	int s;
	int d;

}tot[1005];

int compare( ele a,  ele b)
{
	return a.s > b.s;
}

int pred[1005];
int length[1005];

void print(int i)
{
	if(pred[i] != -1)
	{
		print(pred[i]);
		cout << tot[i].d << endl;
	}
	else
		cout << tot[i].d << endl;
}

int main(void)
{

		int w1,s1;

		int i = 0,j;
		int total;
		int i1;
		i1 = 9;
		int ind;

		while(scanf("%d %d",&w1,&s1) == 2)
		{
			
			tot[i].w = w1;
			tot[i].s = s1;
			tot[i].d = i+1;
			i++;

		}

		ind = i;

		sort(tot,tot+i,compare);

	
		total = i;

		for(i = 0; i < total+1 ; i++)
		{
			length[i] = 1;
			pred[i] = -1;
		}



		for(i = 0;i< total-1; i++)
		{
			for(j = i+1; j < total; j++)
			{
				if(tot[j].w > tot[i].w)
				{

					if(length[i] + 1 > length[j])
					{
						length[j] = length[i] + 1 ;
						pred[j] = i;
					}
				}
			}
		}

		
		
		int max = 0;
		
		for(i = 0; i < total; i++)
		{
			if(length[i] > max)
			{
				max = length[i];
				ind = i;
			}
		}
		cout << length[ind] << endl;
		print(ind);
	

    
    
    
    
    return 0;
}


