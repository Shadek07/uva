import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.*;
import java.lang.Math;



//java.lang.Math.pow(n,2);


class Main{
    public static void main(String[] args)
    	{
	Scanner scanner= new Scanner(System.in);

	
	BigDecimal D,d,a,b;
	
	
	

//while(System.in.read() != -1) 
	
	while(scanner.hasNextBigDecimal() )
	{ 
		
		D = scanner.nextBigDecimal();
		if(D.compareTo(BigDecimal.valueOf(0)) == 0)
			break;
		
		d = D.remainder(BigDecimal.valueOf(9));
		
		if(d.compareTo(BigDecimal.valueOf(0)) == 0)
		{
			a = D.multiply(BigDecimal.valueOf(10));
			//a = a.divide(BigDecimal.valueOf(9));
			a = a.divideToIntegralValue(BigDecimal.valueOf(9));
			a = a.subtract(BigDecimal.valueOf(1));
			System.out.print(a + " ");
			a = a.add(BigDecimal.valueOf(1));
			System.out.println(a);
			
		}
		else
		{
			a = D.multiply(BigDecimal.valueOf(10));
			//a = a.divide(BigDecimal.valueOf(9));
			a = a.divideToIntegralValue(BigDecimal.valueOf(9));
			System.out.println(a);
			
		}
		
		
		
		
		
		
    }
    	}
}

