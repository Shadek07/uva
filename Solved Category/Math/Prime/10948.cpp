#include<iostream.h> 
#include<math.h> 


#define P 1000002 


bool prime[P]; 


int main() 
{ 
     int i,j; 

    
    prime[0]=prime[1]=1; 

    for(i=2; i<=sqrt(P-1); i++) 
	{ 
       if(prime[i]==0)  //if prime
	   { 
           for(j=i*i; j<=P-1; j=j+i) 
		   { 
                prime[j]=1; 
		   } 
	   } 
	} 


	while(cin>>i) 
	{ 

		if(i==0) break; 


		for(j=2;j<=i/2;j++) 
		{ 
		        if( (prime[j]==0) && (prime[i-j]==0) ) 
					break; 

		} 

		if(j>(i/2)) 
			cout<< i << ":\n" << "NO WAY!\n"; 

		else 
		{ 
			 cout<<i<<":\n"<<j<<"+"<<(i-j)<<"\n"; 
		} 

	} 
    return 0; 
}