import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;



//java.lang.Math.pow(n,2);


class Main{
	
	static BigInteger  dp[][] = new BigInteger [302][152];
	static boolean  solved[][] = new boolean [302][152];
	static BigInteger calc(int n,int d)  //for n parantheses with atmost d depth
	{
		if(n<0 || d < 0)
			return BigInteger.ZERO;
		if(n== 0 && d>= 0)
			return BigInteger.ONE;
		
		if(solved[n][d])
			return dp[n][d];
		
		BigInteger ans = BigInteger.ZERO;
		int i,k;
		for(k = 2;k<=n;k+=2)
		{
			ans = ans.add(calc(k-2,d-1).multiply(calc(n-k,d)));
		}
		dp[n][d] = ans;
		solved[n][d] = true;
		return ans;
	}
    public static void main(String[] args)
    	{
	Scanner scanner= new Scanner(System.in);
	int n,d;
	
	int i,j;
	for(i = 0;i<=300;i++)
	{
		for(j = 0;j<=150;j++)
			solved[i][j] = false;
	}
	
	while(scanner.hasNextInt() )
	{ 
		n = scanner.nextInt();
		
		d = scanner.nextInt();
		
		BigInteger ans = calc(n,d);
		ans = ans.subtract(calc(n,d-1));
		System.out.println(ans);
		
		
    }
    	}
}



