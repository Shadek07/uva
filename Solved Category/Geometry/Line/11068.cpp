
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
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int a1,b1,c1,a2,b2,c2;
	double c,x,y;
	while(cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2)
	{
		if(!a1&&!b1&&!c1&&!a2&&!b2&&!c2)
			break;
		if(a1*b2 == a2*b1)
		{
			cout << "No fixed point exists.\n";
			continue;
		}
		else
		{
			c = a1*b2 -(a2*b1);
			x = (-b1*c2+b2*c1)/c;
			y = (-a2*c1+a1*c2)/c;
			printf("The fixed point is at %.2f %.2f.\n",x,y);


		}
	}
     return 0;
}