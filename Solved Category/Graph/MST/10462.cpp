#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define init(i,a,n) for(i=0;i<=n;i++)a[i]=i
#define inf 1000000
typedef struct edge
{
	int f,t,d;
}E;
int getParent(int i,int *set)
{
	if(i==set[i])
		return i;
	else
		return (set[i]=getParent(set[i],set));
}
int isUnion(int a,int b,int* set)
{
	return getParent(a,set)==getParent(b,set);
}
void makeUnion(int a,int b,int* set)
{
	set[getParent(a,set)] = getParent(b,set);
}
int cmp(const void*a,const void*b)
{
	return ((E*)a)->d-((E*)b)->d;
}
int main()
{
	int t,n,e,i,cc,set[105],d,mst,mst2,cmst,j;
	cc=1;
	E list[10005];
	char mark[10005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&e);
		for(i=0;i<e;i++)
			scanf("%d %d %d",&list[i].f,&list[i].t,&list[i].d);
		qsort(list,e,sizeof(E),&cmp);
		init(i,set,n);
		d = 0;
		mst = 0;
		for(i=0;i<e;i++)
			mark[i]=0;
		for(i=0;i<e&&d<n-1;i++)
		{
			if(!isUnion(list[i].f,list[i].t,set))
			{
				d++;
				makeUnion(list[i].f,list[i].t,set);
				mst+=list[i].d;
				mark[i]=1;
			}
		}
		if(d<n-1)
			printf("Case #%d : No way\n",cc++);
		else
		{
			mst2 = inf;
			for(i=0;i<e;i++)
			{
				if(mark[i])
				{

					init(j,set,n);
					cmst = 0;
					for(j=0;j<e;j++)
					{
						if(mark[j]&&j!=i)
						{
							makeUnion(list[j].f,list[j].t,set);
							cmst+=list[j].d;
						}
					}
					d = 0;
					for(j=0;j<e&&!d;j++)
					{
						if(!mark[j]&&!isUnion(list[j].f,list[j].t,set))
						{
							cmst+=list[j].d;
							d=1;
						}
					}
					if(d&&cmst<mst2)
						mst2 = cmst;
				}
			}
			if(mst2!=inf)
				printf("Case #%d : %d\n",cc++,mst2);
			else
				printf("Case #%d : No second way\n",cc++);
		}
	}
	return 0;
}
