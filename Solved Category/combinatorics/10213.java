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
	

	A = scanner.nextInt();
   
	
			while(A-->0)
			{ 
			    N = scanner.nextInt();
			    if(N == 1)
			    {
			 
			    	System.out.println(1);
			    	continue;
			    }
			    if(N == 2)
			    {
			 
			    	System.out.println(2);
			    	continue;
			    }
			    /*if(N == 3)
			    {
			 
			    	System.out.println(4);
			    	continue;
			    }*/
				maxi = BigInteger.valueOf(1);
				mini = BigInteger.valueOf(N);
				mini = mini.multiply(BigInteger.valueOf(N-1));
				mini = mini.divide(BigInteger.valueOf(2));
				maxi = maxi.add(mini);
				if(N>=4)
				{
					if(N==4)
						maxi = maxi.add(BigInteger.valueOf(1));
					else
					{
						mini = BigInteger.valueOf(N);
						mini = mini.multiply(BigInteger.valueOf(N-1));
						mini = mini.multiply(BigInteger.valueOf(N-2));
						mini = mini.multiply(BigInteger.valueOf(N-3));
						mini = mini.divide(BigInteger.valueOf(2));
						mini = mini.divide(BigInteger.valueOf(3));
						mini = mini.divide(BigInteger.valueOf(4));
						maxi = maxi.add(mini);
					}
				}
				System.out.println(maxi);
				
				
				
		    }
    	}
}

