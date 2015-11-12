#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int main()
{
    
       char in[1000000],ch;
       int s[10000][2];
       int x;
       int t,i,k,m,n;
       int c = 1,p,q;
       int check = 1;
      
       
     while(fgets(in,sizeof(in),stdin) != NULL)
     {
          if(strcmp(in,"\n") == 0) break;
          
          cin >> t;
          
          for( i = 0; i < t;i++)
          {
               cin >> s[i][0] >> s[i][1];
          }
          getchar();
          cout << "Case " << c++ <<":\n";
          for( i = 0; i < t; i++)
          {
               p = s[i][0];
               q = s[i][1];
               if( p > q)
               {
                   int y = p;
                   p = q;
                   q = y;
               }
               ch = in[p];
               for( k = p+1; k <=q; k++)
               {
                    if( in[k] != ch)
                    check = 0;
               }
               if( check) cout << "Yes\n";
               else cout << "No\n";
               check  =1;
               
          }
          
          
          
     }
             
       
       fflush(stdin);
       getchar();
       
       
      return 0;
}
