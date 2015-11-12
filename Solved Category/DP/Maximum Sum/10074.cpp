#include<iostream>

using namespace std;

int arr[105][105];

int in[105];

int main(void)
{

	int image = 1;
	int t,len,i,j,k;

	int c;

	int m,n;

	while(1)
	{
		cin >> m >> n;

		getchar();

		if(m == 0 && n == 0)
			break;

                

				

				for( i = 0; i < n;i++)
				{
					cin >> in[i];
					if(in[i] == 0)
						in[i] = 1;
					else
						in[i] = 0;
					arr[0][i] = in[i];
				}

				for( i = 1; i < m;i++)
				{
					for( j = 0; j < n;j++)
					{
						cin >> c;
						if(c == 0)
						c = 1;
						else
							c = 0;
						arr[i][j] = c;
					}

					
				}

				//getchar();

				for( i = 0; i < m; i++)
				{

					for( j = 1; j < n; j++)
					{
						if( arr[i][j] == 1)
							arr[i][j] = arr[i][j-1] + 1;
						else
							arr[i][j] = 0;
					}
				}

				int max = 0;

				int temp;

				for( i = 0; i < m; i++)
				{
					for( j = 0; j < n; j++)
					{
						if( arr[i][j] > 0)
						{
							 temp = 0;

							 temp = arr[i][j];

							 int i1 = i;

							 while(--i1 >= 0)
							 {
								 if(arr[i1][j] >= arr[i][j])
									 temp += arr[i][j];
                                 else
                                      break;
							 }

							 i1 = i;

							 while(++i1 < m)
							 {
								 if(arr[i1][j] >= arr[i][j])
									 temp += arr[i][j];
									 else
                                      break;
							 }

							 if( temp > max)
								 max = temp;

						}
					}
				}

				

				cout << max << endl;

				
	}

	return 0;
}
