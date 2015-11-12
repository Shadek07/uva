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
  while(n!=0)
  {
    t=0;
    printf("%d = ",n);
    if(n==1)
        printf("%d",n);
    if(n<0)
    {
        printf("-1");
        t=1;
        n=-n;
    }
    i=1;
    m=n;
    while(n!=1&&a[i]<=sqrt(m)&&i<=4792)
    {
        if(n%a[i]==0)
        {
            n=n/a[i];
            if(t!=0)
                printf(" x %d",a[i]);
            else
                printf("%d",a[i]);
            t++;
        }
        else
            i++;
    }
    if(n!=1)
    {
      if(t==0)
        printf("%d",n);
      else
        printf(" x %d",n);
    }
    printf("\n");
    scanf("%d",&n);
  }
  
  return 0;
}