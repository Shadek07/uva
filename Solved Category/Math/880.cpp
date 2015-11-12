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

int main(void)
{
	unsigned long long int n,low,high,mid;
	unsigned long long int row,col,a;
	unsigned long long int b,b1;
	while(cin >> n)
	{
		if(n == 1)
		{
			cout << 1 << "/" << 1 << endl;
			continue;
		}
		if(n == 2)
		{
			cout << 2 << "/" << 1 << endl;
			continue;
		}
		if(n == 3)
		{
			cout << 1 << "/" << 2 << endl;
			continue;
		}

		low = 1;
		high = 90000;
		while(low < high)
		{
			mid = (low + high)/2;
			b = mid*(mid+1);
			b /= 2;
			b1 = (mid-1)*mid;
			b1 /= 2;
			if(n> b1 && n <= b)
			{
				a = mid;
				break;
			}
			else if(b<n)
			{
				low = mid;
			}
			else
			{
				high = mid;				
			}

		}

		//cout << a << endl;
		b1 = (a-1)*a;
		b1 /= 2;
		b1++;
		b = a*(a+1);
		b /= 2;
		row = a;
		col = 1;
		row -= (n-b1);
		col += (n-b1);
		cout << row << "/" << col << endl;

	}
	return 0;
}
