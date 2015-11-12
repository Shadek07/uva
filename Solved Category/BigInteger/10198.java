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
	BigInteger t[] = new BigInteger [1005];
	BigInteger s[] = new BigInteger [50];
	int i,j,k;
	int N,A;
	
	t[1] = new BigInteger("2");
	t[2] = new BigInteger("5");
	t[3] = new BigInteger("13");
	
	for(i = 4; i <= 1000; i++)
	{
		mini = t[i-3].add(t[i-2]);
		maxi = t[i-1];
		maxi = maxi.multiply(new BigInteger("2"));
		t[i] = mini;
		t[i] = t[i].add(maxi);
		
	
		
	}
	
	
	

//while(System.in.read() != -1) 
	
	while(scanner.hasNextInt() )
	{ 
		N = scanner.nextInt();
		
		//System.out.println(N);
		
		maxi = t[N];
		
		
		
		
		System.out.println(maxi);
		
		
		
    }
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

