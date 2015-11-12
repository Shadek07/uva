#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

int len,r;

char s[1001];
char p[1001];

int compare(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

void print(void)
{
	int i;
	for(i=0;i<r;i++)
		printf("%c",p[i]);

	printf("\n");
}

void doit(int pos,int depth)
{
	int i;
	if (depth == r) print(); 
	else
	for(i=pos;i<len;)
	{
		p[depth] = s[i];
		doit(i+1,depth+1);
		i++;
		while(s[i] == s[i-1]) 
			i++;
	}
}

int main(void)
{
	while(scanf("%s %d",&s,&r) == 2)
	{
		len = strlen(s);
		qsort(s,len,sizeof(char),compare);
		doit(0,0);
		memset(p,0,sizeof(p));
	}

	return 0;
}