#include<iostream>
#include<cmath>

using namespace std;

int value[1000];
int main(void)
{

	int m,num,n,i,j,k,tmp,closest,tmp1,ca = 1,sum;

	while(1)
	{
		cin >> m;
		if(!m)
			break;
		for(i = 0; i < m; i++)
		{
			cin >> value[i];
		}

		cin >> n;

		cout << "Case " << ca++ << ":\n";

		for( k = 0; k < n; k++)
		{
			cin >> num;

			tmp = value[0] + value[1];

			sum = tmp;
			closest = abs(tmp-num);

			for( i = 0; i < m-1; i++)
			{
				for( j = i+1; j < m;j++)
				{
					tmp = value[i] + value[j];
					
                    tmp1 = abs(tmp-num);
					if( tmp1 < closest)
					{
			          closest = tmp1;
					  sum = tmp;
					}

				}
			}

			cout << "Closest sum to " << num <<" is " << sum << ".\n";



		}

	}

	return 0;
}