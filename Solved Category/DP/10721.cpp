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

unsigned long long int B[51][51][51];

int main(void)
{
	int i,j,k,a,b,i1,n,m;	

	memset(B,0,sizeof(B));
  //ifstream f1("3.txt");
  //ofstream f3("2.txt");
	for(i = 1; i<51;i++)
	{
		for(m = i;m<51;m++)
		{
			B[i][1][m] = 1;
			B[i][0][0] = 1;
		}
	}


	for(i = 2;i<51;i++) //# of blocks or bars
	{
		for(j = 2;j<51;j++)
		{
			for(m = 1;m<51;m++)
			{
				unsigned long long sum = 0;
				for(k = 1;k<=m;k++)
				{
					if(i-k>0)
					sum += B[i-k][j-1][m];
				}
				B[i][j][m] = sum;
				
			}
		}
	}
	
	while(cin >> n >> k >> m)
	{
		cout << B[n][k][m] << endl;		
	}

	return 0;
}
