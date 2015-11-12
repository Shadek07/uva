#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>

using namespace std;

char in[15];

string s1,s2,s3;
int length;

void recur(string s1,int d)
{
     int i,j;
     
     int sz = s1.size();
     string st,str,str1,st1;
     string add;
     //cout << s1 << endl;
     if(d == length)
     {
          cout << s1 << endl; 
          s1 = "";         
          return;    
     }
     
     else
     {
         add = "";
         add += in[d];
         str = "";
         str += in[d];
         recur(add+s1,d+1);
         st = s1;
         st1 = s1;
         s2 = "";
         for(i = 1; i <= sz-1;i++)
         {
                s2 = st1.substr(i,sz-i);
                st1.erase(i,sz-i);
                st1 += add;
                st1.append(s2);
                recur(st1,d+1);
                st1 = st;
                s2 = "";
          }
          
          st1 = s1;
          str = "";
          str += in[d];
          recur(st1+str,d+1);    
     }
     
}
int main(void)
{
    int i,j,len;
    int ch=0;
    
    while(gets(in))
    {
          len = strlen(in);
          length = len;
          if(ch == 0)
          ch = 1;
          else
          cout << endl;
          s1 = "";
          s1 += in[0];          
          recur(s1,1);                   
    }
    
    return 0;
}

