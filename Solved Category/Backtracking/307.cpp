
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
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

int h[101],len,n,num,mn;
bool found;
bool vis[101];
int cmp(int a,int b)
{
	if(a>b)
		return 1;
	else
		return 0;
}

void calc(int ind,int sticks,int filled)
{
	
	if(sticks == num-1)
	{
		found = true;
		mn = len;
		return;
	}
	if(found)
		return;
	
	int i;
	for(i = ind;i<n && !found;i++)
	{
		if(vis[i])
			continue;
		if(filled+h[i]>len)
			continue;
		if(i>0 && h[i] == h[i-1] && vis[i-1]==false)
			continue;
		if(filled+h[i]<len)
		{
			vis[i] = true;
			calc(i+1,sticks,filled+h[i]);
			vis[i] = false;
			if(filled == 0) 
				return;
			//if(h[i] == filled - len) return;
		}
		if(filled+h[i]==len)
		{
			vis[i] = true;
			calc(0,sticks+1,0);
			vis[i] = false;
			return;
		}
	}
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int sum;
	while(cin >> n && n)
	{
		sum = 0;
		for(i = 0;i<n;i++)
		{
			cin >> h[i];
			sum += h[i];
		}

		sort(h,h+n,cmp);
		found = false;
		mn = sum;
		for(len = h[0];len<=sum/2 && !found;len++)
		{
			if(sum%len==0)
			{
				num = sum/len;
				memset(vis,false,sizeof(vis));
				calc(0,0,0);
				if(found)
					break;
			}
		}
		cout << mn << endl;
	}
     return 0;
}