#include<cstdio>
#include<algorithm>
using namespace std;
int deg[1005];
bool flag,found;
bool neg(int n)
{
   int i;
   for(i=1; i<=n; i++)
   {
     if(deg[i]<0)
       return true;
       }
   return false;  
}
bool allzero(int n)
{
   int i;
   for(i=1; i<=n; i++)
   {
      if(deg[i]!=0)
         return false;      
   }
   return true;  
}
int main()
{
   int t,i,j,n,odd,x;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      odd=0;
	  if(n == 0)
	  {
		  printf("Yes\n");
		  continue;
	  }
      for(i=1; i<=n; i++) 
      {
          scanf("%d",&deg[i]);
          if(deg[i]%2) odd++;
          }
      if(odd%2)
      {
          printf("No\n");
          continue;      
      }    
      sort(deg+1,deg+n+1);
      if(deg[n]>n-1)
      {
          printf("No\n");
          continue;             
      }
      
      flag=false;    
      while(n>0)
      {
          if(n==1 && deg[1]!=0)
          {
             flag=false;
             break;     
          }
          if(neg(n))
          {
             flag=false;
             break;       
          }
          if(allzero(n))
          {
             flag=true;
             break;           
          }
          
          sort(deg+1,deg+1+n);
          x=deg[n];
          n--;
          for(i=n; x>0 && i>0;x--,i--)
            deg[i]--;
      }
      
    
      
          if(flag) 
            printf("Yes\n");
          else
            printf("No\n");
      
   }
   return 0; 
}
 