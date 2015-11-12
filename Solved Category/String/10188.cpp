#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
    
    int input_line,output_line;
    
    char input[100][101];
    char output[100][101];
    char num1[1001],num2[1001];
    char c;
    int i,j,k,l,m,n;
    int check = 0;
    int run = 1;
    int ind,len;
    
    while(1)
    {
            cin >> input_line;
            getchar();
            
            if(!input_line) break;
            
            for(i = 0; i < input_line; i++)
            {
                  gets(input[i]);
            }
            
            cin >> output_line;
            getchar();
            
            for(i = 0; i < output_line; i++)
            {
                  gets(output[i]);
            }
            
            if( input_line == output_line )
            {
                check = 0;
                for( i = 0;i < input_line; i++)
                {
                     if( strcmp(input[i],output[i]) != 0)
                     check = 1;
                     
                }
                if( check == 0)
                {
                    cout << "Run #" << run++ <<": ";
                    cout << "Accepted\n";
                    check = 0;
                    continue;
                }
                                                                                
            }
            
            
                
                ind = 0;
                
                for( i = 0; i < input_line;i++)
                {
                      len = strlen(input[i]);
                     
                     for(k = 0; k < len; k++)
                     {
                           if( isdigit(input[i][k]))
                           {
                               num1[ind++] = input[i][k];
                           }
                     }
                     
                }
                
                num1[ind] = '\0';
                
                ind = 0;
                
                for( i = 0; i < output_line;i++)
                {
                      len = strlen(output[i]);
                     
                     for(k = 0; k < len; k++)
                     {
                           if( isdigit(output[i][k]))
                           {
                               num2[ind++] = output[i][k];
                           }
                     }
                     
                }
                
                num2[ind] = '\0';
                
                if( strcmp(num1,num2) == 0)
                {
                    cout << "Run #" << run++ <<": ";
                    cout << "Presentation Error\n";
                    
                }
                else
                {
                    cout << "Run #" << run++ <<": ";
                    cout << "Wrong Answer\n";
                    
                }
                
                
                
            
    }
    
     
    return 0;
}
