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
	BigInteger dp[] = new BigInteger [5005];
	int i,j,k;
	int N,A;
	int s;
	
	for(i = 0;i<=5000;i++)
	dp[i]= BigInteger.ZERO;
	
	dp[0] = BigInteger.ONE;
	
	for(i = 1;i<=5000;i++)
	{
		k = i;
		for(j = i;j<=5000;j++)
		{
			dp[j] = dp[j].add(dp[j-k]);
		}
		
	}   
	
			while(scanner.hasNextInt())
			{ 
			    
				i = scanner.nextInt();
				System.out.println(dp[i]);				
				
		    }
    	}
}

