#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
    
    int t;
    
    char one[201],two[201],add[210],c;
    
    int len1,len2;
    
    int i,j,k,l;
    
    int sum,carry,rem,a;
    
    cin >> t;
    
    while(t--)
    {
              cin >> one;
              cin >> two;
              
              //cout << one << endl;
              //cout << two << endl;
              
              len1 = strlen(one);
              
              len2 = strlen(two);
              
              l = 0;
              
              a = i;

    			sum = 0;
    			carry = 0;
    			k = 0;
    
    			for( i = 0,j = 0; i < len1 || j < len2 ; i++,j++)
    			{
                        
                        if( i < len1)
                        
                        sum += one[i] - 48;
                        if( j < len2)
                        
                        sum += two[j] - 48;
    				
    			
                    
    				sum += carry;
                    rem = sum %10;
    
    				add[k] = char(rem+48);
    
    				sum /= 10;
    				
    				carry = sum;
    				sum = 0;
    				k++;
    			}
    
    			if( carry > 0)
    			{
    				add[k] = char(carry%10 + 48);
    				carry--;
    				k++;
    			}
    			
    			//reverse(add,add+k);
    			add[k] = '\0';
    			
    			//cout << add << endl;
    			
    			i = 0;
    			
    			while(add[i] == '0')
    			i++;
    			
    			for( a = i; a < k; a++)
    			cout << add[a];
    			cout << endl;
    }
    
    return 0;
}
               
