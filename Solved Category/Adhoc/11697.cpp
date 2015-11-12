#include<iostream>

using namespace std;

int main(void)
{
    int t;
    
    char phr[1001],txt[1001],ch,ch1,ch2,tx[1001];
    
    char res[6][6];

    int dup[26];
    
    int i,j = 0,k = 0,m = 0;
    
    int inf[26][2];
    
    int count = 0;
    
    cin >> t;
    
    getchar();
    
    while(t--)
    {
         gets(phr);
         gets(tx);
         
         
         for( i = 0; i < strlen(tx); i++)
         {
              if( tx[i] != ' ' )
              {
                  txt[m++] = tx[i];
              }
              
         }
         txt[m] = '\0';
         
         for( i = 0 ; i < 26 ; i++)
         {
              dup[i] = 0;
         }
         
         //making first table
         
         for( i = 0 ; i < strlen(phr); i++)
         {
              ch  = phr[i]; 
              
              if( (dup[ch - 'a'] != 1) && ch != 'q' && ch != ' ')
              {
                  inf[ch - 'a'][0] = j;
                  inf[ch - 'a'][1] = k;
                  res[j][k] = ch;
                  count++;
                  dup[ch-'a'] = 1;
                  
                  k++;
                  if( k % 5 == 0)
                  {
                      k = 0;
                      j++;
                  }
              }
              
              
         }
         if( count < 26)
         {
             
             for( i = 0 ; i < 26;i++)
             {
                  if( dup[i] == 0 && i != 16 )
                  {
                      
                      inf[i][0] = j;
                      inf[i][1] = k;
                      res[j][k] = 'a' + i ;
                      k++;
                        
                        if( k % 5 == 0)
                        {
                          k = 0;
                          j++;
                        }
                      
                      
                  }
                  
             }
             
             
             
         }
         
         
         j = 0;
         
         for( j = 0 ; j < strlen(txt); j+= 2)
         {
              
              ch1 = txt[j];
              if( (j +1) < strlen(txt) )
              
              ch2 = txt[j+1];
              else
              ch2 = 'x';
              //check whether two char is same
              if( ch1 == ch2)
              {
                  ch2 = 'x';
                  j--;
              }
              //check whether row is same
              if( inf[ch1 - 'a'][0] == inf[ch2-'a'][0] )
              {
                  cout << char( res[ inf[ch1 - 'a'][0] ][ (inf[ch1 - 'a'][1] + 1)% 5 ] - 32);
                  cout << char( res[ inf[ch2 - 'a'][0] ][ (inf[ch2 - 'a'][1] + 1)% 5 ] - 32);
                  
              }
              //check whether column is same
              else if( inf[ch1 - 'a'][1] == inf[ch2-'a'][1] )
              {
                  cout <<char( res[ (inf[ch1 - 'a'][0] + 1) %5 ][ inf[ch1 - 'a'][1]  ] - 32);
                  cout <<char( res[ (inf[ch2 - 'a'][0] + 1) %5][ inf[ch2 - 'a'][1]  ] - 32);
                  
                  
              }
              else
              {
                  cout << char( res[ inf[ch1 - 'a'][0] ][ inf[ch2 - 'a'][1] ] - 32);
                  cout << char(res[ inf[ch2 - 'a'][0] ][ inf[ch1 - 'a'][1] ] - 32);
                  
                  
                  
              }
              
              
              
              
                  
              
              
         }
         
         
         
         cout << "\n";
              
         j = k = m = count = 0;
         
    }   
    
   
    
    
    
    
    return 0;
}
