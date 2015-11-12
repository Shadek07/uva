#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int indegree[120];
bool taken[120];
bool check[120][120];

int cnt[120];

int main(void)
{
	int i,j,k,a,b,a1;

	int count;
	int task;
	int num;

	while(1)
	{
		cin >> task;
		if(!task)
			break;
		j = 1;

		memset(indegree,0,sizeof(indegree));
		memset(taken,false,sizeof(taken));
		memset(check,false,sizeof(check));
		memset(cnt,0,sizeof(cnt));

		a = task;

		while(a--)
		{
			cin >> num;
			
			for(i = 0; i < num; i++)
			{
				cin >> k;
				indegree[j]++;
				check[k][j] = true;
			}

			j++;

		}

		count = 0;

		

		while(count != task)
		{
			for(i = 1; i <= task; i++)
			{
				if(indegree[i] == 0 && taken[i] == false)
				{
					count++;
					taken[i] = true;
					for( j = 1; j <= task; j++)
					{
                        if(check[i][j] == true)
						{
							indegree[j]--;
							cnt[j] = cnt[i] + 1;
							check[i][j] = false;
						}
					}
				}
			}
		}

		a = cnt[1];
		b = 1;

		

		for( i = 2; i <= task ; i++)
		{
			
			if(cnt[i] > a)
			{
                b = i;
				a = cnt[i];
			}
		}

		
		cout << b << endl;

	}

	return 0;
}