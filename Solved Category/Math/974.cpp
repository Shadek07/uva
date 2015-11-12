
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

bool kap[40001];

int digits(long int a)
{
	int t = 0;
	while(a)
	{
		a /= 10;
		t++;
	}
	return t;
}

bool check(int num)
{
	 long int a = num*num;
	 int d = digits(a),i;
	 for(i = 1;i<d;i++)
	 {
		 long int m,n;
		 m = a%((int)pow(10.0,i));
		 n = a/((int)pow(10.0,i));
		 if(m != 0 && n != 0 && m+n == num)
			 return true;
	 }
	 return false;

}

void calc()
{
	int i;
	for(i = 2;i<=40000;i++)
	{
			if(check(i))
				kap[i] = true;
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	memset(kap,false,sizeof(kap));
	calc();
	int ca=1;
	int t;
	cin >> t;
	int m,n,i;
	while(t--)
	{
		cin >> m >> n;
		int cnt = 0;
		if(ca != 1)
			cout << endl;
		cout << "case #" << ca++ << endl;

		for(i = m;i<=n;i++)
		{
			if(kap[i])
			{
				cout << i << endl;
				cnt++;
			}

		}
		if(cnt == 0)
			cout << "no kaprekar numbers\n";
	}	
	
	


     return 0;
}