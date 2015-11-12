import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.lang.*;

class Main{
	//public static final BigInteger ZERO;
	
    public static void main(String[] args) {
        // TODO code application logic here
        int input;
        BigInteger fibo,sum,temp;
        
        BigInteger t[] = new BigInteger [1001];
		BigInteger s[] = new BigInteger [1001];
		
		int a,b;
		
		int bill = 1;
		
		
		Scanner myScanner = new Scanner(System.in);
		
		while(true)
		{
		
		
		     a = myScanner.nextInt();
		     
		     b = myScanner.nextInt();
		     if( a == 0 && b == 0)
		     		break;
	        sum = BigInteger.ZERO;
	        
	        while(a-->0)
	        {
	        	
	        	temp = myScanner.nextBigInteger();
	        	
	        	sum = sum.add(temp);
	   
	        
	        }
	        
	        fibo = sum.divide(BigInteger.valueOf(b));
	        System.out.println("Bill #" + bill++ + " costs " + sum + ": each friend should pay " + fibo+ "\n");
	        
        }
    }
}
