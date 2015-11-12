#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> v1;
#define max 35
#define MAX 20000
#define MYMAX(x,y) ((x>y?x:y));
long int check[1000];
int limit;
int main()
{

long int C[max][MAX],i,i1,N,MW,w,Wi[MAX],Vi[MAX],k;
long int T_cost=0;
int ca = 1;

int fin;
while(scanf("%d",&N) == 1)
{
	//scanf("%d",&N);

	memset(check,0,sizeof(check));

	fin = 0;

	for(i=1;i<=N;++i)
	{ 
		scanf("%d",&Wi[i]);
		Vi[i] = Wi[i];
		if(Wi[i] < 1 && Wi[i] > 1000)
			fin = 1;
		else if( i != 1 && Wi[i]  <= Wi[i-1])
			fin = 1;
	}

	if(fin == 0)
	{
		for(i1 = 2; i1 < N; i1++)
		{

				memset(check,0,sizeof(check));

				T_cost=0;

				MW = Wi[i1+1];

				for (i=0;i<=i1 ;i++)
					C[i][0] = 0;
				for (w=0;w<=MW;w++) 
					C[0][w] = 0;

				long int one,two;

				for (i=1;i<=i1;i++)
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

					T_cost+=C[i1][MW];

					//cout << T_cost << endl;
					
					/*i = i1;
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

					//sort(v1.begin(),v1.end());


					for(i = 0; i < sz; i++)
					{
						
							
							printf("%d ",v1[i]);
						
						
					}

					v1.clear();*/

					if(T_cost == MW)
					{
						//cout << "true: " << MW << endl;
						fin = 1;
						break;
					}
		}
	}

	cout << "Case #" <<ca++ << ":";

	for(i=1;i<=N;++i)
	{ 
		printf(" %d",Wi[i]);
		
	}
	cout << endl;

	if(fin)
	{
		cout << "This is not an A-sequence." << endl;
	}
	else
	{
		cout << "This is an A-sequence." << endl;

	}
	

	}
	
	return 0;
}