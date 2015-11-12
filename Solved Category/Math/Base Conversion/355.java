import  java.io.*; 
import  java.util.*; 
import  java.math.*; 

//Solution from Competitive programming book

class  Main  {  /* UVa  10551  - Basic  Remains   */ 
  
  static int number(char c)
  {
  	if(c>= '0' && c<= '9')
  		return c- '0';
  	else
  		return c-'A'+10;
  }
  public   static  void  main(String[]   args)   
  { 
     Scanner  sc  = new  Scanner(System.in); 
     while  (sc.hasNextInt())  { 
       int  b =  sc.nextInt(); 
       int to = sc.nextInt();
       String  p_str   = sc.next(); 
       	int sz = p_str.length();
       	int i,j;
       	j = 0;
       	for(i = 0;i<sz;i++)
       	{
       		if(number(p_str.charAt(i)) >= b)
       		{
       			System.out.println(p_str+" is an illegal base " + b+" number");
       			j=1;
       			break;
       		}
       	}
       	if(j==1)
       		continue;
       BigInteger   p  = new  BigInteger(p_str,b);  // special   constructor! 
       //String  m_str   = sc.next(); 
       String  out  =  p.toString(to);  // 2nd  parameter   is the  radix/base 
       sz = out.length();
       char[] out1 = out.toCharArray();
       for(i = 0;i<sz;i++)
       {
       	  if(out1[i] >= 'a' && out1[i] <= 'f')
       	  	out1[i] = Character.toUpperCase(out1[i]);
       }
       out = new String(out1);
       System.out.println(p_str+" base "+b +" = " + out+" base "+to );         //  can  output  in  any radix/base 
} }  }