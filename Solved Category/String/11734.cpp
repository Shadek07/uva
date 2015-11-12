#include<iostream>
#include<cctype>

using namespace std;

int main(void)
{
    char in[100],out[100];
    
    int t,i,k,ca = 1;
    
    char in1[21];

	bool team_space;
    
    
    
    cin >> t;
    
    getchar();
    
    while(t--)
    {
          gets(in);
          gets(out);
          k = 0;
		  team_space = false;
          for( i = 0; i < strlen(in);i++)
          {
			  if( in[i] == ' ')
			  {
				  team_space = true;
			  }
              else
                 in1[k++] = in[i];
               
          }
          
          in1[k] = '\0';
          k = 0;
          
          
        
          
          cout << "Case " << ca++ << ": ";
          
          if( (strcmp(in1,out)) == 0)
          {
              if(team_space) cout << "Output Format Error\n";
              else cout << "Yes\n";
          }
          else cout << "Wrong Answer\n";
          
          
          
    }
    
    return 0;
    
}
