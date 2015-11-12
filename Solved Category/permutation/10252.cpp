#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
    int count1[26],count2[26];
    char first[1001],second[1001],c;
    int i,j,k,l,a,b;
    
    while(gets(first))
    {
          gets(second);
          
          memset(count1,0,sizeof(count1));
          memset(count2,0,sizeof(count2));
          
          i = strlen(first);
          j = strlen(second);
          
          for( a = 0; a < i; a++)
          {
               count1[ first[a] - 'a']++;
          }
          
          for( a = 0; a < j; a++)
          {
               count2[ second[a] - 'a']++;
          }
          
         
          
          for(a = 0 ; a < 26; a++)
          {
                if( count1[a] <= count2[a] )
                {
                    b = count1[a];
                }
                else
                {
                    b = count2[a];
                }
                
                for( k = 1; k <= b; k++)
                {
                     cout << char(a+97);
                } 
          }
          
          cout << endl;
           
    }
     
    return 0;
}
