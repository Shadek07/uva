import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.*;
import java.lang.Math;
import java.math.BigInteger;



class Main
{
	
	static double dp[][] = new double[101][11];
	static boolean ch[][] = new boolean[101][11];
	static int k,n;
	public static double solve(int ind,int num)
	{
		if(ind == n-1)
			return 1;
		
		if(ch[ind][num] == true )
			return dp[ind][num];
		double ans = 0;
		ans += solve(ind+1,num);
		if(num+1 <= k)
			ans += solve(ind+1,num+1);
		if(num-1 >= 0)
			ans += solve(ind+1,num-1);
		
		ch[ind][num] = true;
		dp[ind][num] = ans;
		return dp[ind][num];
			
	}
    public static void main(String[] args)
    	{
    		
    		BigDecimal a,b,c;
    		String s;
    		int N;
    		Scanner scn;
    	    int i,j;
    	    double as;
    		scn = new Scanner(System.in);
    		while(scn.hasNextInt())
    		{
    			k = scn.nextInt();
    			n = scn.nextInt();
    			for(i = 0;i<=n;i++)
    			{
    				for(j = 0;j<=k;j++)
    					ch[i][j] = false;
    			}
    			
    			
    			
    			
    			as = 0;
    			for(i = 0;i<=k;i++)
    			{
    			
    				as += solve(0,i);
    				//System.out.println(solve(0,i));
    			}
    			
    			//c = new BigDecimal(as);
    			//c = c.multiply(new BigDecimal(100));
    			//for(i = 1;i<=n;i++)
    			//	c = c.divide(new BigDecimal(k+1));
    			
    			System.out.printf("%.5f\n",as*100.0/Math.pow(k+1,n));
    			
    			
    			
    		}
    		
    		
    	}	
}

