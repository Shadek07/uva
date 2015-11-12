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
string tar;
char in[5];

char grid[4][4];
int cnt(char c)
{
	int i,j;
	int cn = 0;
	for(i = 0;i<3;i++)
	{
		for(j = 0;j<3;j++)
			if(grid[i][j]==c)
				cn++;
	}

	return cn;
}

bool win(char c)
{
	int i,j,k;
	bool tmp;
	for(i = 0;i<3;i++)
	{
		tmp = true;
		for(j = 0;j<3;j++)
		{
			if(grid[i][j] !=c)
				tmp = false;
		}
		if(tmp)
			return tmp;
	}
	for(i = 0;i<3;i++)
	{
		tmp = true;
		for(j = 0;j<3;j++)
		{
			if(grid[j][i] !=c)
				tmp = false;
		}
		if(tmp)
			return tmp;
	}

	if(grid[0][0] == c && grid[1][1] == c && grid[2][2] == c)
		return true;
	if(grid[2][0] == c && grid[1][1] == c && grid[0][2] == c)
		return true;
	return false;
}
int main(void)
{
    int t;
    cin >> t;
    getchar();
    tar = "";
    int i,j,k;
    bool temp;
    int ch;
	
    while(t--)
    {
		for(i = 0;i<3;i++)
        gets(grid[i]);
		int a,b;
		a = cnt('X');
		b = cnt('O');
		bool wina,winb;
		if(a==b || a-b ==1)
		{
			wina = win('X');
			winb = win('O');
			if(wina && winb)
				temp = false;
			else if(wina && a==b)
				temp = false;
			else if(winb && a-b==1)
				temp = false;
			else
				temp = true;

		}
		else
			temp = false;
		if(temp)
			cout << "yes\n";
		else
			cout << "no\n";
		if(t)
			getchar();
              
    }
    return 0;
}
