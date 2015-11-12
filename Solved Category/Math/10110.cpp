#include<iostream>
#include<cmath>

using namespace std;

//int prime_factorization(long x);

int main(void)
{
    unsigned long int n,a;
    
    //int num_divisor;
    
    
    while(1)
    {
        cin >> n ;
        if(!n) break;

	

		a = sqrt(n);

		a = a*a;

		if( a == n)
			cout << "yes\n";
		else
			cout << "no\n";
        
        
       
       
          
    }
    
  
   
   return 0;   
}


int prime_factorization(long x)
{
       long i; /* counter */
       long c; /* remaining product to factor */
       int count = 0;
       int div = 1;
       //int prev;
       //int front;
       c = x;
       while ((c % 2) == 0)
       {
          printf("%ld\n",2);
          count += 1;
          
          c = c / 2;
       }
       
       i = 3;
       div *= (count + 1);
       count = 0;
       while (i <= (sqrt(c)+1))
       {
           if ((c % i) == 0) 
           {
               //printf("%ld\n",i);
               count += 1;
               
               c = c / i;
           }
           else
           {
               
              i = i + 2;
              div *= (count + 1);
              count = 0;
           }
      }

	   
      
      if (c > 1) 
      {
           // printf("%ld\n",c); 
            count += 1;
            div *= (count+1);
      }
      
	  
      return div;
      
}
