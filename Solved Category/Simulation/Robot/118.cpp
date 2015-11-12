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

enum dir {N,S,E,W};

int main(void)
{
	bool grid[102][102];
	int m,n;
	cin >>m >> n;
	int i,j,k,a,b,len;
	char c;
	char in[101];
	memset(grid,false,sizeof(grid));
	while(cin >> a >> b >> c)
	{
		getchar();
		gets(in);		
		int x,y;
		x = a;
		y = b;
		dir d;
		if(c == 'E')
		d = E;
		else if(c == 'N')
		d = N;
		else if(c == 'W')
		d = W;
		else if(c == 'S')
		d = S;
		bool lost=false;
		len = strlen(in);
		for(i = 0;i<len;i++)
		{
			if(in[i] == 'L')
			{
				if(d==E)
					d = N;
				else if(d==N)
					d = W;
				else if(d == W)
					d = S;
				else if(d == S)
					d = E;
			}
			if(in[i] == 'R')
			{
				if(d==E)
					d = S;
				else if(d==S)
					d = W;
				else if(d == W)
					d = N;
				else if(d == N)
					d = E;

			}
			if(in[i] == 'F')
			{
				if(d==E)
				{
					x++;
					if(x>m)
					{
						if(grid[x-1][y]==false)
						{
							lost = true;
							x--;
							grid[x][y] = true;
							break;
						}
						else
							x--;

					}
				}
				else if(d==S)
				{
					y--;
					if(y<0)
					{
						if(grid[x][y+1] == false)
						{
							lost = true;
							y++;
							grid[x][y] = true;
							break;
						}
						else
							y++;
					}
				}
				else if(d == W)
				{
					x--;
					if(x<0)
					{
						if(grid[x+1][y]==false)
						{
							lost = true;
							x++;
							grid[x][y] = true;
							break;
						}
						else
							x++;

					}

				}
				else if(d == N)
				{
					y++;
					if(y>n)
					{
						if(grid[x][y-1] == false)
						{
							lost = true;
							y--;
							grid[x][y] = true;
							break;
						}
						else
							y--;
					}

				}
				
			}
		}

		//x = m-x;
		cout << x << " " << y << " ";
		if(d==E)
			cout << "E";
		else if(d==S)
			cout << "S";
		else if(d == W)
			cout << "W";
		else if(d == N)
			cout << "N";
		if(lost)
			cout << " LOST\n";
		else 
			cout << "\n";
		

	}

	return 0;
}
