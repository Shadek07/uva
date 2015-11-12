import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.lang.*;

class Main{
	//public static final BigInteger ZERO;
	public static int n,target;
	static BigInteger dp[][] = new BigInteger[25][145];
	static boolean ch[][] = new boolean[25][145];
	
	static BigInteger calc(int ind, int sum)
	{
		if(ind == n)
		{
			if(sum >= target)
				return BigInteger.ONE;
			else
				return BigInteger.ZERO;
		}
		if(ch[ind][sum] == true)
			return dp[ind][sum];
		int i;
		BigInteger ans = BigInteger.ZERO;
		for(i = 1;i<=6;i++)
			ans = ans.add(calc(ind+1,sum+i));
		
		ch[ind][sum] = true;
		dp[ind][sum] = ans;
		return ans;
	}
	
    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger one,two,res,gcd;
		
		
		Scanner myScanner = new Scanner(System.in);
		
	     int i,j;
	     
     
		
		while(true)
		{
		    n = myScanner.nextInt();
		    target = myScanner.nextInt();
		    if(n == 0 && target == 0)
		    	break;
		    if(target > n*6)
		    {
		    	System.out.println(0);
		    	continue;
		    }
		    
		    if(target <= n)
		    {
		    	System.out.println(1);
		    	continue;
		    }
			    
		    for(i=0;i<=n;i++)
		    {
		    	for(j=0;j<=n*6;j++)
		    		ch[i][j] = false;
		    		
		    }
		    
		    one = calc(0,0);
		    two = BigInteger.ONE;
		    for(i = 1;i<=n;i++)
		    	two = two.multiply(BigInteger.valueOf(6));
		    
		    gcd = one.gcd(two);
		    one = one.divide(gcd);
		    two = two.divide(gcd);
		    System.out.println(one+"/"+two);
		    
		
        }
    }
}
