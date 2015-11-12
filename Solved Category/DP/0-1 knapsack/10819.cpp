
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
using namespace std;

#define row 101
#define col 10201
#define MYMAX(x,y) ((x>y?x:y));
int check[109];
int C[row][col],Wi[row],Vi[row];

struct item
{
	int wi;
	int vi;

}it[101];


int main()
{

	int i,N,MW,w,k;
	int expense[row][col];
	int tcase,T_cost=0,persons;
	long sum;

	//freopen("2.txt","w",stdout);

	while(scanf("%d %d",&MW,&N) == 2)
	{
		memset(check,0,sizeof(check));

		sum = 0;

		for(i=1;i<=N;++i)
		{ 
			cin >> it[i].wi;
			cin >> it[i].vi;			
		}

		T_cost=0;
		int one,two;

		for (i=0;i<=N ;i++)
		{
			C[i][0] = 0;
			expense[i][0] = 0;
		}
		for(w=0;w<=MW+200;w++)
		{
			C[0][w] = 0;
			expense[0][w] = 0;
		}

		

		for (i=1;i<=N;i++)
			for(w=1;w<=MW+200;w++) 
			{
				if(it[i].wi > w)
				{
					C[i][w] = C[i-1][w];
					expense[i][w] = expense[i-1][w];					
				}
				else
				{
					int x,y;
					one = C[i-1][w];
					x = expense[i-1][w];

					two = C[i-1][w-it[i].wi]+it[i].vi;					
					y = expense[i-1][w-it[i].wi]+it[i].wi;

					if(one > two && (x > 2000 || x <= MW))
					{
						C[i][w] = one;
						expense[i][w] = x;						
					}
					else
					{
						C[i][w] = two;
						expense[i][w] = y;						
					}
				}
			}

			int mx = -1;
			for(i = 1;i<= MW+200; i++)
			{
				if(C[N][i] > mx && expense[N][i] > 2000 && expense[N][i] <= MW + 200)
				{
					mx = C[N][i];
				}
				if(C[N][i] > mx && expense[N][i] <= MW)
				{
					mx = C[N][i];
				}

			}
			
			cout << mx << endl;
		   

		}
		return 0;
}