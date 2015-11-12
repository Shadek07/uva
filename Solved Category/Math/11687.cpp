#include<iostream>

using namespace std;

int main(void)
{
    
    int count = 1;
    char c,d;
    int i,j;
    int check = 1,t = 0;
    int dit;
    
    while(check == 1)
    {
               d = getchar();
               dit = int(d) - 48;
               //cout << dit;
               if( d == '\n')
               {
                   
                   count = 0;
                   t = 1;
               }
               if( d == 'E')
               {  
                  t = 1;
                  d = getchar();
                  d = getchar(); 
                  break;
               }
               if( t != 1)
               {
                    
                
                    while( ( c = getchar()) != '\n')
                    {
                          count++; 
                           
                    }
                }
                if( count >= 10 )
                cout << "4\n";
                else if( count > 1)
                cout << "3\n";
                
                else if ( count == 1 && dit == 1)
                cout << "1\n";
                else
                cout << "2\n";
                
                
                
                
                
                
         count = 1;
         t = 0;       
    }
    
    
    
    
    
    return 0;   
    
} 
