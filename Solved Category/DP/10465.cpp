#include <stdio.h>

int main() 
{
   long i,j,m,n,t,max,waste,time;
   long diff;
   while( scanf("%ld %ld %ld",&m,&n,&t)!=EOF ) 
   {
      max=0;
      time=0;
      waste=0;
	  diff = t;
      for(i=0;m*i<=t;i++)
         for(j=0;m*i+n*j<=t;j++) 
		 {
			 long a = t - (m*i+n*j);

            if(m*i+n*j==t && i+j>max) 
			{
				max=i+j; 
			}
            /*else if(i+j>waste) 
			{ 
				waste=i+j; time=m*i+n*j; 
			}*/
			else if(a < diff)
			{
				diff = a;
				waste = i+j;
			}
			else if( a == diff)
			{
				if( i+j > waste)
					waste = i+j;
			}
         }
      //if(max==0) printf("%ld %ld\n",waste,t-time);
	  if(max==0) printf("%ld %ld\n",waste,diff);
      else printf("%ld\n", max);
   }
   return 0;
}
