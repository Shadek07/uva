#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;



#define F(i,start,limit) for(i = start;i < limit;i++)

int m,n;
long int mat[20][210];
long int dp[20][210];
int parent[20][210];
int save[20];

vector<int> v[20][210];

//parent[i][j] is 0, if it is parent of itself
//parent[i][j] is 1, if i,j-1 is parent of i,j
//parent[i][j] is 2, if i-1,j-1 is parent of i,j
//parent[i][j] is 3, if i+1,j-1 is parent of i,j
//parent[i][j] is 4, if m-1,j-1 is parent of i,j or 0,j-1 is parent of i,j(wrapping)

struct path
{
	int row[210];

}sh[20];

bool comp(path a,path b)
{
	int i;
	for(i = 0; i < n;i++)
	{
		if(a.row[i] < b.row[i])
			return true;
		if(a.row[i] > b.row[i])
			return false;
	}

	return true;
}

int check(int i,int j,int i1,int j1)
{
	int k,a,b;
	
	for(k = 0; k < v[i][j].size();k++)
	{
		a = v[i][j][k];
		b = v[i1][j1][k];
		if(v[i][j][k] < v[i1][j1][k])
			return 1;
		else if(v[i][j][k] > v[i1][j1][k])
			return 0;
	}
	
	return 1;
	
}

