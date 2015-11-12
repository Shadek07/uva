#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(void)
{
	int h1,m1,h2,m2;
	int cnt;
	int res;

	while(1)
	{
		cin >> h1 >> m1 >> h2 >> m2;
		if(!h1 && !m1 && !h2 && !m2)
			break;
		
		cnt = h2 - h1;
		if((cnt == 0 && m1 > m2) || (h1 > h2))
		{
			res = (24 - h1)*60;
			res -= m1;
			res += h2*60;
			res += m2;
			cout << res << endl;
		}
		else
		{
			cnt *= 60;
			if(m1 < m2)
			{
				cnt += (m2-m1);
				
			}
			if(m1 > m2)
			{
				cnt -= (m1-m2);
			}
			cout << cnt << endl;
		}
	}

	return 0;
}