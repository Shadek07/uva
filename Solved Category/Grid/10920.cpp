
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
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)

int dx[]={0,1,1,0,-1,-1,-1,0,1};
int dy[]={0,0,-1,-1,-1,0,1,1,1};

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	unsigned long long int sz,pos;
	unsigned long long int a,b;
	unsigned long long int i,j;
	int row,col;
	while(cin >> sz >> pos)
	{
		if(!sz && !pos)
			break;
		row = sz/2 + 1;
		col = sz/2 + 1;
		if(pos<=9)
		{
			row += dx[pos-1];
			col += dy[pos-1];
			cout << "Line = " << row << ", column = " << col << ".\n";
		}
		else
		{
			row += dx[8];//go to position of 9'th value
			col += dy[8];
			//row += 1; // then go to 10'th value, only increase row
			for(i=5;;i+=2)
			{
				if(i*i >= pos)
				{
					a = (i-2)*(i-2) + 1;
					row += 1;
					if(a+(i-2) >= pos) //fall in upper part of new square
					{
						col -= (pos-a);
						break;
					}
					a += (i-2);
					col -= (i-2);
					if(a+(i-1) >= pos) //fall in left side
					{
						row -= (pos-a);
						break;
					}
					a += (i-1);
					row -= (i-1);
					if(a+(i-1) >= pos) //fall in lower part
					{
						col += (pos-a);
						break;
					}
					a += (i-1);
					col += (i-1);
					//now certainly fall in right side
					row += (pos-a);
					break;
				}
				else
				{
					col++;
					row++;
				}
			}
			cout << "Line = " << row << ", column = " << col << ".\n";
		}
	}
     return 0;
}
