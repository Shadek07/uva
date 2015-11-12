import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.*;
import java.lang.Math;

class Main{
    public static void main(String[] args)
    	{
    		
    		BigDecimal a,b,c;
    		String s;
    		int N;
    		Scanner scn;
    		
    		scn = new Scanner(System.in);
    		
    		N = scn.nextInt();
    		
    		while(N-- > 0)
    		{
    			a = scn.nextBigDecimal();
    			b = scn.nextBigDecimal();
    			c = a.add(b);
    			s = String.valueOf(c);
    			//System.out.println(s);
    			int n,i,j;
    			n = s.length();
    			i = 0;
    			while(s.charAt(i) != '.')
    			{
    				System.out.print(s.charAt(i));
    				i++;
    			}
    			
    			System.out.print('.');
    			i++;
    			
    				j = n-1;
    				boolean ch = false;
    				while(s.charAt(j) == '0' && j > i)
    				{
    					j--;
    					
    				}
    				
    				if(i == j && s.charAt(i) == '0')
    					System.out.print(s.charAt(i));
    				else
    				{
    				
	    				while(i<=j)
	    				{
	    					System.out.print(s.charAt(i));
	    					ch = true;
	    					i++;
	    				}
	    				if(ch == false)
	    					System.out.print("0");
	    				
    				}
    				System.out.println();	
    			}
    		}
	
}

