import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;
 
class Main 
{ 
  private static  String pattern = "[-+]?\\d+(.\\d+)?([Ee]?[-+]?\\d+)?";
  //private static final String STATEMENT = ;
  
 //ACTION + "( , " + ACTION + ")*";
  public static void main(String args[]) throws Exception
  	 {
  	 	
	    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
	    String riddle;
	    String constant;
	    int i,j,k,len;
	    String last= "*";
		boolean dot,Ex;
		
			
	    while ((riddle = sc.readLine()) != null) 
	    {
	      if(riddle.compareTo(last) == 0)
	      	break;	
	      
	      len = riddle.length();
	      if(len == 0)
	      {
	      	System.out.println(" " + "is illegal.");
	      	continue;
	      }
	      
	      dot = Ex = false;
	      for(i = 0;i<len;i++)
	      {
	      	if(riddle.charAt(i) == '.')
	      		dot = true;
	      	if(riddle.charAt(i) == 'E'|| riddle.charAt(i) == 'e')
	      		Ex = true;
	      }
	      
	      i = 0;
	      while(riddle.charAt(i) == ' ' || riddle.charAt(i) == '\t')
	      	i++;
	      j = len-1;
	      while(riddle.charAt(j) == ' ' || riddle.charAt(j) == '\t')
	      	j--;
	      constant = riddle.substring(i,j+1);
	      System.out.print(constant+ " ");
	      
	      if(constant.matches(pattern) && (dot==true || Ex==true))
	      	System.out.println("is legal.");
	      else
	      	System.out.println("is illegal.");	      	
	      
	      //System.out.println(riddle.replaceAll(" +", " ").trim().matches(STATEMENT) ? "YES I WILL" : "NO I WON'T");
	    }
	    
  }
}