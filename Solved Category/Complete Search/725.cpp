
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

int n;
bool dig[10];
int main(void)
{
	int ch=0;
	int i,j,k;
	bool t,t1;
	int a,b,d,b1;
	while(cin >> n && n)
	{
		if(ch==0)
			ch = 1;
		else
			cout << endl;
		t = false;
		for(i = 1234;i<=98765;i++)
		{
			b = n*i;
			b1 = b;
			memset(dig,false,sizeof(dig));
			a = i;
			t1 = true;
			if(a<10000)
				dig[0] = true;
			while(a)
			{

				d = a%10;
				a/=10;
				if(dig[d])
				{
					t1 = false;
					break;
				}
				else
					dig[d] = true;

			}
			while(t1 && b)
			{

				d = b%10;
				b /= 10;
				if(dig[d])
				{
					t1 = false;
					break;
				}
				else
					dig[d] = true;

			}
			if(t1 && !(b1<10000 && i <10000))
			{
				t = true;
				if(b1<10000)
					cout << "0" << b1 << " / ";
				else
					cout << b1 << " / ";
				if(i<10000)
					cout << "0" << i <<" = " << n << endl;
				else
					cout << i << " = " << n << endl;
			}
		}

		if(!t)
			cout << "There are no solutions for " << n <<".\n";
		
	}
	return 0;
}