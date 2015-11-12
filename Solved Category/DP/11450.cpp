#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define max(a,b) (a>b)?a:b
int item[21][21];
int budget,num;
int each[21];
#define inf 100000
int save[22][210];

int solve(int index,int money)
{
	int i;
	int maxi,a;
	int ch = 1;
	
	if(index == num && money >= 0)
	{
		return 0;		

	}
	else if(money < 0)
	{
		return -inf;		

	}

	else if(save[index][money] != -1)
	{
		return save[index][money];
	}

	else
	{

		int mx = -inf;
		
		for(i = 0;i < each[index];i++)
		{
			mx = max(mx,item[index][i] + solve(index+1,money-item[index][i]));
			
		}
	
		return save[index][money]=mx;
			
		
	}

}
int main(void)
{
	int t,i,j,a;
	
	int optimum;

	cin >> t;

	while(t--)
	{
		cin >> budget >> num;

		for(i = 0; i < num;i++)
		{
			cin >> a;
			each[i] = a;
			for(j = 0; j < a;j++)
				cin >> item[i][j];

		}

		memset(save,-1,sizeof(save));

		optimum = solve(0,budget);
		if(optimum < 0)
			cout << "no solution\n";
		else
			cout  << optimum << endl;

	}

	return 0;
}