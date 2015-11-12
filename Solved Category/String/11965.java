import java.*;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;
import java.io.*;
class Main
{
	public static void main(String[] args)
    	{
    		String s1,s2;
    		int t,n;
    		Scanner scn = new Scanner(System.in);
    		int c = 1;
    		//String a = "Some    text  with   spaces";
			//String b = a.replaceAll("\\s+", " ");
			//System.out.println(b);

    		t = scn.nextInt();
    		int ca = 1;
    		while(t > 0)
    		{
    			n = scn.nextInt();
    			s1 = scn.nextLine();
    			if(c == 1)
    				c = 0;
    				else
    					System.out.println();
    			System.out.print("Case ");
    			System.out.print(ca);
    			System.out.print(":\n");
    			ca++;
    		
    			while(n>0)
    			{
    				
    				
	    				s1 = scn.nextLine();
	    				s2 = s1.replaceAll("\\s+"," ");
	    				System.out.println(s2);
	    				
    				
    			     	n--;
    				
    			}
    			
    			t--;
    		}
    	}
}