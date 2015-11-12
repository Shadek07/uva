#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int first[12];
int sec[12];

int de[12];

int bin[12];

int total;
vector<int> v1;
void cal(int num);
int s;

int main(void)
{
	int t;
	int i,j,k;
	int n,n1;
	cin >> t;

	while(t--)
	{
		memset(first,0,sizeof(first));

		cin >> n >> n1;
		s = n;

		for(i = 1; i <= n1; i++)
		{
			cin >> j;
			first[j] = 1;
		}

		de[1] = first[1];

		for(i = 2; i <= n; i++)
		{
			if(first[i] == 0)
			{
				de[i] = de[i-1];
			}
			else
			{
				if(de[i-1] == 0)
				{
					de[i] = 1;
				}
				else
					de[i] = 0;
			}
		}

		j = 0;
		int val;

		val = 0;
		j = n-1;

		for(i = 1; i <= n; i++,j--)
		{
			if(de[i] == 1)
				val += pow(2.0,j);

		}

		total = pow(2.0,n) - 1;


		for(i = 1; i <= total; i++)
		{
			val = (val+1)%(total+1);
			cal(val);
			
			sec[1] = v1[0];

			for(j = 1; j < v1.size(); j++)
			{
				if(v1[j] != v1[j-1])
					sec[j+1] = 1;
				else
					sec[j+1] = 0;
			}

			for(j = 1; j <= n; j++)
			{
				if(first[j] != sec[j])
				{
					if(sec[j] == 0)
					{
						printf("Move %d from B1 to B2\n",j);
					}
					else
					{
						printf("Move %d from B2 to B1\n",j);

					}
				}
			}


			for(j = 1; j <= n; j++)
			{
				first[j] = sec[j];
			}

			v1.clear();
		}

		cout << endl;

	}
	return 0;
}

void cal(int num)
{
	int a,b;
	a = num;
	while(a>0)
	{
		b = a%2;
		a = a/2;
		v1.push_back(b);
	}

	while(v1.size() < s)
	{
		v1.push_back(0);
	}

    reverse(v1.begin(),v1.end());

}