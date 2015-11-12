
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
	int n,i,j,k,m;
	long int cost[21];
	long int F[21];
	cin >> n;
	long int volume,T;
	int ca=1;
	long int mn,a,b,sum;
	mn = 0;
	for(i = 0;i<n;i++)
	{
		cin >> F[i] >> cost[i];
		mn += cost[i];
	}
	cin >> m;
	bool ch=false;
	sum = mn;
	long int temp,v;
	for(i = 0;i<m;i++)
	{
		cin >> volume >> T;

		cout << "Case "<< ca++ << ": ";
		mn = sum+1;
		b = pow(2.0,n);
		for(j = 1;j<b;j++) //finding all subsets
		{
			temp = 0;
			v = 0;
			for(k = 0;k<n;k++)
			{
				if(j & (1<<k)) //check whether k'th bit is set
				{
					temp += cost[k];
					v += T*F[k];
				}
			}
			if(v>= volume && temp < mn)
				mn = temp;
			
		}

		if(mn == sum+1)
			cout << "IMPOSSIBLE\n";
		else
			cout << mn << endl;

	}
	return 0;
}
