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

int main(void)
{

	char in[100];
	int len;
	int i,j,k,ind;
	int get;
	int valid;
	int dp[12];
	int dp1[12];
	int a,b;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);

	while(gets(in))
	{

		valid = 1; //by default valid
		dp[0] = 0;
		dp1[0] = 0;
		ind = 1;
		len = strlen(in);
		
		if(len == 0)
		{
			cout << " " << "is incorrect.\n";
			continue;
		}

		i = 0;
		while(in[i] == ' ' || in[i] == '\t')
			i++;
		j = len-1;
		a = i;
		while(in[j] == ' ' || in[j] == '\t')
			j--;
		b = j;
		for( ; i<=j; i++)
		{
			if(!((in[i] >= '0' && in[i] <= '9') || in[i] == '-' || in[i] == 'X'))
			{
				valid = 0;
				break;
			}
			if(in[i] >= '0' && in[i] <= '9')
			{
				if(ind>10)
				{
					valid = 0;
					break;
				}
				else
				{
					get = in[i] - '0';
					dp[ind] = dp[ind-1] + get;
					dp1[ind] = dp1[ind-1] + dp[ind];
					ind++;
				}
			}
			if(in[i] == 'X')
			{
				if(ind != 10)
				{
					valid = 0;
					break;
				}
				else
				{
					get = 10;
					dp[ind] = dp[ind-1] + get;
					dp1[ind] = dp1[ind-1] + dp[ind];
					ind++;
				}
			}
		}

		if(valid)
		{
			if(dp1[10]%11 != 0)
				valid = 0;
			if(ind < 11)
				valid = 0;
		}
		
		for(i = a;i<=b;i++)
			cout << in[i];
		if(valid == 0)
		{
		    cout  << " is incorrect.\n";
		}
		else
		{
			cout  << " is correct.\n";
		}

	}

	return 0;
}