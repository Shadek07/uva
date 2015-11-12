
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
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n;
vector<int> v;
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca=1;
	int i,j,k;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i = 0;i<n;i++)
		{
			cin >> j;
			v.push_back(j);
		}
		sort(v.begin(),v.end());
		int sum=0;
		i =0;
		j = n-1;
		int A,B,a,b;
		while(1)
		{
			if(i==j)
			{
				sum += v[i];
				break;
			}
			else if(i+1==j)
			{
				sum += v[j];
				break;
			}
			else if(i+2==j)
			{
				sum += (v[i]+v[i+1]+v[i+2]);
				break;
			}
			else
			{
				A = v[i];
				B = v[i+1];
				a = v[j];
				b = v[j-1];
				if(A+b<2*B)
				{
					sum += 2*A+a+b;
				}
				else
				{
					sum += 2*B+A+a;
				}
				j-=2;
			}
		}
		if(ca==1)
			ca=2;
		else
			cout << endl;
		cout << sum << endl;
		i =0;
		j = n-1;
		while(1)
		{
			if(i==j)
			{
				cout <<  v[i] << endl;
				break;
			}
			else if(i+1==j)
			{
				cout << v[i] << " " << v[j] << endl;
				break;
			}
			else if(i+2==j)
			{
				cout << v[i] << " " << v[j] << endl;
				cout <<  v[i] << endl;
				cout << v[i] << " " << v[i+1] << endl;
				break;
			}
			else
			{
				A = v[i];
				B = v[i+1];
				a = v[j];
				b = v[j-1];
				if(A+b<2*B)
				{
					//sum += 2*A+a+b;
					cout << A << " " << a << endl;
					cout <<  A << endl;
					cout << A << " " << b << endl;
					cout <<  A << endl;
				}
				else
				{
					//sum += 2*B+A+a;
					cout << A << " " << B << endl;
					cout <<  A << endl;
					cout << a << " " << b << endl;
					cout <<  B << endl;
				}

				j-=2;
			}
		}

		v.clear();
	}
     return 0;
}