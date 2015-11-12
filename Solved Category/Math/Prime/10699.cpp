#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
  int n,i,t,m,a[4800],k;
  k=0;
  for(i=2;i<=46342;i++)
  {
    t=0;
    n=2;
    while(n<=sqrt(i)&&t==0)
    {
        if(i%n==0)
            t=1;
        else
            n++;
    }
    if(t==0)
    {
        k++;
        a[k]=i;
    }
  }
  scanf("%d",&n);
  int cnt;
  int num;
  while(n!=0)
  {
    t=0;
   
	cnt = 0;
	num = -1;
   
    i=1;
    m=n;
    while(n!=1&&a[i]<=sqrt(m)&&i<=4792)
    {
        if(n%a[i]==0)
        {
            n=n/a[i];
			if(num != a[i])
			{
				cnt++;
				num = a[i];
			}
            
            t++;
        }
        else
            i++;
    }
    if(n!=1)
    {
      if(num != n)
		  cnt++;
    }
    printf("%d : %d\n",m,cnt);
    scanf("%d",&n);
  }
  
  return 0;
}