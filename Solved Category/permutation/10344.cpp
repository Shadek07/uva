#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define a 0
#define b 1
#define c 2

int main(void)
{
	int a1,a2,a3,a4,a5;
	int i,j,k,l;
	int res;
	int pos;
	int info[7];
	int arr[6];

	while(1)
	{
		cin >> a1 >> a2 >> a3 >> a4 >> a5;

		info[1] = a1;
		info[2] = a2;
		info[3] = a3;
		info[4] = a4;
		info[5] = a5;

		if(!a1 && !a2 && !a3 && !a4 && !a5)
			break;
		
		pos = 0;
        
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 4;
		arr[4] = 5;

		do
		{

			for( i = 0;i <=2; i++)
			{
				for( j = 0; j <=2; j++)
				{
					for( k = 0; k <=2; k++)
					{
						for( l = 0; l <=2; l++)
						{
						    if(i == 0)
								res  = info[arr[0]] + info[arr[1]];
							else if(i == 1)
								res  = info[arr[0]] - info[arr[1]];
							else
								res  = info[arr[0]] * info[arr[1]];

							if(j == 0)
								res += info[arr[2]];
							else if(j == 1)
								res -= info[arr[2]];
							else
								res *= info[arr[2]];

							if(k == 0)
								res += info[arr[3]];
							else if(k == 1)
								res -= info[arr[3]];
							else
								res *= info[arr[3]];

							if(l == 0)
								res += info[arr[4]];
							else if(l == 1)
								res -= info[arr[4]];
							else
								res *= info[arr[4]];

							if(res == 23)
							{
								pos = 1;
								goto nt;
							}



						}
					}
				}
			}
		}while(next_permutation(arr,arr+5));

nt:
		if( pos == 1)
		{
			cout << "Possible\n";
		}
		else
			cout << "Impossible\n";
	}


	return 0;
}
