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
        BigInteger one,two,res,gcd;
        int total;
        
        BigInteger t[] = new BigInteger [1001];
		BigInteger s[] = new BigInteger [1001];
		
		int a,b;
		
		int bill = 1;
		
		
		Scanner myScanner = new Scanner(System.in);
		
		total = myScanner.nextInt();
		
		while(total-->0)
		{
		
		
		     one = myScanner.nextBigInteger();
		     char c = myScanner.findInLine(".").charAt(0);
		     c = myScanner.findInLine(".").charAt(0);
		     c = myScanner.findInLine(".").charAt(0);
		     two = myScanner.nextBigInteger();
		     
		     gcd = one.gcd(two);
		     
		     one = one.divide(gcd);
		     two = two.divide(gcd);
		     
	      
	        System.out.println(one + " / " + two);
	        
        }
    }
}
