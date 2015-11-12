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
#include<fstream>

using namespace std;

#define MAX 1005
char com1[1005];
char com2[1005];
int ind1,ind2;
int m,n;
int coun;
int i,j,c[MAX][MAX],b[MAX][MAX];
int len;
char in[1009];
char dir[1009][1009];
int next[1000][1000][2];
bool one[1000][1000];
int dp[1009][1009];
int longest(int i,int j)
{
	int a,b,k;
	char c,c1;
	int ans;
	int f1,e1;
	bool ch,ch1;
	int mx;
	mx = -1;
	int temp;
	if(i>j)
		return 0;
	if(dir[i][j] != '#')
	{
		return dp[i][j];
	}
	if(i == j)
	{
		dir[i][j] = in[i];
		return dp[i][j]=1;
	}
	for(c = 'a'; c<='z';c++)
	{
		ch = ch1 = false;
		for(f1 = i;f1<=j;f1++)
		{
			if(in[f1] == c)
			{
				ch = true;
				break;
			}
		}
		for(e1 = j;e1>=i;e1--)
		{
			if(in[e1] == c)
			{
				ch1 = true;
				break;
			}
		}
		if(ch && ch1)
		{
			if(f1 == e1)
			temp = 1;
			else
				temp = 2;
			if(f1+1<=e1-1)
				temp += longest(f1+1,e1-1);
			if(mx == -1)
			{
				mx = temp;				
				c1 = c;
				a = f1;
				b = e1;
			}
			else if(mx<temp)
			{
				mx = temp;
				
				c1 = c;
				a = f1;
				b = e1;
			}
		}

	}

	dir[i][j] = c1;
	if(a == b)
		one[i][j] = true;
	next[i][j][0] = a+1;
	next[i][j][1] = b-1;
	return dp[i][j] = mx;
}

void Print(int i,int j)
{
	if(i == j)
	{
		cout << in[i];
		return;
	}
	else
	{
		cout << dir[i][j];
		int a,b;
		a = next[i][j][0];
		b = next[i][j][1];
		if(a<=b)
		Print(a,b);
		if(one[i][j] == false)
		cout << dir[i][j];
		
	}

}
int main()
{

	string s,s1,s2;
	int check = 1;

	int tr = 0;
    int i,j,k;

	int ans;
	
	
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	ind1 = ind2 = 0;
	
	//(scanf("%s",in)) == 1
	while(gets(in))
	{
		ind1 = strlen(in);
		memset(one,false,sizeof(one));
		memset(dir,'#',sizeof(dir));
		ans = longest(0,ind1-1);
		//cout << ans << endl;
		Print(0,ind1-1);
		cout << endl;
	} 		 
	
   return 0;
}