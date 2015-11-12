#include<iostream>
#include<cmath>
using namespace std;
int prime(int n)
{
   int i;
   if(n==2)
      return 1;
   if(n%2==0)
      return 0;
   for(i=3;i<=sqrt(n);i+=2)
      if(n%i==0)
         return 0;
   return 1;
}
int main(void)
{
    
    int save[1000][2];
    int i,k,l,m,n = 0;
    int num;
    
    while(1)
    {
         
         cin >> num;
         if( num == 0)
         break;
         m = ceil(num/2);
         for( i = 2; i <= m ; i++)
         {
              
              if( prime(i) && prime(num-i))
              n++;
              
         } 
         
         cout << n << endl;
         n = 0;  
            
    }
    
    
    return 0;
}
