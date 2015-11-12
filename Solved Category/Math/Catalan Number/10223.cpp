#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

unsigned long int save[25] = {
	
1
,
2,

5,

14,

42,

132,

429,

1430,

4862,

16796,

58786,

208012,

742900,

2674440,

9694845,

35357670,

129644790,

477638700,

1767263190,

6564120420

};

int main(void)
{

	unsigned long int n;
	int i,j;

	while(cin >> n)
	{
		for(i = 0; i < 20; i++)
		{
			if(save[i] > n)
				break;
		}

		cout << i << endl;

	}

	return 0;
}