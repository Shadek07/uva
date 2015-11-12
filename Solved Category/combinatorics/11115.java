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
	int N,D;

	
	while(true)
		{
			N = scanner.nextInt();
			D = scanner.nextInt();
			if(N == 0 && D == 0)
				break;
				
		   
		    ne =  BigInteger.valueOf(N).pow(D);

		    
		   // maxi = ne.subtract(t[i]);
		    
		    System.out.println(ne);	
		    
	  }
    }
}

