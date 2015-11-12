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
#include<list>
using namespace std;

int nPr(int n,int m)
{
	int k;
	register unsigned long long int i,j;
	unsigned long long int c,d;
	c=d=1;
	k = n-m;
	unsigned long long int div = 1e8;
	for(i=n;i>= k+1;i--)
	{	
		c*=i;
		//cout << i << " " << c << endl;
		while(c%10 == 0)
		c = c/10;
		//if(c > div)
		c %= div;
	}
	return c%10;
}


int main(void)
{
	int n,m;
	while((scanf("%d %d",&n,&m)) == 2)
	{	
        if(m == 0)
        {
             cout << 1 << endl;
             continue;
         }	 
		cout << nPr(n,m) << endl;	
	}
	return 0;
}
