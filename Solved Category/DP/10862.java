import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;





class Main{
    public static void main(String[] args)
    	{
	Scanner scanner= new Scanner(System.in);
	BigInteger mini,maxi,ne,ni;
	BigInteger dp[] = new BigInteger [4001];
	int i,j,k;
	int N,A;
	int s;
	
	
	
	dp[1] = BigInteger.ONE;
	dp[2] = BigInteger.valueOf(2);
	
	
	for(i = 3;i<4000;i++)
	{
	    dp[i] = dp[i-1].add(dp[i-2]);
		
	}
	

	
   
	
			while(scanner.hasNextInt())
			{ 
			    
				i = scanner.nextInt();
				if(i == 0)
				break;
				System.out.println(dp[2*i-1]);				
				
		    }
    	}
}

