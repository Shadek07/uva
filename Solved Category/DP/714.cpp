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
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

unsigned long  long int val[501];
int n,k;
unsigned long  long int prefix[501];
unsigned long  long int M[501][501];
unsigned long  long int D[501][501]; //D[i][j] is index of partition
unsigned long long int INF;
vector<int> division;
int pass;
bool cut[501]; //cut[i] is true if there is a partition after first i elements 
long int high;
int org,part;
unsigned long long int solve(int n,int k)
{
	int i,j;
    unsigned long long int a,b,b1,a1;
	if(n<k)// too less number of items to divide into k parts
	{
		return 0;
	}
	
	if(M[n][k] != 0)
	{
		return M[n][k];
	}
	
	if(k==1)
	{
		return prefix[n];
	}
	for(i = n-1;i>=1;i--)
	{
		//unsigned long long  int mx=0;
		a = prefix[n] - prefix[i];
		a1 = a;
		
		b1 = b = solve(i,k-1);
		
		if(b1 != 0)//can be divided
		{
			a = max(a,b1);
			if(M[n][k] == 0)
			{
                  M[n][k] = a;
                  D[n][k] = i;
            }
			else if(M[n][k] > a)//capture the minimum result
			{
                M[n][k] = a;
				D[n][k] = i;				
			}			
		}

	}

	return M[n][k];
}

void divide(int n,int k)
{
	if(D[n][k] == -1)
		return;
	else
	{
		division.push_back(D[n][k]);
		divide(D[n][k],k-1);
	}
}
int main(void)
{
	unsigned long long int a,b;
	int i,j;
	int t;
	unsigned long long int arr[501];
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	int num[501];
	unsigned long long int p[501][501];
	cin >> t;
	 int ans;
	//INF = (unsigned long long int)4999999501;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		
		org = n;
		part = k;
		for(i = 1;i<=n;i++)
		{
			cin >> val[n-i+1];
			arr[i] = val[n-i+1];
		}
		//M[org][part] = INF;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=k;j++)
			{
				M[i][j] = 0;//(unsigned long long int)4999999501L;
				D[i][j] = 0;
			}
		}

		prefix[0] = 0;
		for(i = 1;i<=n;i++)
		{
			prefix[i] = prefix[i-1] + val[i];
		}

		for(i = 1;i<=n;i++)
		{
			M[i][1] = prefix[i];
		}
		high = -1;
		ans = solve(n,k);

		memset(cut,false,sizeof(cut));
		//cout << ans << endl;
		b = 0;
		
		for(a = k,i=n;i>=1;i--)
		{
			if(b+arr[i]>ans || i == a-1)
			{
				a--;
				b = 0;
				cut[i] = true;
			}
			b += arr[i];
			
		}

		for(i = 1;i<=n; i++)
		{
			if(i==1)
				cout << arr[i];
			else
			{
				if(cut[i-1] == true)
				{
					cout << " / " << arr[i];
				}
				else
					cout << " " << arr[i];
			}
		}
		cout << endl;


	}
	return 0;
}
