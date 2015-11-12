import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;



//java.lang.Math.pow(n,2);


class Main
{
    public static void main(String[] args)
    {
	Scanner scanner= new Scanner(System.in);
	BigInteger mini,maxi,ne,ni;
	BigInteger dp[][] = new BigInteger [2005][2];
	int i,j,k;
	int N,A;
	int s;
	
	//dp[n][0] ->number of all numbers that can be formed by less than n matches
	//dp[n][1] -> number of all numbers that can be formed by using exactly n matches
	
	for(i = 0;i<=2000;i++)
	{
		dp[i][1] = BigInteger.ZERO;
		dp[i][0] = BigInteger.ZERO;
		
	}
	
	dp[0][1] = BigInteger.ONE;
	
	
	//dp[0] = BigInteger.ONE;
	dp[2][0] = BigInteger.ZERO;
	dp[2][1] = BigInteger.ONE;
	dp[3][0] = BigInteger.ONE;
	dp[3][1] = BigInteger.ONE;
	dp[4][0] = dp[3][0].add(dp[3][1]);
	dp[4][1] = BigInteger.valueOf(2);
	dp[5][0] = dp[4][0].add(dp[4][1]);
	dp[5][1] = BigInteger.valueOf(5);
	dp[6][0] = dp[5][0].add(dp[5][1]);
	dp[6][1] = BigInteger.valueOf(7);
	//dp[6] = BigInteger.valueOf(16);
	for(i = 7;i<=2000;i++)
	{
		dp[i][0] = dp[i-1][0].add(dp[i-1][1]);
		if(i-2==6)
		dp[i][1] = dp[i][1].add(dp[i-2][1].subtract(BigInteger.ONE));
		else
		dp[i][1] = dp[i][1].add(dp[i-2][1]);
	    if(i-3==6)
		dp[i][1] = dp[i][1].add(dp[i-3][1].subtract(BigInteger.ONE));
		else
		dp[i][1] = dp[i][1].add(dp[i-3][1]);
		if(i-4==6)
		dp[i][1] = dp[i][1].add(dp[i-4][1].subtract(BigInteger.ONE));
		else
		dp[i][1] = dp[i][1].add(dp[i-4][1]);
		
		if(i-5==6)
		dp[i][1] = dp[i][1].add(dp[i-5][1].subtract(BigInteger.ONE).multiply(BigInteger.valueOf(3)));
		else
		dp[i][1] = dp[i][1].add(dp[i-5][1].multiply(BigInteger.valueOf(3)));
		
		if(i-6==6)
		dp[i][1] = dp[i][1].add(dp[i-6][1].subtract(BigInteger.ONE).multiply(BigInteger.valueOf(2)));
		else
		dp[i][1] = dp[i][1].add(dp[i-6][1].multiply(BigInteger.valueOf(2)));
		
		if(i-6 == 6)
		{
			dp[i][1] = dp[i][1].add(dp[i-6][1].subtract(BigInteger.ONE));
		}
		else
		dp[i][1] = dp[i][1].add(dp[i-6][1]);
		if(i-7==6)
		dp[i][1] = dp[i][1].add(dp[i-7][1].subtract(BigInteger.ONE));
		else
		dp[i][1] = dp[i][1].add(dp[i-7][1]);
		
	}
	

	
   
	
			while(scanner.hasNextInt())
			{ 
			    
				i = scanner.nextInt();
				System.out.println(dp[i][0].add(dp[i][1]));
				
				
		    }
    	}
}

