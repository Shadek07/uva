#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
    
    char in[1000];
    int t,len;
    
    cin >> t;
    
    getchar();
    
    while(t--)
    {
              gets(in);
              
              len = strlen(in);
              
              if( len == 1 || len == 2)
              {
                  if( (strcmp(in,"1") == 0 )|| (strcmp(in,"4") == 0 ) || (strcmp(in,"78") == 0 ))
                  cout << "+\n";
                  continue;
              }
              
              else if( in[len-1] == '5' && in[len-2] == '3')
              {
                  cout << "-\n";
                  continue;
                  
              }
              
              else if( in[len-1] == '4' && in[0] == '9')
              {
                  cout << "*\n";
                  continue;
                  
              }
              else
              {
                  cout << "?\n";
                  continue;
                  
              }
    }
    
    return 0;
}
