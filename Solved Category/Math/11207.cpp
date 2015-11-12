
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
	int n;
	int i;
	double l,w;
	int ind;
	double mx;
	while(cin >> n && n)
	{
		mx = -1;
		double tmp,t;
		for(i = 0;i<n;i++)
		{
			cin >> l >> w;
			tmp = -1;

			t = min(l/2,w/2);
			if(t>tmp)
				tmp = t;

			t = min(l/3,w/2);
			if(t>tmp)
				tmp = t;

			t = min(l/2,w/3);
			if(t>tmp)
				tmp = t;

			t = min(l/4,w);
			if(t>tmp)
				tmp = t;

			t = min(l,w/4);
			if(t>tmp)
				tmp = t;
			//cout << tmp << endl;

			if(tmp > mx)
			{
				mx = tmp;
				ind = i+1;
				//cout << mx << endl;
			}
			
			

		}

		cout << ind << endl;


	}
     return 0;
}