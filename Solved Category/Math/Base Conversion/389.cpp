

#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) a>a?a:b
#define min(a,b) a>b?b:a

int  a,b;  
char  sa[10000]; 
char  sb[10000]; 

void  rev(char  s[])  
{ 
     int  l=strlen(s); 
     for(int  i=0;   i<l-1-i;  i++)   swap(s[i],s[l-1-i]); 
} 

void  multi(char  s[],int k) 
{ 
     int  i,  c=0,  d; 
     for(i=0;s[i];i++) 
     { 
          d=(s[i]-'0')*k+c; 
          c=d/b;  d%=b; 
          s[i]='0'+d; 
     } 
     while(c) 
     { 
          s[i]='0'+(c%b); 
		  i++; 
          c/=b; 
     } 
     s[i]='\0'; 
} 

void  add1(char  s[],int  k)
{ 
     int  i,  c=k,  d; 
     for(i=0;s[i];i++) 
     { 
          d=(s[i]-'0')+c; 
          c=d/b;  d%=b; 
		  s[i]='0'+d; 
       } 
       while(c) 
       { 
             s[i]='0'+(c%b);  i++; 
             c/=b; 
       } 
       s[i]='\0'; 
} 

void    trans(char  s[]) 
{ 
       int    i; 
       for(i=0;s[i];i++) 
       { 
              char&  c=s[i]; 
              if(c>='A'  && c<'Z')  c=  '0'+10+(c-'A'); 
              if(c>='a'  &&c<='z')  c='0'+36+(c-'a'); 
       } 
} 

void    itrans(char  s[]) 
{ 
       int    i; 
       for(i=0;s[i];i++) 
       { 
              char&  c=s[i];  int           d=c-'0'; 
              if(d>=10  &&  d<=35)  c='A'+(d-10); 
              if(d>=36)  c='a'+(d-36); 
       } 
} 

int    main()  
{ 
	   int   q; 
       int   i,j,len; 
       while(cin >> sa >> a >> b) 
       { 
              sb[0]='0';  sb[1]='\0'; 
              //cout<<a<<"  "<<sa<<endl; 
              trans(sa);
			  //cout << sa << endl;
              for(i=0;sa[i];i++) 
              { 
                    multi(sb,a); 
                    add1(sb,sa[i]-'0'); 
              } 
              rev(sb); 
              itrans(sb); 
			  len = strlen(sb);
			  if(len > 7)
			  {
				  cout << "  ERROR\n";
				  continue;
			  }
			  for(i = 0;i<7-len;i++)
				  cout << " ";
              cout<<sb<<endl;  
       } 
       return  0; 
} 

           