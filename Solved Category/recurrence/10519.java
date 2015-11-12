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
	

	
   
	
			while(scanner.hasNextBigInteger())
			{ 
			    mini = scanner.nextBigInteger();
			    if(mini.compareTo(BigInteger.ONE)== 0)
			    {
			 
			    	System.out.println(2);
			    	continue;
			    }
			    if(mini.compareTo(BigInteger.ZERO)== 0)
			    {
			 
			    	System.out.println(1);
			    	continue;
			    }
			    
			    maxi = mini.multiply(mini);
			    maxi = maxi.subtract(mini);
			    maxi = maxi.add(BigInteger.valueOf(2));
				System.out.println(maxi);
				
				
				
		    }
    	}
}

