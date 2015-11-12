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
	BigInteger mini,maxi,ne,ni;
	BigInteger t[] = new BigInteger [1005];
	int i,j,k;
	int N,A;
	int s;
	

	
	t[1] = new BigInteger("1");
	t[2] = new BigInteger("2");
	t[3] = new BigInteger("5");
//	t[3] = new BigInteger("7");
	
	for(i = 4; i <= 1000; i++)
	{
		
		maxi = BigInteger.ONE;
		ne = BigInteger.ONE;
		for(j=i+2,k=1;j<=2*i||k<=i;k++,j++)
		{
			if(j<= 2*i)
			{
				maxi = maxi.multiply(BigInteger.valueOf(j));
			}
			if(k<= i)
			{
				ne = ne.multiply(BigInteger.valueOf(k));
			}
			
			BigInteger m = maxi.remainder(ne);
			
			if(m == BigInteger.ZERO)
			{
				maxi = maxi.divide(ne);
				ne = BigInteger.ONE;
			}
		}
		
		t[i] = maxi;
	   
		
	
		
	}
	

	
			while(scanner.hasNextInt())
			{ 
			    
				A = scanner.nextInt();
				//System.out.println(N);
				
				System.out.println(t[A]);
				
				
				
		    }
    	}
}
