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


int main(void)
{
	int t;
	char in[100002];
	cin >> t;
	getchar();
	int i,j,k,slen;
	while(t--)
	{
		gets(in);
		slen = strlen(in);
		int ind,cnt;
		int mx;
		i = 0;
		j = 1;
		k= 0 ;
		
		int x, y, tmp;
		while(i < slen && j < slen && k < slen) 
		{
			x = i + k;
			y = j + k;
			if(x >= slen)	
				x -= slen;
			if(y >= slen)	
				y -= slen;
			if(in[x] == in[y]) 
			{
				k++;
			} 
			else if(in[x] > in[y]) 
			{
				i = j+1 > i+k+1 ? j+1 : i+k+1;
				k = 0;
				tmp = i, i = j, j = tmp;
			} 
			else 
			{
				j = i+1 > j+k+1 ? i+1 : j+k+1;
				k = 0;
			}
		}
	
		
		
		
		cout << i+1 << endl;
		

	}
	return 0;
}
