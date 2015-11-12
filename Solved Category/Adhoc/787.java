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
	BigInteger mini,maxi,ne,num,temp;
	BigInteger t[] = new BigInteger [1005];

	int i,j,k;
	int N,A,s;
	

	
	
	

//while(System.in.read() != -1) 
	
	while(scanner.hasNextBigInteger() )
	{ 
		num = scanner.nextBigInteger();
		
		t[0] = num;
		
		num = scanner.nextBigInteger();
		i = 1;
		while(num.compareTo(BigInteger.valueOf(-999999)) != 0)
		{
				t[i++] = num;	
				num = scanner.nextBigInteger();
			
		}
		
		//System.out.println(N);
		
		s = i;
		maxi = BigInteger.valueOf(-999999);
		
		for(i= 0; i <s;i++)
		{
			temp = t[i];
			if(temp.compareTo(maxi)> 0)
			{
				maxi = temp;
			}
			
			for(j = i+1; j < s;j++)
			{
				temp = temp.multiply(t[j]);
				if(temp.compareTo(maxi)> 0)
				{
					maxi = temp;
				}
				
			}
			
		}
		
		
		
		
		System.out.println(maxi);
		
		
		
    }
    	}
}

/*
 for( i = 4; i <= 32;i++)
	{
		ne =  BigInteger.valueOf(2).pow(i);
		maxi = ne.subtract(t[i]);
		s[i] = maxi;
		
	}
	
	while(true)
		{
			i = scanner.nextInt();
			if(i == 0)
				break;
				
		   
		   // ne =  BigInteger.valueOf(2).pow(i);

		    
		   // maxi = ne.subtract(t[i]);
		    
		    System.out.println(s[i]);	
		    
	  }

 */

