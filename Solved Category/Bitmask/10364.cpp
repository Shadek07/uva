
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
#define max(a,b) ((a>a?a:b))
#define min(a,b) ((a>b?b:a))

int len[21];
int side_length;
bool found;
bool taken[21];
int n,needed;
int start[4]; // start[i] is starting index of group i

bool solve(int mask,int side_sum,int st,int side)
{
	
	if(side == 5 && mask == ((1<<n)-1))
	{
		return true;
	}
	if(side_sum == needed)
		 return solve(mask,0,start[side]+1,side+1);
	if(side_sum > needed)
		return false;
	int i;
	for(i = st;i<n;i++)
	{
		if(!(mask & (1<<i)))
		{
			if(side_sum == 0)
				start[side] = i;
			if(solve(mask|(1<<i),side_sum+len[i],i+1,side))
				return true;
		}
	}

	return false;

}

bool comp(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j,k;
	cin >> t;
	int sum;
	while(t--)
	{
		scanf("%d",&n);
		sum  =0;
		for(i = 0;i<n;i++)
		{
			scanf("%d",&len[i]);
			sum += len[i];
		}

		if(sum%4)
		{
			cout << "no\n";
		}
		else
		{
			//cout << sum << " " << sum/4 << endl;
			needed = sum/4;
			found = true;
			for(i = 0;i<n;i++)
			{
				if(len[i] > needed)
				{
					cout << "no\n";
					found = false;
					break;

				}
			}
			if(found == false)
				continue;
			found = solve(0,0,0,1);
			if(found)
				cout << "yes\n";
			else
				cout << "no\n";
		}	

	}
     return 0;
}