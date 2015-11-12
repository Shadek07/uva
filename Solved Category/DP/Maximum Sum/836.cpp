#include<iostream>

using namespace std;

int arr[25][25];

char in[26];

int main(void)
{

	int image = 1;
	int t,len,i,j,k;

	char c;

	cin >> t;

	getchar();
	getchar();
	while(t--)
	{

                gets(in);

				len = strlen(in);

				for( i = 0; i < len;i++)
				{
					arr[0][i] = in[i]-'0';
				}

				for( i = 1; i < len;i++)
				{
					for( j = 0; j < len;j++)
					{
						c = getchar();
						arr[i][j] = c-'0';
					}

					getchar();
				}

				//getchar();

				for( i = 0; i < len; i++)
				{

					for( j = 1; j < len; j++)
					{
						if( arr[i][j] == 1)
							arr[i][j] = arr[i][j-1] + 1;
						else
							arr[i][j] = 0;
					}
				}

				int max = 0;

				int temp;

				for( i = 0; i < len; i++)
				{
					for( j = 0; j < len; j++)
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

							 while(++i1 < len)
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

				if(image == 1)
					image = 0;
				else
					cout << endl;

				cout << max << endl;

				if(t > 0)
				   getchar();
	}

	return 0;
}
