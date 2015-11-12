#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   long  i,j,x,val,temp=0,count,num,a,b,test,temp1;
   
   scanf("%ld",&test);
   
   while(test--)
      {
   
         scanf("%ld%ld",&a,&b);
         
        if(a>b)
        {
         temp1=a;
         a=b;
         b=temp1;
        }
        
       
        
      for(i=a;i<=b;i++)
      {
           count=0;
         
           x=(long)sqrt(i);
      

      for(j=1;j<=x;j++)
      {
         if(i%j==0)
            ++count;
      }

      if(x*x==i)
          val=2*count-1;
      else
         val=2*count;


      if(val>temp)
      {
         temp=val;
         num=i;
      }
   }

   printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",a,b,num,temp);
    temp = 0;  
   }
   
return 0;
}
