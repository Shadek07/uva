#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int a,b;

	int i;

	double c;
	int total = 0;
	int cnt[100001];

	memset(cnt,0,sizeof(cnt));
	cnt[0] = 0;
	cnt[1] = 1;

	for(i = 2; i <= 100000; i++)
	{
		c = sqrt(i);
		if( (c - (int) c) == 0.0)
		{
			cnt[i] = cnt[i-1] + 1;
		}
		else
		{
			cnt[i] = cnt[i-1];

		}
	}


	scanf("%d %d", &a,&b);

	while( (a != 0) && (b != 0))
	{

	

		printf("%d\n",cnt[b] - cnt[a-1]);

		

		scanf("%d %d",&a,&b);
	}


	return 0;
}
