#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v1;
#define max 25
#define MAX 20000
#define MYMAX(x,y) ((x>y?x:y));
long int check[1000];
int main()
{

long int C[max][MAX],i,N,MW,w,Wi[MAX],Vi[MAX],k;
long int T_cost=0;


while(scanf("%d",&MW) == 1)
{
	scanf("%d",&N);

	memset(check,0,sizeof(check));

	for(i=1;i<=N;++i)
	{ 
		scanf("%d",&Wi[i]);
		Vi[i] = Wi[i];
	}

	T_cost=0;

	for (i=0;i<=N ;i++)
		C[i][0] = 0;
	for (w=0;w<=MW;w++) 
		C[0][w] = 0;

	long int one,two;

	for (i=1;i<=N;i++)
		for (w=1;w<=MW;w++) 
		{
			if (Wi[i] > w)
			{
				C[i][w] = C[i-1][w];
				
			}
			else
			{
				one = C[i-1][w];
				two = C[i-1][w-Wi[i]]+Vi[i];
				if(one > two)
				{
					C[i][w] = one;
					
				}
				else
				{
					C[i][w] = two;
					
				}
			}
		}

		T_cost+=C[N][MW];


		long int out = 0;

		/*printf("%d\n",T_cost);*/

		if(T_cost == 0)
			continue;

		i = N;
		k = MW;

		while(i> 0 && k > 0)
		{
			if(C[i][k] != C[i-1][k])
			{
				check[i] = 1;
				v1.push_back(Wi[i]);
				i = i-1;
				k = k - Vi[i+1];
			}
			else
			{
				check[i] = 0;
				i = i-1;				
			}
		}

		int sz = v1.size();

		sort(v1.begin(),v1.end());


		for(i = 0; i < sz; i++)
		{							
			printf("%d ",v1[i]);			
		}

		
		printf("sum:%d\n",T_cost);
		
		T_cost=0;

		v1.clear();

	}
	
	return 0;
}