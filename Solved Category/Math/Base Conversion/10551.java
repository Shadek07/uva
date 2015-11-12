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
     while  (true)  { 
       int  b =  sc.nextInt(); 
       	if(b == 0)
       		break;
       String  p_str   = sc.next(); 
       	int i,j;
       	
       BigInteger   p  = new  BigInteger(p_str,b);  // special   constructor! 
       String  m_str   = sc.next(); 
       BigInteger m = new BigInteger(m_str,b);
       System.out.println(p.mod(m).toString(b) );         //  can  output  in  any radix/base 
} }  }