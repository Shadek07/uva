
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<iomanip>
using namespace std;


char out[3151][3151];
int n;

void horizontal_line_dot(int line)
{
	int i;
	for(i=0;i<5*n;i++)
	{
		out[line][i] = '.';
	}
}

void horizontal_line_star(int line)
{
	int i;
	for(i=0;i<5*n;i++)
	{
		out[line][i] = '*';
	}
}

void horizontal_line_star_Custom(int line,int st,int cnt)
{
	int i;
	for(i = st;i<st+cnt;i++)
		out[line][i] = '*';
}

void horizontal_line_dot_Custom(int line,int st,int cnt)
{
	int i;
	for(i = st;i<st+cnt;i++)
		out[line][i] = '.';
}

void vertical_line_dot(int col)
{
	int i;
	for(i=0;i<5*n;i++)
	{
		out[i][col] = '.';
	}
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k;
	int ca=1;
	while(cin >> n && n)
	{
		memset(out,'\0',sizeof(out));
		//if(ca==1)
			//ca=2;
		//else
			//cout << endl << endl;
		if(n<0)
		{
			n = -n;
			//S
			for(i=0;i<n;i++)
				horizontal_line_star(i);
			for(;i<2*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,5*n-n);
			}
			for(;i<3*n;i++)
				horizontal_line_star(i);
			for(;i<4*n;i++)
			{
				horizontal_line_dot_Custom(i,0,5*n-n);
				horizontal_line_star_Custom(i,5*n-n,n);
			}
			for(;i<5*n;i++)
				horizontal_line_star(i);

			for(;i<6*n;i++)
				horizontal_line_dot(i);

			//A
			for(;i<7*n;i++)
			{
				horizontal_line_dot_Custom(i,0,n);
				horizontal_line_star_Custom(i,n,3*n);
				horizontal_line_dot_Custom(i,4*n,n);
			}
			for(;i<8*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<9*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<11*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}

			for(;i<12*n;i++)
				horizontal_line_dot(i);

			//V
			for(;i<15*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<16*n;i++)
			{
				horizontal_line_dot_Custom(i,0,n);
				horizontal_line_star_Custom(i,n,n);
				horizontal_line_dot_Custom(i,2*n,n);
				horizontal_line_star_Custom(i,3*n,n);
				horizontal_line_dot_Custom(i,4*n,n);
			}
			for(;i<17*n;i++)
			{
				horizontal_line_dot_Custom(i,0,2*n);
				horizontal_line_star_Custom(i,2*n,n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}
			for(;i<18*n;i++)
				horizontal_line_dot(i);

			//E
			for(;i<19*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<20*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,4*n);
			}
			for(;i<21*n;i++)
			{
				horizontal_line_star_Custom(i,0,3*n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}
			for(;i<22*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,4*n);
			}
			for(;i<23*n;i++)
			{
				horizontal_line_star(i);
			}

			//separation of two words: "save" and "hridoy"
			for(;i<26*n;i++)
				horizontal_line_dot(i);

			//H
			for(;i<28*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<29*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<31*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			
			for(;i<32*n;i++)
				horizontal_line_dot(i);

			//R
			for(;i<33*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<34*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<35*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<36*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,n);
				horizontal_line_star_Custom(i,2*n,n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}

			for(;i<37*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,2*n);
				horizontal_line_star_Custom(i,3*n,2*n);
			}

			for(;i<38*n;i++)
			{
				horizontal_line_dot(i);
			}

			//I
			for(;i<39*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<42*n;i++)
			{
				horizontal_line_dot_Custom(i,0,2*n);
				horizontal_line_star_Custom(i,2*n,n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}
			for(;i<43*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<44*n;i++)
				horizontal_line_dot(i);

			//D
			for(;i<45*n;i++)
			{
				horizontal_line_star_Custom(i,0,3*n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}
			for(;i<46*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,2*n);
				horizontal_line_star_Custom(i,3*n,n);
				horizontal_line_dot_Custom(i,4*n,n);
			}
			for(;i<47*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<48*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,2*n);
				horizontal_line_star_Custom(i,3*n,n);
				horizontal_line_dot_Custom(i,4*n,n);
			}
			for(;i<49*n;i++)
			{
				horizontal_line_star_Custom(i,0,3*n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}

			for(;i<50*n;i++)
				horizontal_line_dot(i);

			//O
			for(;i<51*n;i++)
			{
				horizontal_line_star(i);
			}
			for(;i<54*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<55*n;i++)
			{
				horizontal_line_star(i);
			}

			for(;i<56*n;i++)
				horizontal_line_dot(i);

			//Y
			for(;i<57*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);
				horizontal_line_dot_Custom(i,n,3*n);
				horizontal_line_star_Custom(i,4*n,n);
			}
			for(;i<58*n;i++)
			{
				horizontal_line_dot_Custom(i,0,n);
				horizontal_line_star_Custom(i,n,n);
				horizontal_line_dot_Custom(i,2*n,n);
				horizontal_line_star_Custom(i,3*n,n);
				horizontal_line_dot_Custom(i,4*n,n);
			}
			for(;i<61*n;i++)
			{
				horizontal_line_dot_Custom(i,0,2*n);
				horizontal_line_star_Custom(i,2*n,n);
				horizontal_line_dot_Custom(i,3*n,2*n);
			}

			for(j=0;j<i;j++)
			{
				for(k = 0;k<5*n;k++)
				{
					cout << out[j][k];
				}
				cout << endl;
			}
			
		}
		else
		{
			for(i = 0;i<n;i++)
			{
				horizontal_line_star_Custom(i,0,5*n);//S

				horizontal_line_dot_Custom(i,5*n,n);

				horizontal_line_dot_Custom(i,6*n,n);//A
				horizontal_line_star_Custom(i,7*n,3*n);
				horizontal_line_dot_Custom(i,10*n,n);

				horizontal_line_dot_Custom(i,11*n,n);

				horizontal_line_star_Custom(i,12*n,n);//V
				horizontal_line_dot_Custom(i,13*n,3*n);
				horizontal_line_star_Custom(i,16*n,n);

				horizontal_line_dot_Custom(i,17*n,n);

				horizontal_line_star_Custom(i,18*n,5*n);//E

				horizontal_line_dot_Custom(i,23*n,3*n);

				horizontal_line_star_Custom(i,26*n,n);//H
				horizontal_line_dot_Custom(i,27*n,3*n);
				horizontal_line_star_Custom(i,30*n,n);

				horizontal_line_dot_Custom(i,31*n,n);

				horizontal_line_star_Custom(i,32*n,5*n);//R

				horizontal_line_dot_Custom(i,37*n,n);

				horizontal_line_star_Custom(i,38*n,5*n);//I

				horizontal_line_dot_Custom(i,43*n,n);

				horizontal_line_star_Custom(i,44*n,3*n);//D
				horizontal_line_dot_Custom(i,47*n,2*n);

				horizontal_line_dot_Custom(i,49*n,n);

				horizontal_line_star_Custom(i,50*n,5*n);//O

				horizontal_line_dot_Custom(i,55*n,n);

				horizontal_line_star_Custom(i,56*n,n);//H
				horizontal_line_dot_Custom(i,57*n,3*n);
				horizontal_line_star_Custom(i,60*n,n);
				for(k=0;k<61*n;k++)
				cout << out[i][k];
				cout << endl;

			}
			for(;i<2*n;i++)
			{
				horizontal_line_star_Custom(i,0,n);//S
				horizontal_line_dot_Custom(i,n,4*n);

				horizontal_line_dot_Custom(i,5*n,n);

				horizontal_line_star_Custom(i,6*n,n);//A
				horizontal_line_dot_Custom(i,7*n,3*n);
				horizontal_line_star_Custom(i,10*n,n);

				horizontal_line_dot_Custom(i,11*n,n);

				horizontal_line_star_Custom(i,12*n,n);//V
				horizontal_line_dot_Custom(i,13*n,3*n);
				horizontal_line_star_Custom(i,16*n,n);

				horizontal_line_dot_Custom(i,17*n,n);

				horizontal_line_star_Custom(i,18*n,n);//E
				horizontal_line_dot_Custom(i,19*n,4*n);

				horizontal_line_dot_Custom(i,23*n,3*n);

				horizontal_line_star_Custom(i,26*n,n);//H
				horizontal_line_dot_Custom(i,27*n,3*n);
				horizontal_line_star_Custom(i,30*n,n);

				horizontal_line_dot_Custom(i,31*n,n);

				horizontal_line_star_Custom(i,32*n,n);//R
				horizontal_line_dot_Custom(i,33*n,3*n);
				horizontal_line_star_Custom(i,36*n,n);

				horizontal_line_dot_Custom(i,37*n,n);

				horizontal_line_dot_Custom(i,38*n,2*n);//I
				horizontal_line_star_Custom(i,40*n,n);
				horizontal_line_dot_Custom(i,41*n,2*n);

				horizontal_line_dot_Custom(i,43*n,n);

				horizontal_line_star_Custom(i,44*n,n);//D
				horizontal_line_dot_Custom(i,45*n,2*n);
				horizontal_line_star_Custom(i,47*n,n);
				horizontal_line_dot_Custom(i,48*n,n);

				horizontal_line_dot_Custom(i,49*n,n);

				horizontal_line_star_Custom(i,50*n,n);//O
				horizontal_line_dot_Custom(i,51*n,3*n);
				horizontal_line_star_Custom(i,54*n,n);

				horizontal_line_dot_Custom(i,55*n,n);

				horizontal_line_dot_Custom(i,56*n,n);//Y
				horizontal_line_star_Custom(i,57*n,n);
				horizontal_line_dot_Custom(i,58*n,n);
				horizontal_line_star_Custom(i,59*n,n);
				horizontal_line_dot_Custom(i,60*n,n);
				for(k=0;k<61*n;k++)
				cout << out[i][k];
				cout << endl;
			}
			for(;i<3*n;i++)
			{
				horizontal_line_star_Custom(i,0,5*n);//S

				horizontal_line_dot_Custom(i,5*n,n);

				horizontal_line_star_Custom(i,6*n,5*n);//A

				horizontal_line_dot_Custom(i,11*n,n);

				horizontal_line_star_Custom(i,12*n,n);//V
				horizontal_line_dot_Custom(i,13*n,3*n);
				horizontal_line_star_Custom(i,16*n,n);

				horizontal_line_dot_Custom(i,17*n,n);

				horizontal_line_star_Custom(i,18*n,3*n);//E
				horizontal_line_dot_Custom(i,21*n,2*n);

				horizontal_line_dot_Custom(i,23*n,3*n);

				horizontal_line_star_Custom(i,26*n,5*n);//H

				horizontal_line_dot_Custom(i,31*n,n);

				horizontal_line_star_Custom(i,32*n,5*n);//R

				horizontal_line_dot_Custom(i,37*n,n);

				horizontal_line_dot_Custom(i,38*n,2*n);//I
				horizontal_line_star_Custom(i,40*n,n);
				horizontal_line_dot_Custom(i,41*n,2*n);

				horizontal_line_dot_Custom(i,43*n,n);

				horizontal_line_star_Custom(i,44*n,n);//D
				horizontal_line_dot_Custom(i,45*n,3*n);
				horizontal_line_star_Custom(i,48*n,n);

				horizontal_line_dot_Custom(i,49*n,n);

				horizontal_line_star_Custom(i,50*n,n);//O
				horizontal_line_dot_Custom(i,51*n,3*n);
				horizontal_line_star_Custom(i,54*n,n);

				horizontal_line_dot_Custom(i,55*n,n);

				horizontal_line_dot_Custom(i,56*n,2*n);//Y
				horizontal_line_star_Custom(i,58*n,n);
				horizontal_line_dot_Custom(i,59*n,2*n);
				for(k=0;k<61*n;k++)
				cout << out[i][k];
				cout << endl;
			}
			for(;i<4*n;i++)
			{
				horizontal_line_dot_Custom(i,0,4*n);//S
				horizontal_line_star_Custom(i,4*n,n);

				horizontal_line_dot_Custom(i,5*n,n);

				horizontal_line_star_Custom(i,6*n,n);//A
				horizontal_line_dot_Custom(i,7*n,3*n);
				horizontal_line_star_Custom(i,10*n,n);

				horizontal_line_dot_Custom(i,11*n,n);

				horizontal_line_dot_Custom(i,12*n,n);//V
				horizontal_line_star_Custom(i,13*n,n);
				horizontal_line_dot_Custom(i,14*n,n);
				horizontal_line_star_Custom(i,15*n,n);
				horizontal_line_dot_Custom(i,16*n,n);

				horizontal_line_dot_Custom(i,17*n,n);

				horizontal_line_star_Custom(i,18*n,n);//E
				horizontal_line_dot_Custom(i,19*n,4*n);

				horizontal_line_dot_Custom(i,23*n,3*n);

				horizontal_line_star_Custom(i,26*n,n);//H
				horizontal_line_dot_Custom(i,27*n,3*n);
				horizontal_line_star_Custom(i,30*n,n);

				horizontal_line_dot_Custom(i,31*n,n);

				horizontal_line_star_Custom(i,32*n,n);//R
				horizontal_line_dot_Custom(i,33*n,n);
				horizontal_line_star_Custom(i,34*n,n);
				horizontal_line_dot_Custom(i,35*n,2*n);

				horizontal_line_dot_Custom(i,37*n,n);

				horizontal_line_dot_Custom(i,38*n,2*n);//I
				horizontal_line_star_Custom(i,40*n,n);
				horizontal_line_dot_Custom(i,41*n,2*n);

				horizontal_line_dot_Custom(i,43*n,n);

				horizontal_line_star_Custom(i,44*n,n);//D
				horizontal_line_dot_Custom(i,45*n,2*n);
				horizontal_line_star_Custom(i,47*n,n);
				horizontal_line_dot_Custom(i,48*n,n);

				horizontal_line_dot_Custom(i,49*n,n);

				horizontal_line_star_Custom(i,50*n,n);//O
				horizontal_line_dot_Custom(i,51*n,3*n);
				horizontal_line_star_Custom(i,54*n,n);

				horizontal_line_dot_Custom(i,55*n,n);

				horizontal_line_dot_Custom(i,56*n,2*n);//Y
				horizontal_line_star_Custom(i,58*n,n);
				horizontal_line_dot_Custom(i,59*n,2*n);
				for(k=0;k<61*n;k++)
				cout << out[i][k];
				cout << endl;
			}
			for(;i<5*n;i++)
			{
				horizontal_line_star_Custom(i,0,5*n);//S

				horizontal_line_dot_Custom(i,5*n,n);

				horizontal_line_star_Custom(i,6*n,n);//A
				horizontal_line_dot_Custom(i,7*n,3*n);
				horizontal_line_star_Custom(i,10*n,n);

				horizontal_line_dot_Custom(i,11*n,n);

				horizontal_line_dot_Custom(i,12*n,2*n);//V
				horizontal_line_star_Custom(i,14*n,n);
				horizontal_line_dot_Custom(i,15*n,2*n);

				horizontal_line_dot_Custom(i,17*n,n);

				horizontal_line_star_Custom(i,18*n,5*n);//E

				horizontal_line_dot_Custom(i,23*n,3*n);

				horizontal_line_star_Custom(i,26*n,n);//H
				horizontal_line_dot_Custom(i,27*n,3*n);
				horizontal_line_star_Custom(i,30*n,n);

				horizontal_line_dot_Custom(i,31*n,n);

				horizontal_line_star_Custom(i,32*n,n);//R
				horizontal_line_dot_Custom(i,33*n,2*n);
				horizontal_line_star_Custom(i,35*n,2*n);

				horizontal_line_dot_Custom(i,37*n,n);

				horizontal_line_star_Custom(i,38*n,5*n);//I

				horizontal_line_dot_Custom(i,43*n,n);

				horizontal_line_star_Custom(i,44*n,3*n);//D
				horizontal_line_dot_Custom(i,47*n,2*n);

				horizontal_line_dot_Custom(i,49*n,n);

				horizontal_line_star_Custom(i,50*n,5*n);//O

				horizontal_line_dot_Custom(i,55*n,n);

				horizontal_line_dot_Custom(i,56*n,2*n);
				horizontal_line_star_Custom(i,58*n,n);//Y
				horizontal_line_dot_Custom(i,59*n,2*n);
				for(k=0;k<61*n;k++)
				cout << out[i][k];
				cout << endl;

			}

		}

		cout << endl << endl;
	}

    return 0;
}
