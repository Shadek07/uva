#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{
	int m,n;
	int ca = 1;
	int i,k,j,a,b,c,l;
	int space1,space2,inter_space,outer_space,under;
	while(1)
	{
		cin >> m >> n;   // n == level
		if(!m && !n)
			break;
		cout << "Triangular Museum " << ca++ << endl;
		space1 = m*n - 1;
		space2 = 2;
		inter_space = 2;

		for(i = 1; i <= n; i++)
		{
		

			inter_space = 0;
			outer_space = 2*(m-1);

			for(k = 1; k <= m; k++,inter_space += 2,outer_space -= 2)
			{
				
				for(j = 0; j < space1; j++)
				{
					cout << " ";
				}

				for(j = 1; j <= i; j++)
				{
					if(k == 1)
						cout << "/\\";
					else if(k == m)
					{
						cout << "/";
						under = 2*(m-1);
						for(l = 0; l < under; l++)
						{
							cout << "_";
						}
						cout << "\\";
					}
					else
					{
						cout << "/";
						for(l = 0; l < inter_space; l++)
						{
							cout << " ";
						}
						cout << "\\";

					}

					if(j != i)
					{
						for(l = 0; l < outer_space; l++)
						{
							cout << " ";
						}
					}

				}

				cout << endl;

				space1--;
			}

		}

		cout << endl;
	}
	return 0;
}