import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;



//java.lang.Math.pow(n,2);


class Main{
    public static void main(String[] args)
    	{
	Scanner scanner= new Scanner(System.in);
	BigInteger mini,maxi,ne;
	
	BigInteger s[] = new BigInteger[802];
	int i,j,k;
	int N;
	
	s[1] = BigInteger.ZERO;
	s[2] = BigInteger.ONE;
	
	for(i = 3;i <= 800; i++)
	{
		mini = BigInteger.valueOf(i-1);
		maxi = s[i-1].add(s[i-2]);
		s[i] = mini.multiply(maxi);
	}
	

//while(System.in.read() != -1) 
	
	while(true)
	{ 
		N = scanner.nextInt();
		if( N == -1)
			break;
		//System.out.println(N);
		BigInteger a,b,factorial,sum,next;
		
		maxi = BigInteger.ZERO;
		next = BigInteger.ONE;
		
		System.out.println(s[N]);
		
		
			//BigInteger c = new BigInteger(String.valueOf(i));
		//	ne = c.multiply(BigInteger.valueOf(A).pow(i));
			//maxi = maxi.add(ne);
			
		/*	if(N == 1)
			{
				System.out.println("0");
				continue;
			}
			
			
		factorial = calculate(N);
		
		sum = factorial;
		
		for(i = 1; i <= N; i++)
		{
			next = next.multiply(BigInteger.valueOf(i));
			if(i%2 == 1)
			{
				sum = sum.subtract(factorial.divide(next));
			}
			else
			{
				sum = sum.add(factorial.divide(next));
				
			}
		}	
		
		
		System.out.println(sum);*/
		
		
		
    }
    	}
    	
    	
    	
    		   static BigInteger calculate(int n)
		    	{
		    		int i;
		    		
		    		BigInteger a =  BigInteger.ONE;
		    		for(i = 1; i <= n; i++)
		    		{
		    			a = a.multiply(BigInteger.valueOf(i));
		    		}
		    		
		    		return a;
		    	}
    	
    	
    
}

/*
 for( i = 4; i <= 32;i++)
	{
		ne =  BigInteger.valueOf(2).pow(i);
		maxi = ne.subtract(t[i]);
		s[i] = maxi;
		
	}
	
	while(true)
		{
			i = scanner.nextInt();
			if(i == 0)
				break;
				
		   
		   // ne =  BigInteger.valueOf(2).pow(i);

		    
		   // maxi = ne.subtract(t[i]);
		    
		    System.out.println(s[i]);	
		    
	  }

 */

