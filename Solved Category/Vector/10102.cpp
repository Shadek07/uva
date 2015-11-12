#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

char in[10000][10000];

struct one
{
	int x;
	int y;
}p[10000];

struct three
{
	int x;
	int y;
}th[10000];

int main(void)
{
	vector<int> coll;
    
    vector<int>::iterator pos;

	int m,i,j;

	int o,t;

	while(cin >> m)
	{
		getchar();

		for( i = 0; i < m; i++)
		{
			gets(in[i]);
		}

		o = 0;
		t = 0;

		for( i = 0; i < m; i++)
		{
			for( j = 0; j < m; j++)
			{
				if( in[i][j] == '1')
				{
					p[o].x = i;
					p[o].y = j;
					o++;
				}
				if( in[i][j] == '3')
				{
					th[t].x = i;
					th[t].y = j;
					t++;
				}
			}
		}

		int min;

		for( i = 0; i < o; i++)
		{
			min = abs(p[i].x - th[0].x) + abs(p[i].y - th[0].y);

			for( j = 1; j < t; j++)
			{
                  int tmp;
				  tmp = abs(p[i].x - th[j].x) + abs(p[i].y - th[j].y);
				  if( tmp < min)
					  min = tmp;
			}

			coll.push_back(min);
		}

		pos = max_element (coll.begin(), coll.end());

		cout << *pos << endl;

		coll.clear();


	}

	return 0;
}