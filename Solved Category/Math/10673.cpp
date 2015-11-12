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
	int t;
    long int x,k,a,b;
    long int q;
	cin >> t;
	while(t--)
	{
		cin >> x >> k;
		a = floor(x*1.0/k);
		b = ceil(x*1.0/k);
		q = 0;
		if(a != 0)
		{
			while(1)
			{
				if((x-q*b)%a ==0)
					break;
				q++;
			}
			cout << (x-q*b)/a << " " << q << endl;
		}
		else
		{
			cout << 0 << " " << x/b << endl;
		}

	}
	return 0;
}