#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main(void)
{
	int w,h,t;
	bool arr[502][502];
	int i,j,k;
	int cnt;
	int x1,y1,x2,y2;
	char c;
	while(cin >> w >> h >> t && w && h && t)
	{
		memset(arr,false,sizeof(arr));
		cin.get(c);
		while(cin.peek() != '\n')
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) 
			{
				swap(x1, x2);
				swap(y1, y2);
			}

			if (y1 > y2) 
			{
				int tmpx1 = x1;
				int tmpy1 = y2;
				int tmpx2 = x2;
				int tmpy2 = y1;
				x1 = tmpx1;
				x2 = tmpx2;
				y1 = tmpy1;
				y2 = tmpy2;
			}
			for(j = x1;j<=x2;j++)
			{
				for(k = y1;k<=y2;k++)
				{
					arr[j][k] = true;
				}
			}
			cin.get(c);
		}

		cnt = 0;
		for(i = 1;i<=w;i++)
		{
			for(j = 1;j<=h;j++)
				if(arr[i][j]==false)
					cnt++;
		}

		if(cnt==0)
			cout << "There is no empty spots.\n";
		else if(cnt==1)
			cout << "There is one empty spot.\n";
		else
			cout << "There are " << cnt << " empty spots.\n";

	}
	return 0;
}
