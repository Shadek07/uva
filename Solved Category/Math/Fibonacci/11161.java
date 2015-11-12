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
	BigInteger fibo[] = new BigInteger [1501];
	BigInteger pre[] = new BigInteger [1501]; //prefix_sum
	int i,j,k;
	int n;
	fibo[1] = BigInteger.ONE;
	fibo[2] = BigInteger.ONE;
	pre[1] = BigInteger.ONE;
	pre[2] = BigInteger.valueOf(2);
	for(i = 3;i<=1500;i++)
	{
		fibo[i] = fibo[i-1].add(fibo[i-2]);
		pre[i] = pre[i-1].add(fibo[i]);
	}
	
	//System.out.println(pre[4]);
	int ca=1;
	
	while(true)
		{
			n = scanner.nextInt();
			if(n == 0)
				break;
			System.out.println("Set " + ca + ":");
			ca++;
			if(n==1)
			{
				System.out.println(0);
				continue;
			}
			if(n==2)
			{
				System.out.println(1);
				continue;
			}

		    BigInteger a,b,c;
		    a = pre[n].subtract(BigInteger.ONE);
		    b = pre[n-1];
		    
		    //System.out.println(b + " " + a);
		    c = a.subtract(b);
		    c = c.add(BigInteger.ONE);
		   
		    if(c.remainder(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO)==0)
		    {
		    	a = c.divide(BigInteger.valueOf(2));
		    	a = a.subtract(BigInteger.ONE);
		    	b = b.add(a);
		    	System.out.println(b);
		    		
		    }
		    else
		    {
		    	c = c.add(BigInteger.ONE);
		    	a = c.divide(BigInteger.valueOf(2));
		    	a = a.subtract(BigInteger.ONE);
		    	b = b.add(a);
		    	System.out.println(b);
		    }
		    
		   // maxi = ne.subtract(t[i]);
		    
		    
		    
	  }
    }
}

