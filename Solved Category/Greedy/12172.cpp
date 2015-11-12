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
using namespace std;

vector<int> v;

void odd_recursive(int n)
{
	if(n>= 9)
	{
		odd_recursive(n-7);
		//cout << 8;
		v.push_back(8);
	}
	else
	{
		if(n == 8)
		{
			//cout << 10;
			v.push_back(1);
			v.push_back(0);
		}
		else if(n==7)
		{
			//cout << 8;
			v.push_back(8);
		}
		else if(n==6)
		{
			//cout << 6;
			v.push_back(6);
		}
		else if(n==5)
		{
			//cout << 2;
			v.push_back(2);
		}
		else if(n==4)
		{
			//cout << 4;
			v.push_back(4);
		}
		else if(n==3)
		{
			//cout << 7;
			v.push_back(7);
		}
		else
		{
			//cout << 1;
			v.push_back(1);
		}

	}
}


void even_recursive(int n)
{
	if(n>= 9)
	{
		even_recursive(n-7);
		v.push_back(8);
	}
	else
	{
		if(n == 8)
		{
			v.push_back(1);
			v.push_back(0);
		}
		else if(n==7)
		{
			v.push_back(8);
		}
		else if(n==6)
		{
			v.push_back(6);
		}
		else if(n==5)
		{
			v.push_back(2);
		}
		else if(n==4)
		{
			v.push_back(4);
		}
		else if(n==3)
		{
			
			v.push_back(7);
		}
		else
		{
			v.push_back(1);
		}

	}
}

int main(void)
{
	int t,n;
	cin >> t;
	int i,j;
	while(t--)
	{
		cin >> n;
		v.clear();
		if(n%2==1)//odd
		{
			if(n ==3)
			{
				cout << 7 << " " << 7 << endl;
				continue;
			}
			if(n == 5)
			{
				cout << 2 << " " << 71 << endl;
				continue;
			}
			if(n == 7)
			{
				cout << 8 << " " << 711<<endl;
				continue;
			}
			odd_recursive(n);
			if(v.size()>=2)
			{
				if(v[0] == 7 && v[1] == 8 && v[2] == 8)
				{
					v[0] = 2;
					v[1] = 0;
					v[2] = 0;
				}
				else if(v[0] == 4 && v[1] == 8)
				{
					v[0] = 2;
					v[1] = 0;
				}
			}
			i = v.size();
			for(j = 0;j<i;j++)
				cout << v[j];
			cout << " ";
			cout << 7;
			for(i = 5;i<=n;i+=2)
				cout << 1;
			cout << endl;

		}
		else  //even
		{
			if(n ==2)
			{
				cout << 1 << " " << 1 << endl;
				continue;
			}
			if(n == 4)
			{
				cout << 4 << " " << 11 << endl;
				continue;
			}
			if(n == 6)
			{
				cout << "6 111"<<endl;
				continue;
			}
			if(n==10)
			{
				cout << "22 11111\n";
				continue;
			}
			even_recursive(n);
			
			if(v.size()>=2)
			{
				if(v[0] == 7 && v[1] == 8 && v[2] == 8)
				{
					v[0] = 2;
					v[1] = 0;
					v[2] = 0;
				}
				else if(v[0] == 4 && v[1] == 8)
				{
					v[0] = 2;
					v[1] = 0;
				}
			}
			
			i = v.size();
			//cout << "-" << i << endl;
			for(j = 0;j<i;j++)
				cout << v[j];
			cout << " ";
			j = n/2;
			for(i = 1;i<=j;i++)
				cout << 1;
			cout << endl;

		}
	}
	return 0;
}