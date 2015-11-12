
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
#include <bitset>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
//#define max(x,y) ((x)>(y)?(x):(y))
//#define min(x,y) ((x)<(y)?(x):(y))
int N,M;
unsigned long long int budget;

unsigned long long int input[100][101];
unsigned long long int sum[100][101];
unsigned long long int arr[101];
int area;
int tmpl,tmpw;
unsigned long long int mn;
void find_max()
{
	int sz=-1,i,j;

	unsigned long long int mx;
	unsigned long long int prefix[102];
	prefix[0] = 0;
	prefix[1] = arr[0];
	for(i = 1;i<M;i++)
		prefix[i+1] = prefix[i]+arr[i];

	for(i = 1;i<=M;i++)
	{
		for(j=i;j<=M;j++)
		{
			tmpl = j-i+1;
			if(prefix[j]-prefix[i-1] <= budget && tmpw*tmpl > area)
			{
				mn = prefix[j]-prefix[i-1];
				area = tmpw*tmpl;
			}
			else if(tmpw*tmpl == area && prefix[j]-prefix[i-1] <= budget && prefix[j]-prefix[i-1]< mn)
			{
				mn = prefix[j]-prefix[i-1];
			}
		}

	}

}

int main(void)
{
	int i,j,k;
	int t;
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	cin >> t;
	int ca=1;
	while(t--)
	{
		cin >> N >> M >> budget;

		for( i = 0; i < N; i++)
		{
			for( j = 0; j < M; j++)
			{
				cin >> input[i][j];
			}
		}

		for( j = 0; j < M; j++)
		{
			sum[0][j] = input[0][j];

			for( i = 1; i < N; i++)
			{
				sum[i][j] = sum[i-1][j] + input[i][j];

			}
		}

		

		area=0;
		mn = budget+1;
		
		for( i = 0; i<N ;i++)
		{
			for( k = 0; k < M; k++)
			{
				arr[k]  =  sum[i][k];
			}

			tmpw = i+1;
			find_max();
			
		}

		for(i = 1; i < N-1; i++)
		{
			for( j = 0; j < M; j++)
			{
				arr[j] = input[i][j];
			}
			tmpw = 1;
			find_max();
			

			for( j = i+1; j < N; j++)
			{
				for( k = 0; k < M; k++)
				{
					arr[k] = sum[j][k] - sum[i-1][k];
				}
				tmpw = j-i+1;
				find_max();
				
			}
		}
        if(area == 0)
        mn = 0;
		cout << "Case #" << ca++ <<": " << area << " " << mn << endl; 
		
	}

	return 0;
}
