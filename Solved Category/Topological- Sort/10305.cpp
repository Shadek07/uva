#include<iostream>
#include<algorithm>

using namespace std;

int indegree[101];
bool taken[101];
bool check[101][101];

int main(void)
{
	int m,n,i,j,k,a,b;

	int count;

	while(cin >> m >> n)
	{
		if(!m && !n)
			break;

		memset(indegree,0,sizeof(indegree));
		memset(taken,false,sizeof(taken));
		memset(check,false,sizeof(check));

		count = 0;
		for( i = 0; i < n; i++)
		{
             cin >> a >> b;
             indegree[b]++;
			 check[a][b] = true;
		}

		while(count != m)
		{
			for(i = 1; i <= m; i++)
			{
				if(indegree[i] == 0 && taken[i] == false)
				{
					cout << i;

					count++;

					if( count != m)
						cout << " ";
					else
						cout << "\n";
					taken[i] = true;
					for( j = 1; j <= m; j++)
					{
                        if(check[i][j] == true)
						{
							indegree[j]--;
							check[i][j] = false;
						}
					}
				}
			}
		}

	}

	return 0;
}