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
const int MAXL = 1005;
char str[MAXL];
int dp[MAXL][MAXL], p[MAXL][MAXL];
char ans[2002];
char input[10001];
int val;
int len1,len2;
int fir[27],sec[27];
bool check_input()
{
	int num;
	int len = strlen(input);
	int i,j,k;
	memset(fir,0,sizeof(fir));
	memset(sec,0,sizeof(sec));
	for(i = 0;i<len && input[i] != ' ' && input[i] != '\t';i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			str[i] = input[i];
			fir[input[i]-'a']++;
		}
		else
			return false;
			
	}
	if(i == len || input[i] == '\t'|| (input[i] == ' ' && i>=1001))
		return false;
	len1 = i;
	str[i] = '\0';
	i++;
	val = 0;
	num = 0;
	for(i<len;input[i] != ' ' && input[i] != '\t';i++)
	{
		if(input[i] >= '0' && input[i] <= '9')
		{
			val = val*10 + input[i] - '0';
			num++;
		}
		else
			return false;
	}
	if(i == len || input[i] == '\t'|| (input[i] == ' ' && val>=1001))
		return false;
	i++;
	int ind = 0;
	for(;i<len;i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			ans[ind++] = input[i];
			sec[input[i]-'a']++;
		}
		else
			return false;
			
	}
	ans[ind] = '\0';
	len2 = ind;
	if(len2 ==0)
		return false;
	if(ind >= 2001)
		return false;
	if(len1 + num + len2 + 2 != len)
		return false;
	return true;
}
int DP(int x, int y)
{
	int a,b;
    if (x >= y)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if (str[x] == str[y])
	{
        dp[x][y] = DP(x+1, y-1), p[x][y] = 0;
		return dp[x][y];
	}
	else
	{
		a = DP(x+1, y);
		b = DP(x,y-1);
		if(a<=b)
		{
			dp[x][y] = a+1;
			p[x][y] = 1;
			return dp[x][y];
		}
		else
		{
			dp[x][y]  =b+1;
			p[x][y] = -1;
			return dp[x][y];
		}

	}
    
    
}
bool Palindrome_check()
{
	int i,j;
	for(i = 0,j=len2-1;i<j;i++,j--)
	{
		if(ans[i] != ans[j])
			return false;

	}
	return true;
    
}

bool p3_check()
{
	int i;
	for(i = 0;i<26;i++)
		if(fir[i] > 0 && sec[i] <= 0)
			return false;
	return true;

}
bool p4_check()
{
	int i;
	for(i = 0;i<26;i++)
		if(fir[i] > sec[i])
			return false;
	return true;

}

bool p5_check()
{
	int i,j;
	i = 0;
	j = 0;
	if(len1 > len2)
		return false;
	for(;i<len1 && j<len2;j++)
	{
		if(str[i] == ans[j])
			i++;
	}
	if(i == len1)
		return true;
	return false;

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	int k,i;
	bool ch,c;
	char src[10];
	bool tf;
    while (gets(input))
    {
        ch = check_input();
		tf = true;
		if(ch == false)
		{
			cout << "FFFFFFF The solution is not accepted\n";
			ch = true;
		}
		else
		{
			ch = true;
			src[i=0] = 'T';
			i++;
			ch = Palindrome_check();
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			ch = p3_check();
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			ch = p4_check();
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			ch = p5_check();
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			//memset(dp, -1, sizeof(dp));
			//k= DP(0, len1-1);
			ch = len1 + val == len2?true:false;
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			ch = val<len1?true:false;
			if(ch==false)
				tf = false;
			if(ch == true)
				src[i++] = 'T';
			else
				src[i++] = 'F';
			src[i] = '\0';
			cout << src << " ";
			if(tf)
				cout << "The solution is accepted\n";
			else
				cout << "The solution is not accepted\n";
			
		}
    }
    return 0;
}