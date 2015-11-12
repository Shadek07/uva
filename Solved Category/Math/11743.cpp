#include<iostream>
#include<cctype>

using namespace std;

int main(void)
{
    int t;
    int sum1= 0,sum2= 0;
    
    char in[21];
    char ne[17];
    
    
    char c;
    int i = -1, m ,n = -1;
    cin >> t;
    
    getchar();
    
    while(t--)
    {
         gets(in);
         
         while(in[++i] != '\0')
         {
            if( isdigit(in[i]))
            ne[++n] =  in[i];          
         } 
         
         ne[++n] = '\0';
         
         for( i = 0; i < strlen(ne) ;i++)
         {
              if(isdigit(ne[i]))
              {
                  if( i%2 == 0)
                  {
                      m = ne[i] - '0';
                      m *= 2;
                      if( m < 10)
                      sum1 += m;
                      else
                      {
                          sum1 += m%10;
                          m /= 10;
                          sum1 += m;
                      }
                  }
                  else
                  {
                      sum2 += ne[i] - '0';
                  }
              }
         }
         
         sum1 += sum2;
         if( sum1 %10 == 0)
         cout << "Valid\n";
         else
         cout << "Invalid\n";
         sum1 = 0;
         sum2 = 0; 
         i = -1;
         n = -1;   
              
    }
    
    
    return 0;
}
