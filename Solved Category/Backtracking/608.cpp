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

using namespace std;

struct line
{
       char in[14];
       char in1[14];
       char type[10];
       
}li[3];

set<char> even;
int val[20];
int equa[20];
char c;

bool determine()
{
     int a,b,i,j,k,len;
     int d = true;
     for(i = 0; i < 3;i++)
     {
           len = strlen(li[i].in);
           a = b = 0;
           for(j = 0; j < len;j++)
           {
               a += val[li[i].in[j]-'A'];
           }
                          
           len = strlen(li[i].in1);
           for(j = 0; j < len;j++)
           {
               b += val[li[i].in1[j]-'A'];
           }
           
           if(strcmp(li[i].type,"up") == 0 && a != b+1)
           {
                d = false;
                return d;
           }
           if(strcmp(li[i].type,"down") == 0 && a +1 != b)
           {
                d = false;
                return d;
           }
           if(strcmp(li[i].type,"even") == 0 && a != b)
           {
                d = false;
                return d;
           }
           
     }
     
     return d;
}
int main(void)
{
    int t;
    int i,j,len,k;
    int light,heavy;
    cin >> t;
    getchar();
    bool b;
    while(t--)
    {
              i = 0;
              cin >> li[i].in >> li[i].in1 >> li[i].type;
              i++;
              cin >> li[i].in >> li[i].in1 >> li[i].type;
              i++;
              cin >> li[i].in >> li[i].in1 >> li[i].type;
              
              
              //memset(equa,-1,sizeof(equa));
              for(k = 0; k < 12;k++)
              equa[k] = -1;
              light=heavy=0;
              
              for(i = 0; i < 3;i++)
              {
                    if(strcmp(li[i].type,"even") == 0)
                    {
                          len = strlen(li[i].in);
                          for(j = 0; j < len;j++)
                          {
                                even.insert(li[i].in[j]);
                                equa[li[i].in[j]-'A'] = 1;
                          }
                          
                          len = strlen(li[i].in1);
                          for(j = 0; j < len;j++)
                          {
                                even.insert(li[i].in1[j]);
                                equa[li[i].in1[j]-'A'] = 1;
                          }
                                                 
                    }
              }
              
              b = false;
              for(i = 0; i < 3;i++)
              {
                    if(strcmp(li[i].type,"up") == 0)
                    {                          
                         len = strlen(li[i].in);
                         for(j = 0; j < len;j++)
                         {
                               if(equa[li[i].in[j]-'A'] == -1)
                               {
                                  //memset(val,1,sizeof(val));
                                  for(k = 0; k < 12;k++)
                                  val[k] = 1;
                                  val[li[i].in[j]-'A'] = 2; 
                                  c = li[i].in[j];
                                  b = determine();
                                  if(b == true)
                                  {
                                       i = 3;
                                       heavy = 1;
                                       goto nt;
                                  }  
                               }
                         }
                         len = strlen(li[i].in1);
                         for(j = 0; j < len;j++)
                         {
                               if(equa[li[i].in1[j]-'A'] == -1)
                               {
                                  //memset(val,1,sizeof(val));
                                  for(k = 0; k < 12;k++)
                                  val[k] = 1;
                                  val[li[i].in1[j]-'A'] = 1; 
                                  c = li[i].in1[j];
                                  b = determine();
                                  if(b == true)
                                  {
                                       i = 3;
                                       light = 1;
                                       goto nt;
                                  }  
                               }
                         }                      
                    }
                    else if(strcmp(li[i].type,"down") == 0)
                    {                          
                         len = strlen(li[i].in);
                         for(j = 0; j < len;j++)
                         {
                               if(equa[li[i].in[j]-'A'] == -1)
                               {
                                  //memset(val,1,sizeof(val));
                                  for(k = 0; k < 12;k++)
                                  val[k] = 1;
                                  val[li[i].in[j]-'A'] = 0; 
                                  c = li[i].in[j];
                                  b = determine();
                                  if(b == true)
                                  {
                                       i = 3;
                                       light = 1;
                                       goto nt;
                                  }  
                               }
                         }
                         
                         len = strlen(li[i].in1);
                         for(j = 0; j < len;j++)
                         {
                               if(equa[li[i].in1[j]-'A'] == -1)
                               {
                                  //memset(val,1,sizeof(val));
                                  for(k = 0; k < 12;k++)
                                  val[k] = 1;
                                  val[li[i].in1[j]-'A'] = 2; 
                                  c = li[i].in1[j];
                                  b = determine();
                                  if(b == true)
                                  {
                                       i = 3;
                                       heavy = 1;
                                       goto nt;
                                  }  
                               }
                         }                      
                    }
              }

nt:              
              cout << c << " is the counterfeit coin and it is ";
              if(heavy == 1)
              {
                       cout << "heavy.\n";
              }
              else
              {
                  cout << "light.\n";
              }
              
              even.clear();
              
              
    }
    return 0;
}
