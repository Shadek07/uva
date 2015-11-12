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
	unsigned long long int s,d;
	long int n;
	long int low,mid,high;
	unsigned long long int s1,s2;
	unsigned long long int term;
	while(cin >> s >> d)
	{
		double n1;
		n1 = (1-2.0*s) + sqrt((1-2.0*s)*(1-2.0*s)+8.0*d);
		n1 /= 2;
		n = ceil(n1);
		low = 1;
		high = n;
		while(low<= high)
		{
			mid = (high+low)/2;
			s1 = (2*s + (mid-1))*mid;
			s1 /= 2;
			s2 = (2*s + (mid-2))*(mid-1);
			s2 /=2;
			if(d<= s1 && d > s2)
			{
				term = mid;
				break;
			}
			else if(d > s1)
			{
				low = mid+1;
			}
			else if(d < s1)
			{
				high = mid-1;
			}
		}

		cout << s+(term-1) << endl;

	}
	return 0;
}
