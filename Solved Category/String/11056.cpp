
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
int n;
struct pilot
{
	string orig;
	string low;
	int time;
}part[101];

int cmp(pilot p1,pilot p2)
{
	if(p1.time < p2.time)
		return 1;
	else if(p1.time == p2.time && p1.low.compare(p2.low) < 0)
		return 1;
	return 0;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca=1;
	char in[1000];
	int i,j,k;
	int val[4];
	while(cin >> n)
	{
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(in);
			char *p;
			p = strtok(in," :,.,!?");
			j=0;
			part[i].time = 0;
			while( p != NULL)
			{					
				if(j == 0)
				{
					part[i].orig = p;
					part[i].low = "";
					for(k = 0;p[k] != '\0';k++)
						part[i].low += tolower(p[k]);
				}
				if(j == 1)
				{
					part[i].time += atoi(p)*60*1000;
				}
				if(j == 3)
				{
					part[i].time += atoi(p)*1000;
				}
				if(j == 5)
				{				
					part[i].time += atoi(p);
				}
				p = strtok(NULL," :,.,!?");
				j++;
			}
		}

		sort(part,part+n,cmp);
		//if(ca==1)
			//ca=2;
		//else
			//cout << endl;
		for(i = 0,k=1;i<n;i+=2,k++)
		{
			cout << "Row " << k << endl;
			cout << part[i].orig << endl;
			if(i+1<n)
				cout << part[i+1].orig << endl;
		}
		cout << endl;

	}
    
	return 0;
}
