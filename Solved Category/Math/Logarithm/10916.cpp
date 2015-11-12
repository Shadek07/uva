
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

int main(void)
{
	int y;
	double n;
	int k,i,j,k1;
	double a,b,c;
	
	while(cin >> y)
	{
		if(y == 0)
			break;
		a = (y-1960)*1.0/10.0;
		i = 2 + floor(a);
		c = pow(2.0,i);
		j = 0;
		//cout << c << endl;
		while(1)
		{
			
			k1 = j+1; 
			b = log10(k1*1.0)/log10(2.0);
			c = c-b;
			if(c <= 0)
			{
				j = k1-1;
				break;
			}
			else
				j = k1;
		}

		cout << j << endl;

	}
	return 0;
}
