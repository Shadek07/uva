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
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)


typedef pair<int,int> pa;
vector<pa> v1;
#define max 35
#define MAX 20000
#define MYMAX(x,y) ((x>y?x:y));
long int check[1000];

int main()
{

	long int C[max][MAX],i,N,MW,w,Wi[MAX],Vi[MAX],k,w1;
	long int T_cost=0;
	pa p1;
	int ch = 0;

	while(scanf("%d %d",&MW,&w1) == 2)
	{
		scanf("%d",&N);

		memset(check,0,sizeof(check));

		for(i=1;i<=N;++i)
		{ 
			scanf("%d %d",&Wi[i],&Vi[i]);
			Wi[i] = 3*w1*Wi[i];
		}

		T_cost=0;

		for (i=0;i<=N ;i++)
			C[i][0] = 0;
		for (w=0;w<=MW;w++) 
			C[0][w] = 0;

		long int one,two;

		for(i=1;i<=N;i++)
			for (w=1;w<=MW;w++) 
			{
				if(Wi[i] > w)
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

			T_cost=C[N][MW];			

			i = N;
			k = MW;

			while(i> 0 && k > 0)
			{
				if(C[i][k] != C[i-1][k])  //i'th item is taken
				{
					p1.first = Wi[i]/(3*w1);
					p1.second = Vi[i];
					v1.push_back(p1);
					k = k - 3*w1*p1.first;
				}
				
				i = i-1;				
				
			}

			int sz = v1.size();

			reverse(v1.begin(),v1.end());

			if(ch==0)
				ch = 1;
			else
				cout << endl;
			cout << T_cost<<endl;
			cout << sz << endl;
			for(i = 0; i < sz; i++)
			{							
				cout << v1[i].first << " " << v1[i].second << endl;			
			}

			v1.clear();

		}
	
	return 0;
}
