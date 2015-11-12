#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 10005


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

}tot[10005];

int compare( ele a,  ele b)
{
	return a.s > b.s;
}

int pred[10005];
int length[10005];
int cost[10005];

unsigned long int inc,dc;

void print(int i)
{
	if(pred[i] != -1)
	{
		print(pred[i]);
		inc += tot[i].s;
		//cout << tot[i].s << " ";
	}
	else
	{
		inc += tot[i].s;
		//cout << tot[i].s << endl;
	}
}

void print1(int i)
{
	if(pred[i] != -1)
	{
		print1(pred[i]);
		dc += tot[i].s;
		//cout << tot[i].s << " ";
	}
	else
	{
		dc += tot[i].s;
		//cout << tot[i].s << endl;
	}
}

int main(void)
{

		int w1,s1;

		int i = 0,j;
		int total;
		int i1;
		i1 = 9;
		int ind;
		int t;
		int ca = 1,n;

		cin >> t;

		while(t--)
		{
				cin >> n;

				for(i = 0; i < n; i++)
				{
					scanf("%d",&w1);
					tot[i].w = w1;

				}
				for(i = 0; i < n; i++)
				{
					scanf("%d",&s1);
					tot[i].s = s1;
					tot[i].d = i+1;

				}
			

				ind = i;

				//sort(tot,tot+i,compare);

				inc = dc = 0;
				total = n;

				for(i = 0; i < total; i++)
				{
					length[i] = 1;
					cost[i] = tot[i].s;
					pred[i] = -1;
				}



				//for Increasing

				for(i = 0;i< total-1; i++)
				{
					for(j = i+1; j < total; j++)
					{
						if(tot[j].w > tot[i].w)
						{

							/*if(length[i] + 1 > length[j])
							{
								length[j] = length[i] + 1 ;
								cost[j] = cost[i] + tot[j].s;
								pred[j] = i;
							}*/
							if(cost[i] + tot[j].s > cost[j])
							{
								cost[j] = cost[i] + tot[j].s;
								pred[j] = i;
							}
						}
					}
				}

				
				
				int max = cost[0];
				
				for(i = 1; i < total; i++)
				{
					
					if(cost[i] > max)
					{
						max =  cost[i];
						ind = i;
					}
				}

				//cout << length[ind] << endl;
				int mx = max;
				print(ind);

				//for Decreasing

				for(i = 0; i < total; i++)
				{
					length[i] = 1;
					cost[i] = tot[i].s;
					pred[i] = -1;
				}



				for(i = 0;i< total-1; i++)
				{
					for(j = i+1; j < total; j++)
					{
						if(tot[j].w < tot[i].w)
						{

							/*if(length[i] + 1 > length[j])
							{
								length[j] = length[i] + 1 ;
								cost[j] = cost[i] + tot[j].s;
								pred[j] = i;
							}*/
							if(cost[i] + tot[j].s > cost[j])
							{
								cost[j] = cost[i] + tot[j].s;
								pred[j] = i;
							}
						}
					}
				}

				
				
				max = cost[0];
				
				for(i = 1; i < total; i++)
				{
					/*if(length[i] > max)
					{
						max = length[i];
						ind = i;
					}*/
					if(cost[i] > max)
					{
						max =  cost[i];
						ind = i;
					}
				}

				//cout << max << endl;
				print1(ind);

				cout << "Case " << ca++ << ". ";
				if(mx >= max)
				{
					cout << "Increasing (" << mx << "). Decreasing (" << max << ").\n";
				}
				else
				{
					cout << "Decreasing (" << max << "). Increasing (" << mx << ").\n";

				}


		}
			

    
    
    
    
    return 0;
}


