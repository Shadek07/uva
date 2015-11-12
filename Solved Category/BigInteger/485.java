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
	BigInteger mini,maxi,ne,comp;
	BigInteger t[] = new BigInteger [10000];
	BigInteger next[] = new BigInteger [10000];

	int i,j,k;
	
	System.out.println(1);
	System.out.println("1 1");
	System.out.println("1 2 1");
	
	comp = BigInteger.valueOf(1);
	for(i = 1;i<=60;i++)
		comp = comp.multiply(BigInteger.valueOf(10));
	t[0] = BigInteger.valueOf(1);
	t[1] = BigInteger.valueOf(2);
	t[2] = BigInteger.valueOf(1);
	int last = 2;
	int ch = 0;
	while(ch == 0)
	{
		System.out.print(1);
		next[0] = BigInteger.valueOf(1);
		for(i = 1;i<=last;i++)
		{
			next[i] = t[i].add(t[i-1]);
			System.out.print(" ");
			System.out.print(next[i]);
			if(next[i].compareTo(comp) >= 0)
			{
			
				ch = 1;
				//System.out.println();
				//break;
			}
				
		}
		
		System.out.print(" ");
		System.out.println(1);
		if(ch == 1)
			break;
	
		last++;
		next[last] = BigInteger.valueOf(1);
		for(j = 0;j<=last;j++)
			t[j] = next[j];
		
	}
	
	
/*	s[1] = BigInteger.ZERO;
	s[2] = BigInteger.ZERO;
	s[3] = BigInteger.ONE;
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
		    
	  }*/
    }
}

