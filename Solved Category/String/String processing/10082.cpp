#include<iostream>
#include<cstring>

using namespace std;
int main(void)
{
    char in[1000],c,out[1000];
    int i,k,len,a,b;
    char letter[] = {'#','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','#','E','A','R','Y','C','Q','Z','T','#'};
    
    
    while( gets(in) )
    {
         len = strlen(in);
         
         for(i = 0; i < len; i++)
         {
               if( in[i] == ' ')
               out[i] = ' ';
               if( isalpha(in[i]) )
               out[i] = letter[ in[i] - 65 ];
               if(in[i] == '1')
               out[i] = '`';
               if( in[i] >= '2' && in[i] <= '9' )
               out[i] = char(in[i] - 1);
               if(in[i] == '0')
               out[i] = '9';
               if(in[i] == '-')
               out[i] = '0';
               if(in[i] == '=')
               out[i] = '-';
               if(in[i] == '.')
               out[i] = ',';
               if(in[i] == ',')
               out[i] = 'M';
               if(in[i] == '\'')
               out[i] = ';';
               if(in[i] == ';')
               out[i] = 'L';
               if(in[i] == '\\')
               out[i] = ']';
               if(in[i] == ']')
               out[i] = '[';
               if(in[i] == '[')
               out[i] = 'P';
               if(in[i] == '/')
               out[i] = '.';
               
               
         }
         
         out[len] = '\0';
         
         cout << out << endl;
                   
    }
      
    return 0;
}
