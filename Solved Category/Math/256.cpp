#include<iostream>
#include<stdio.h>

#include<math.h>



using namespace std;
void count(int n)
{

   long i,a,b,c;
   
   long x,y;

    int s[] = {4941729,7441984,24502500,25502500,52881984,60481729,99980001};

   if(n==2)
   {
	   cout << "00\n" << "01\n" << "81\n";
	    return;
	   x=100; y=10; 
   }
   if(n==4)
   { 
	  cout<< "0000\n" << "0001\n" <<  "2025\n" <<  "3025\n" << "9801\n";
	   return; 
	  x=10000; y=100;
   }
   if(n==6)
   { 
	   cout << "000000\n" <<  "000001\n" << "088209\n" <<  "494209\n" << "998001\n";
	    return;
	   x=1000000; y=1000;
   }
   if(n==8)
   {
	  cout << "00000000" << endl << "00000001" << endl;
	   cout << "0" << 4941729 << endl << "0" << 7441984 << endl << 24502500 << endl << 25502500 << endl << 52881984 << endl << 60481729 << endl << 99980001 << endl;
	   return;
	   x=100000000; y=10000;
   }

   for(i=0;i<x;i++)
   {
	   a=i/y;
	   b=i%y;
         
	   c=(a+b)*(a+b);

	   if(c==i)
		   printf("%0*d\n",n,i);
   }

}

int main()
{

    
   int n; 

   while(scanf("%d",&n)!=EOF)
   {
	   count(n);
   }

   return 0;

       
 
}