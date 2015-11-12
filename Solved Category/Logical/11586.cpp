#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>

using  namespace std;

char in[200];
int cnt;
int FF;
int MM;
int MF;
int main(void)
{
    int t;
    char *p;
    cin >> t;
    getchar();
    while(t--)
    {
       gets(in);
       cnt = 0;
       FF = MM = MF = 0;
       p = strtok(in,"      ");
       while(p != NULL)
       {
               cnt++;
               if(strcmp(p,"FF") == 0)
               FF++;
               else if(strcmp(p,"MF") == 0 || strcmp(p,"FM") == 0)
               MF++;
               else
               MM++;
               p = strtok(NULL,"        ");
       }
       
       
       if(cnt == 1)
       {
              cout << "NO LOOP\n";
              continue;
       }
       if(FF == MM)
       {
           cout << "LOOP\n";
              continue;  
       }
       else
       cout << "NO LOOP\n";
              
    }
    return 0;
}
