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
	
	
	

	
   
	
			while(scanner.hasNextInt())
			{ 
			    
				i = scanner.nextInt();
				maxi = BigInteger.valueOf(i);
				if(maxi.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO)==0)
				{
					maxi = maxi.divide(BigInteger.valueOf(2));
					maxi = maxi.multiply(BigInteger.valueOf(i+1));
					maxi = maxi.multiply(maxi);
				}
				else
				{
					maxi = maxi.add(BigInteger.ONE);
					maxi = maxi.divide(BigInteger.valueOf(2));
					maxi = maxi.multiply(BigInteger.valueOf(i));
					maxi = maxi.multiply(maxi);
				}			
				System.out.println(maxi);
		    }
    	}
}

