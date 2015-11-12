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
#include<stack>

using namespace std;

char T[100001];
char P[100001];
int F[100001];
int n;

void failure_function()
{
	F[0] = 0;
	int i,j;
	i = 1;
	j = 0;
	while(i<n)
	{
		if(P[i] == P[j])  //we have matched j + 1 chars
		{
			F[i] = j+1;
			i++;
			j++;
		}
		else if(j > 0)  //use failure function to shift P
		{
			j = F[j-1];
		}
		else  //no match
		{
			F[i] = 0;
			i++;
		}

	}

}

int KMP_match()
{

	failure_function();
	int i,j;
	i = 0;
	j = 0;
	while(i<n)
	{
		if(T[i] == P[j])
		{
			if(j == n-1)
			{
				return n;
			}
			else
			{
				i++;
				j++;
			}
		}
		else if(j>0)
		{
			j = F[j-1];
		}
		else
		{
			i++;
		}

	}

	return j;
}

int main(void)
{
	int ind,i;
	while(gets(P))
	{
		n = strlen(P);
		strcpy(T,P);
		reverse(P,P+n);
		cout << T;
		ind = KMP_match();
		for(i = n-1-ind;i>=0;i--)
		{
			cout << T[i];
		}
		cout << endl;
	}

	return 0;
}
