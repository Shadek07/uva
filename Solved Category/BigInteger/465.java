import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;
 
class Main 
{ 
  
  public static void main(String args[]) throws Exception
  {
  	
  	   Scanner scn = new Scanner(System.in);
  	   String input;
  	   String words[] = new String[4];
  	   BigInteger a,b,res,mx;
  	   mx = BigInteger.valueOf(2147483647);
  	   while (scn.hasNext())
  	   {
  	   	  input = scn.nextLine();
  	   	  words = input.split(" ");
  	   	  a = new BigInteger(words[0]);
  	   	  b = new BigInteger(words[2]);
  	   	  if(words[1].compareTo("+")==0)
  	   	  {
  	   	  	res = a.add(b);
  	   	  }
  	   	  else
  	   	  	res = a.multiply(b);
  	   	  	
  	   	  System.out.println(input);
  	   	  if(a.compareTo(mx)>= 1)
  	   	  {
  	   	  	System.out.println("first number too big");
  	   	  }
  	   	  if(b.compareTo(mx)>=1)
  	   	  {
  	   	  	
  	   	  	System.out.println("second number too big");
  	   	  }
  	   	  if(res.compareTo(mx)>=1)
  	   	  {
  	   	  	System.out.println("result too big");	   	  	
  	   	  }
  	   	  
  	   }
  	 	
	   
  }
}