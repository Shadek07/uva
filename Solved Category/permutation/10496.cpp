#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
int m,n;
int point[20][2];
int perm[20];
int main(void)
{
	int t,a,i;
	int x,y; //starting position
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		cin >> x >> y;
		cin >> a;

		for(i = 0;i < a;i++)
		{
			cin >> point[i][0] >> point[i][1];
		}

		int mx = 0;
		int temp;

		mx += abs(point[0][0] - x) + abs(point[0][1] - y);

		for(i = 1;i < a;i++)
		{
			mx += abs(point[i][0] - point[i-1][0]) +  abs(point[i][1] - point[i-1][1]);
		}

		mx += abs(point[a-1][0] - x) + abs(point[a-1][1] - y);

		for(i = 0;i < a;i++)
			perm[i] = i;
		do
		{
			temp = 0;
			temp += abs(point[perm[0]][0] - x) + abs(point[perm[0]][1] - y);
			for(i = 1;i < a;i++)
			{
				temp += abs(point[perm[i]][0] - point[perm[i-1]][0]) +  abs(point[perm[i]][1] - point[perm[i-1]][1]);
			}

			temp += abs(point[perm[a-1]][0] - x) + abs(point[perm[a-1]][1] - y);
			if(temp < mx)
				mx = temp;

		}while(next_permutation(perm,perm+a));

		cout << "The shortest path has length " << mx << endl;

	}
	return 0;
}