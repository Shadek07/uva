import java.util.*;
import java.*;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Math;





class Main{
    public static void main(String[] args)
    	{
	Scanner scanner= new Scanner(System.in);
	BigInteger mini,maxi,ne;
	BigInteger fibo[] = new BigInteger [115];
	BigInteger s[] = new BigInteger [50];
	int i,j,k;
	int N;
	String fir,sec,tmp;
    BigInteger A,B;
	fibo[0] = BigInteger.valueOf(1);
	fibo[1] = BigInteger.valueOf(2);
	
	for(i = 2;i<=110;i++)
	{
		fibo[i] = fibo[i-1].add(fibo[i-2]);
	}
	
	boolean ch = true;

//while(System.in.read() != -1) 
	
	while(scanner.hasNext() )
	{ 
		fir = scanner.next();
		i = 0;

		sec = scanner.next();
		
		if(fir.compareTo("0")==0 && sec.compareTo("0")==0)
		{
			if(ch==true)
				ch = false;
			else
				System.out.println();
			System.out.println(0);
			continue;
		}

		
		i = fir.length();
		A = BigInteger.ZERO;
		j = 0;
		while(j<i)
		{
			if(fir.charAt(j)=='1')
			{
				k = i-j-1;
				A = A.add(fibo[k]);
			}
			j++;
		}
		//System.out.println(A);
		
		i = sec.length();
		B = BigInteger.ZERO;
		j = 0;
		while(j<i)
		{
			if(sec.charAt(j)=='1')
			{
				k = i-j-1;
				B = B.add(fibo[k]);
			}
			j++;
		}
		
		A = A.add(B);
		//System.out.println(A);
		i = 109;
		int low,high,mid;
		low = 0;
		high = 110;
		int i1 = -1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(fibo[mid].compareTo(A)>0)
			{
				high = mid-1;
			}
			else if(fibo[mid].compareTo(A)<0)
			{
				if(i1 == -1)
				{
					i1 = mid;
				}
				else if(mid > i1)
				{
					i1 = mid;
				}
				low = mid+1;
			}
		    else if(fibo[mid].compareTo(A)==0)
		    {
		    	i1 = mid;
		    	break;
		    }
		}
		
		
		tmp = "";
		tmp += '1';
		i = i1;
		maxi = A.subtract(fibo[i]);
		i--;
		N = i+1;
		k = 0;
		while(maxi.compareTo(BigInteger.ZERO)>0)
		{
			if(maxi.compareTo(fibo[i])>= 0)
			{
				tmp += '1';
				maxi = maxi.subtract(fibo[i]);
			}
			else
				tmp += '0';
			i--;
			k++;
			if(i<0)
				break;
		}
		
		while(k<N)
		{
			tmp += '0';
			k++;
		}
		if(ch==true)
			ch = false;
		else
			System.out.println();
		System.out.println(tmp);
		
		
    }
  }
}



