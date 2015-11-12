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

int h[20002];
int main(void)
{
	int a,b,c,i,j,k;
	memset(h,0,sizeof(h));
	int f=-1;
	int b1 = -1;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		if(a == c)
			continue;
		if(f<2*c)
			f = 2*c;
		if(b1 == -1)
			b1 = 2*a;
		for(i = 2*a; i<=2*c;i++)
		{
			if(h[i] < b)
				h[i] = b;
		}
	}
	a = -1;
	for(i=b1;i<=f;i++)
	{
		if(h[i] != a)
		{
			cout << i/2 << " " << h[i] << " ";
			a = h[i];
		}
	}
	cout << f/2 << " " << 0 << endl;

	return 0;
}