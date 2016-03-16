
import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		   Scanner scn = new Scanner(System.in);
	  	   String input;
	  	   String words[] = new String[4];
	  	   BigInteger a,b,res;
	  	   while (scn.hasNext())
	  	   {
	  	   	  input = scn.nextLine();
	  	   	  words = input.split(" ");
	  	   	  
	  	   	  if(words[0].length() == 1){
	  	   		  if(words[0].charAt(0) == '0'){
	  	   			System.out.println("Not an Automorphic number.");
	  	   			continue;
	  	   		  }
	  	   	  }
	  	   	  a = new BigInteger(words[0]);
	  	   	  res = a.multiply(a);
	  	   	  String ans = res.toString();
	  	   	  //ans = new StringBuilder(ans).reverse().toString();
	  	   	  String num = words[0];
	  	   	  if(ans.indexOf(num) == ans.length()-num.length()){
	  	   		  System.out.print("Automorphic number of ");
	  	   		  System.out.println(num.length() + "-digit.");
	  	   	  }else{
	  	   		System.out.println("Not an Automorphic number.");
	  	   	  }
	  	   }
	  	   scn.close();

	}

}
