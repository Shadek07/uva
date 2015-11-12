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
	BigInteger mini,maxi,ne;
	
	BigInteger cal[][][] = new BigInteger [132][132][5];
	int i,j,k;
	int N,A;
	int n,s;
	

        cal[1][0][1] = BigInteger.ZERO;
		cal[1][0][0] = BigInteger.ONE;
		cal[1][1][1] = BigInteger.ONE;
		cal[1][1][0] = BigInteger.ZERO;
		cal[2][0][1] = BigInteger.ZERO;
		cal[2][0][0] = BigInteger.valueOf(2);
		cal[2][1][1] = BigInteger.ONE;
		cal[2][1][0] =  BigInteger.ZERO;
		
		for(i = 2; i <= 65; i++)
		{
			cal[i][i][1] = BigInteger.ONE;
			cal[i][i][0] = BigInteger.ZERO;
		}
		
		for(i = 3; i <= 65; i++)
		{
			for(j = i-1; j >= 0; j--)
			{
				if(j >= 1)
				{
					if(i-1 >= 0 && j-1 >= 0)
					cal[i][j][1] = cal[i-1][j-1][0].add(cal[i-1][j-1][1]);
					if(i-1 >= 0)
					cal[i][j][0] = cal[i-1][j][0];
					if(j+1 <= 65 && i-1 >= 0)
					{
					
					   if(i-1 >= j+1)
						cal[i][j][0] = cal[i][j][0].add(cal[i-1][j+1][1]);
					}
				}
				else
				{
					cal[i][j][1] = BigInteger.ZERO;
					if(i-1 >= 0)
					cal[i][j][0] = cal[i-1][j][0];
					if(i-1 >= 0 && j+1 <= 65 && i-1 >= j+1)
						cal[i][j][0] = cal[i][j][0].add(cal[i-1][j+1][1]);

				}
				
				
			}
		}


//while(System.in.read() != -1) 
	
	while(true)
	{ 
		n = scanner.nextInt();
		s = scanner.nextInt();
		//System.out.println(N);
		if(n < 0 && s < 0)
			break;
		BigInteger a,b;
		
		if(s > n)
		{
			//cout << 0 << endl;
			System.out.println("0");
			continue;
		}
		
		/*for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= s+n; j++)
			{
				cal[i][j][0] = BigInteger.ZERO;
				cal[i][j][1] = BigInteger.ZERO;
			}
		}*/
		
		System.out.println(cal[n][s][0].add(cal[n][s][1]));
		
		
		
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

