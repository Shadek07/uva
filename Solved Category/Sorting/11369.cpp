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
#include<stack>

using namespace std;

vector<int> v;

bool comp(int a,int b)
{
	if(a>b)
		return true;
	else
		return false;
}
int main(void)
{
	int t,i,j,k;
	int a,b,n;
	unsigned long sum;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i = 0; i< n;i++)
		{
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),comp);
		sum = 0;
		for(i = 2;i<n;i+=3)
		{
			sum += v[i];
		}
		cout << sum << endl;
		v.clear();
	}
	return 0;
}
