#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;

int sum1,sum2,sum,total;

int main(void)
{
	int k,z=0,tmp;
	int t;
	char c;
	cin >> t;

	while(t--)
	{
		sum = 0;
		total = 0;
		while(1)
		{
			cin >> k;
			c = getchar();
			sum += k;
			total++;
			v.push_back(k);
			if( c == '\n')
				break;
		}

		sort(v.begin(),v.end());
		sum1 = sum2 = 0;
		for(z = total-1; z > -1 ; z--)
		{
			if( sum1 > sum2)
			{
				 tmp = v[z];
                 sum2 += tmp;
			}
			else
			{
				tmp = v[z];
				sum1 += tmp;
			}

		}

		if( sum1 == sum2)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		v.clear();
	}


	return 0;
}
