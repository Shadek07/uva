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
	BigInteger t[] = new BigInteger [305];
	BigInteger fact[] = new BigInteger [305];
	int i,j,k;
	
	t[1] = new BigInteger("1");
	t[2] = new BigInteger("4");
	t[3] = new BigInteger("30");
	
	fact[1] = new BigInteger("1");
	fact[2] = new BigInteger("2");
	fact[3] = new BigInteger("6");
	
	for(i = 4; i <= 300; i++)
	{
		mini = BigInteger.valueOf(i+2);
		
		for(j = i+3; j <= (2*i) ; j++)
		{
			
			mini = mini.multiply(BigInteger.valueOf(j));
		}
		
		t[i] = mini;
		
	
		
	}
	

	
	while(true)
		{
			i = scanner.nextInt();
			if(i == 0)
				break;
	
		    
		    System.out.println(t[i]);	
		    
	  }
    }
}

