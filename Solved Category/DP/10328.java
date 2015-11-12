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
	BigInteger t[][] = new BigInteger [105][105];
	int i,j,k;
	int N,A,n;
	int s;
	boolean pr = false;

    for(i = 0;i<101;i++)
    {
    	for(j = 0;j<101;j++)
    	{
    		t[i][j] = BigInteger.ZERO;
    	}
    }
	
	t[1][1] = new BigInteger("1");
	t[2][1] = new BigInteger("3");
	t[2][2] = new BigInteger("1");

	
	for(i = 3; i <= 100; i++)
	{
		

		for(k=1;k<i;k++)
		{
			maxi = t[i-1][k];
			maxi = maxi.multiply(BigInteger.valueOf(2));
			mini = BigInteger.valueOf(2);
			mini = mini.pow(i-k-1);
			mini = mini.subtract(t[i-k-1][k]);
			maxi = maxi.add(mini);
			t[i][k] = maxi;
			
		}
		t[i][i] = BigInteger.ONE;
		
			
		
	}
	

	
			while(scanner.hasNextInt())
			{ 
			    
				n = scanner.nextInt();
				k = scanner.nextInt();
				//System.out.println(N);


				System.out.println(t[n][k]);
				
				
				
		    }
    	}
}
