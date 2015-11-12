#include<stdio.h>
#include<iostream>

using namespace  std;

#define MAXTRI 101
unsigned long int pas[MAXTRI][MAXTRI];
void pascals(int n)
{


register int i,j;
pas[0][0]=1;
pas[1][0]=pas[1][1]=1;
for(i=2;i<=n;i++)
{
pas[i][0]=1;
for(j=1;j<i;j++)
{
pas[i][j]= pas[i-1][j-1]+pas[i-1][j];
}
pas[i][j]=1;
}
}
int main(void)
{
pascals(100);
int n,m;
while(1)
{
	scanf("%d %d",&n,&m);
		if(!n && !m)
			break;
		cout << n <<" things taken " << m << " at a time is "; 
		printf("%lu",pas[n][m]);
		cout << " exactly.\n";   
}
return 0;
}