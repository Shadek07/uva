#include<iostream>
using namespace std;

unsigned long long int s[1000002];

void precalculate()
{
	unsigned long long int square,i,j,k;
	unsigned long long int tmp;
	j = 1;
	s[3] = 0;
	k = 2;
	tmp = 0;
	for( i = 4; i <= 1000000; i++)
	{
		if(i%2 == 0)
		{
			s[i] = s[i-1] + j*j;
			j++;

		}
		else
		{
			s[i] = s[i-1] + tmp + k;
			tmp = tmp + k;
			k += 2;

		}
	}

}

int main(void)
{
	int t,i;

	precalculate();

	cin >> t;

	while(t--)
	{
		cin >> i;

		cout << s[i] << endl;
	}

	return 0;
}