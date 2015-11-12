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
	BigInteger mini,maxi,ne;
	BigInteger t[] = new BigInteger [50];
	BigInteger s[] = new BigInteger [50];
	int i,j,k;
	
	t[1] = new BigInteger("2");
	t[2] = new BigInteger("4");
	t[3] = new BigInteger("7");
	
	for(i = 4; i <= 32; i++)
	{
		mini = t[i-3].add(t[i-2]);
		mini = mini.add(t[i-1]);
		t[i] = mini;
		
	
		
	}
	
	s[1] = BigInteger.ZERO;
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
		    
	  }
    }
}

