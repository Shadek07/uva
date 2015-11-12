#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;
int n;
char in[10005];
string s1,s2;
char out[15];

void recur(string s)
{
     int len;
     len = s.size();
     char c;
     c = s[0];
     if(len == 1 && c == 'A')
     {
            //strcpy(out,"FULLY-GROWN\n");
            return;
     }
     else if(len == 1 && c == 'B')
     {
            strcpy(out,"MUTANT\n");
            return;
     }
     else if(s[len-2] == 'A' && s[len-1] == 'B')
     {
          s1 = s.substr(0,len-2);
          //strcpy(out,"FULLY-GROWN\n");
          recur(s1);
     }
     else if(s[0] == 'B' && s[len-1] == 'A')
     {
         s1 = s.substr(1,len-2);
         //strcpy(out,"MUTAGENIC\n");
         recur(s1); 
     }
     else
     {
          strcpy(out,"MUTANT\n");
            return;         
     }
}
int main(void)
{
    int i,j,len;
    string s;
    cin >> n;
    getchar();
    while(n--)
    {
       gets(in);
       len = strlen(in);
       if(len == 1 && in[0] == 'A')
       {
              cout << "SIMPLE\n";
       }
       else if(len == 1 && in[0] == 'B')
       {
              cout << "MUTANT\n";
       }
       else
       {
           s = in;
           len = s.size();
           if(s[0] == 'B' && s[len-1] ==  'A')
           strcpy(out,"MUTAGENIC\n");
           else if(s[len-2] == 'A' && s[len-1] == 'B')
           strcpy(out,"FULLY-GROWN\n");
           recur(s);
           cout << out;
       }      
    }
    return 0;
}
