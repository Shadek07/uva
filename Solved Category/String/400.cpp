
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
struct fil
{
	char in[100];

}fi[100];

string out[100];

bool compare( fil a,fil b)
{
	return strcmp(a.in , b.in) < 0;
}

int main(void)
{

	int n,i,j,k,l,len,inter;

	int row,col;

	int cnt; 

	int max;

	float d;

	char one[100];

	while(cin >> n)
	{
		getchar();

		gets(one);
		strcpy(fi[0].in,one);
		max = strlen(one);

		for( i = 1; i < n ; i++)
		{
             gets(one);
			 strcpy(fi[i].in,one);
			 k = strlen(one);
			 if( max < k)
				 max = k;
		}

		cout <<"------------------------------------------------------------\n";
                
		sort(fi,fi+n,compare);

		col = (60-max)/(max+2) + 1;

		d = (n*1.0)/col;

		//cout << d << endl;


		row = ceil(d);

		//cout << row << endl;

		//cout << col << endl;

		cnt = 0;
		for(j = 0;j<row;j++)
		{
			out[j] = "";
		}
		for(i = 0;i<col && cnt < n;i++)
		{
			for(j = 0;j<row;j++)
			{
				if(cnt < n)
				{
					out[j] += fi[cnt].in;
					len = strlen(fi[cnt].in);
					cnt++;
					if(i+1 == col)
					{
						for(k = 0;k<max-len;k++)
						{
							out[j] += ' ';
						}
					}
					else
					{
						for(k = 0;k<max+2-len;k++)
						{
							out[j] += ' ';
						}
					}
				}
			}

		}

		for(j = 0;j<row;j++)
		{
			cout << out[j] << endl;
		}


	}


	return 0;
}
