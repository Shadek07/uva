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
    
	BigDecimal a,b,ans;
	int n,i,j,len;
   
	
	while(scanner.hasNextBigDecimal())
		{
			a = scanner.nextBigDecimal();
			n = scanner.nextInt();
			
			ans = a.pow(n);
			
			String s = String.valueOf(ans);
			len = s.length();
			boolean ch = false;
			j = len-1;
			int save=0;
			while(j>= 0)
			{
				if(s.charAt(j) == 'E')
				{
					ch = true;
					save = j;
					break;
				}
				j--;
			}
		    
		    if(ch)
		    {
		    	int num = 0;
		    	
		    	j += 2;
		    	while(j<len)
		    	{
		    		num = num*10 + (s.charAt(j)-48);
		    		j++;
		    	}
		    	j = 0;
		    	while(true)
		    	{
		    		if(s.charAt(j) == '.')
		    		{
		    			break;
		    		}
		    		j++;
		    	}
		    	System.out.print('.');
		    	for(i = 0; i < num-j;i++)
		    	{
		    		System.out.print('0');
		    	}
		    	for(i = 0;i < save;i++)
		    	{
		    		if(s.charAt(i) != '.')
		    			System.out.print(s.charAt(i));
		    	}
		    	System.out.println();
		    }
		    else
		    {
		    	j = len-1;
		    	while(s.charAt(j) == '0')
		    	{
		    		j--;
		    	}
		    	for(i = 0;i <=j;i++)
		    	{
		    		
		    			System.out.print(s.charAt(i));
		    	}
		    	System.out.println();
		    }	
		    
	  }
    }
}

