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
	BigInteger t[] = new BigInteger [300];
	
	int i,j,k;
	
	t[0] = new BigInteger("1");
	t[1] = new BigInteger("1");
	
	
	for(i = 2; i <= 250; i++)
	{
		mini = t[i-1].add(t[i-2]);
		mini = mini.add(t[i-2]);
		t[i] = mini;		
	}
	
	
	
	while(scanner.hasNextInt() )
		{
			i = scanner.nextInt();    
		    System.out.println(t[i]);	
		    
	  }
    }
}