void calculate()
{
	long int mn,i,j,k;
	long int prev;
	long int x,y,a1;
	int flag;

		F(i,0,m)
		{
			dp[i][0] = mat[i][0];
			parent[i][0] = 0;
			v[i][0].push_back(i);
		}

		F(j,1,n)
		{
			F(i,0,m)
			{
				if(i == 0)
				{
					mn = dp[i][j-1] + mat[i][j];
					parent[i][j] = 1;
					x = i;
					y = j-1;
					if(dp[i+1][j-1] + mat[i][j] < mn)
					{
						mn = dp[i+1][j-1] + mat[i][j];
						parent[i][j] = 3;
						x = i+1;
						y = j-1;
					}
					else if(dp[i+1][j-1] + mat[i][j] == mn)
					{
						flag = check(i,j-1,i+1,j-1);
						if(flag == 1)
						{
							parent[i][j] = 1;
						}
						else
						{
							x = i+1;
							y = j-1;
							parent[i][j] = 3;
						}
					}
					if(m > 2)
					{
						prev = parent[i][j] ;
						if(dp[m-1][j-1] + mat[i][j] < mn)
						{
							mn = dp[m-1][j-1] + mat[i][j];
							parent[i][j] = 4;
							x = m-1;
							y = j-1;
						}
						else if(dp[m-1][j-1] + mat[i][j] == mn)
						{
							flag = check(x,y,m-1,j-1);
							if(flag == 1)
								parent[i][j] = prev;
							else
								parent[i][j] = 4;

						}

					}

					if(parent[i][j] == 1)
					{
						for(k = 0; k < v[i][j-1].size();k++)
							 v[i][j].push_back(v[i][j-1][k]),a1 = v[i][j][k];
						v[i][j].push_back(i);
						a1 = v[i][j][k];
					}
					else if(parent[i][j] == 3)
					{
						for(k = 0; k < v[i+1][j-1].size();k++)
							v[i][j][k],v[i][j].push_back(v[i+1][j-1][k]),a1 = v[i][j][k];
						v[i][j].push_back(i);
						a1 = v[i][j][k];

					}
					else if(parent[i][j] == 4)
					{
						for(k = 0; k < v[m-1][j-1].size();k++)
							 v[i][j][k],v[i][j].push_back(v[m-1][j-1][k]),a1 = v[i][j][k];
						v[i][j].push_back(i);
						a1 = v[i][j][k];

					}

					dp[i][j] = mn;
				}
				else if(i == m-1)
				{
					if(m > 2)
					{
						mn = dp[0][j-1] + mat[i][j];
						parent[i][j] = 4;
						x = 0;
						y = j-1;
						if(dp[i-1][j-1] + mat[i][j] < mn)
						{
							mn = dp[i-1][j-1] + mat[i][j];
							parent[i][j] = 2;
							x = i-1;
							y = j-1;
						}
						else if(dp[i-1][j-1] + mat[i][j] == mn)
						{
							flag = check(0,j-1,i-1,j-1);
							if(flag == 1)
								parent[i][j] = 4;
							else
							{
								x = i-1;
								y = j-1;
								parent[i][j] = 2;
							}

						}

						prev = parent[i][j];
						if(dp[i][j-1] + mat[i][j] < mn)
						{
							mn = dp[i][j-1] + mat[i][j];
							parent[i][j] = 1;
							x = i;
							y = j-1;
						}
						else if(dp[i][j-1] + mat[i][j] == mn)
						{
							flag = check(x,y,i,j-1);
							if(flag)
								parent[i][j] = prev;
							else
							parent[i][j] = 1;

						}

						if(parent[i][j] == 1)
						{
							for(k = 0; k < v[i][j-1].size();k++)
								v[i][j][k],v[i][j].push_back(v[i][j-1][k]),a1 = v[i][j][k];
							v[i][j].push_back(i);
							a1 = v[i][j][k];
						}
						else if(parent[i][j] == 2)
						{
							for(k = 0; k < v[i-1][j-1].size();k++)
								v[i][j][k],v[i][j].push_back(v[i-1][j-1][k]),a1 = v[i][j][k];
							v[i][j].push_back(i);
							a1 = v[i][j][k];

						}
						else if(parent[i][j] == 4)
						{
							for(k = 0; k < v[0][j-1].size();k++)
								v[i][j][k],v[i][j].push_back(v[0][j-1][k]),a1 = v[i][j][k];
							v[i][j].push_back(i);
							a1 = v[i][j][k];

						}
					}
					else
					{
						mn = dp[i-1][j-1] + mat[i][j];
						parent[i][j] = 2;
						x = i-1;
						y = j-1;
						if(dp[i][j-1] + mat[i][j] < mn)
						{
							mn = dp[i][j-1] + mat[i][j];
							parent[i][j] = 1;
							x = i;
							y = j-1;
						}
						else if(dp[i][j-1] + mat[i][j] == mn)
						{
							flag = check(x,y,i,j-1);
							if(flag)
								parent[i][j] = 2;
							else
								parent[i][j] = 1;
						}

						if(parent[i][j] == 1)
						{
							for(k = 0; k < v[i][j-1].size();k++)
								v[i][j].push_back(v[i][j-1][k]),a1 = v[i][j][k];
							v[i][j].push_back(i);
							a1 = v[i][j][k];
						}
						else if(parent[i][j] == 2)
						{
							for(k = 0; k < v[i-1][j-1].size();k++)
								v[i][j][k],v[i][j].push_back(v[i-1][j-1][k]),a1 = v[i][j][k];
							v[i][j].push_back(i);
							a1 = v[i][j][k];

						}
						

					}

					dp[i][j] = mn;

				}
				else
				{
					mn = dp[i-1][j-1] + mat[i][j];
					parent[i][j] = 2;
					x = i-1;
					y = j-1;
					if(dp[i][j-1] + mat[i][j] < mn)
					{
						mn = dp[i][j-1] + mat[i][j];
						parent[i][j] = 1;
						x = i;
						y = j-1;
					}
					else if(dp[i][j-1] + mat[i][j] == mn)
					{
						flag = check(x,y,i,j-1);
						if(flag)
						{
							parent[i][j] = 2;
						}
						else
						{
							x = i;
							y = j-1;
							parent[i][j] = 1;
						}
					}

					prev = parent[i][j];
					if(dp[i+1][j-1] + mat[i][j] < mn)
					{
						mn = dp[i+1][j-1] + mat[i][j];
						parent[i][j] = 3;
					}
					else if(dp[i+1][j-1] + mat[i][j] == mn)
					{
						flag = check(x,y,i+1,j-1);
						if(flag)
							parent[i][j] = prev;
						else
							parent[i][j] = 3;
					}

					if(parent[i][j] == 1)
					{
						int a1;
						for(k = 0; k < v[i][j-1].size();k++)
							 v[i][j].push_back(v[i][j-1][k]),a1 = v[i][j][k];
						v[i][j].push_back(i);
						a1 = v[i][j][k];
					}
					else if(parent[i][j] == 2)
					{
						int a1;
						for(k = 0; k < v[i-1][j-1].size();k++)
						{
							 v[i][j].push_back(v[i-1][j-1][k]),a1 = v[i][j][k];
							
						}
						v[i][j].push_back(i);
						a1 = v[i][j][k];
						

					}
					else if(parent[i][j] == 3)
					{
						int a1;
						for(k = 0; k < v[i+1][j-1].size();k++)
							v[i][j].push_back(v[i+1][j-1][k]),a1 = v[i][j][k];
						v[i][j].push_back(i);
						a1 = v[i][j][k];

					}

					dp[i][j] = mn;

				}
			}
		}
}
int main(void)
{
	long int i,j;
	long int sum,mn,ind,a;
	long int cnt;
	while(cin >> m >> n)
	{
		F(i,0,m)		
			F(j,0,n)
				cin >> mat[i][j];

		//cout << mat[1][0];
		if(m == 1)
		{
			sum = 0;
			F(j,0,n)
				sum += mat[0][j];
			cout << 1;
			F(j,1,n)
				cout << " 1";
			cout << endl;
			cout << sum << endl;
			continue;
		}
		if(n == 1)
		{
			mn = mat[0][0];
			ind = 1;
			F(j,1,m)
			{
				if(mat[j][0] < mn)
				{
					mn = mat[j][0];
					ind = j+1;
				}
			}

			cout << ind << endl;
			cout << mn << endl;
			continue;
		}

        calculate();

		
		mn = dp[0][n-1];

		//cout << mn << endl;
		/*F(i,0,m)
		{
			F(j,0,n)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/

		//cout << " par " << parent[1][1] << endl;

		F(i,1,m)
		{
			if(dp[i][n-1] < mn)
				mn = dp[i][n-1];
		}

		cnt = 0;
		ind = 0;
		F(i,0,m)
		{
			if(dp[i][n-1] == mn)
			{
				save[ind++] = i;
				//cout << "select:" << i+1;
			}
		}

		int r,c,col;
		col = n-1;
		int x,y,flag;

		x = save[0];
		y = n-1;
		
        //cout << "ind: " << ind << endl;
		F(i,1,ind)
		{
			flag = check(x,y,save[i],n-1);
			//cout << "flag: " << flag << endl;
			if(!flag)
				x = save[i];
		}

		cout << v[x][n-1][0] + 1;

		for(i = 1;i<v[x][n-1].size();i++)
		{
			cout << " " << v[x][n-1][i] + 1;
		}
		cout << endl;

	

	

		cout << mn << endl;


		for(i = 0; i < m;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(!v[i][j].empty())
					v[i][j].clear();
			}
		}
		
	}

	return 0;
}