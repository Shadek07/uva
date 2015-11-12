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
	BigInteger t[] = new BigInteger [50];
	int i,j,k;
	int N,A;
	int s;
	
	ne = new BigInteger("4");
	maxi = new BigInteger("2");
	
	t[0] = new BigInteger("1");
	t[1] = new BigInteger("1");
	t[2] = new BigInteger("5");
//	t[3] = new BigInteger("7");
	
	for(i = 3; i <= 40; i++)
	{
		mini = t[i-2];
		mini = mini.multiply(ne);
		mini = mini.add(t[i-1]);
		ni = t[i-3];
		ni = ni.multiply(maxi);
		mini = mini.add(ni);
		t[i] = mini;
	   
		
	
		
	}
	

	

//while(System.in.read() != -1) 

     N = scanner.nextInt();
	
	while(N-->0)
	{ 
	    
		A = scanner.nextInt();
		//System.out.println(N);
		
		System.out.println(t[A]);
		
		
		
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

